/*
 * Execute compiled code.
 *
 * Here is defined the "heart" of the interpreter.
 * The important function to note is `basik_exec`
 * which takes a pointer to a `State` struct and
 * begins executing the compiled bytecode.
 */


#include "objects/frameobject.h"
#include "opcodes.h"
#include "state.h"

/* Main entry point for an interpreter.
 *
 * This will consume a State struct and
 * run its code until a fatal exception
 * or a graceful shutdown occurs.
 */
void basik_exec(State *vm)
{
    if (vm == NULL)
    {
        return;
    }

    FrameObject *frame = vm->frame;
    bool head = true;

    do {
        if (!_basic_exec_frame(frame)) {
            if (head) {
                TRACEBACK(frame);
                EXIT(ERR);
            } else {
                FrameObject_SET_ERR(frame->parent, frame);
                vm->frame = frame->parent;
            }
        } else {
            vm->frame = frame->parent;
        }

    } while (vm->frame != NULL);

    return;
}


/* Execute a FrameObjects code.
 *
 * This is the function 
 * execute frames, aka running
 * procedures.
 */
static int _basik_exec_frame(FrameObject *frame)
{
    int op, arg, last_op = 0;

    Object *rvalue = NULL;     /* The return value */

    CodeObject *co = frame->code;

    Object *names = co->co_names;
    Object *consts = co->co_consts;

    Object **sp = frame->stack_top;    /* Next free slot in the stack. */
    Object **locals = frame->locals;   /* Frame locals */

/* Tuple indexing macros */
#define GETIEM(t, i) Tuple_GET_ITEM((Tuple *)(t), (i))

/* Preprocessor alias to the stack pointer name */
#define STACK_POINTER sp

/* Stack metadata */
#define STACK_LEVEL ((int)(STACK_POINTER - frame->vstack))
#define STACK_EMPTY (STACK_LEVEL == 0)

/* Stack value macros */
#define PEEK(n)    (STACK_POINTER[-(n)])
#define TOP(n)     (PEEK(1))
#define SECOND(n)  (PEEK(2))
#define THIRD(n)   (PEEK(3))
#define FOURTH()   (PEEK(4))

/* Stack manipulation macros */
#define PUSH(v)    (*STACK_POINTER++ = (v))
#define POP()      (*--STACK_POINTER)
#define GROW(n)    (STACK_POINTER += n)
#define SHRINK(n)  (STACK_POINTER -= n)

/* Local variable macros */

#define LOCAL(i) (locals[i])
#define SETLOCAL(i, v) \
{ \
    Object *tmp = LOCAL(i); \
    LOCAL(i) = v; \
    XDECREF(tmp); \
}

/* OpCode switch statement */

    for (;;) {

next_opcode:
        op = frame->code[frame->ins_ptr++];
        op_arg = frame->code[frame->ins_ptr++];

        switch(op) {
            case NOP: {
                goto next_opcode;
            }

            case LOAD_LOCAL: {
                Object *value = LOCAL(arg);
                if (value == NULL) {
                    goto error;
                } else {
                    INCREF(value);
                    PUSH(value);
                    goto next_opcode;
                }
            }

            case LOAD_CONST: {
                Object *value = GETITEM(consts, arg);
                INCREF(value);
                PUSH(VALUE);
                goto next_opcode;
            }

            case STORE: {
                Object *value = POP();
                SETLOCAL(arg, value);
                goto next_opcode;
            }
        }

error:
        return 0; /* TODO: Add Exceptions and a way to handle them */
    }
}
