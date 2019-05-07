/*
 * Source file for frameobjects
 *
 * Frame objects are created when a
 * function is called, functions act
 * as a kind of read only blueprint
 * of the code inside with some added
 * metadata.
 *
 * Frame objects are the living process
 * of an executing procedure, they
 * contain the current working stack,
 * what bytecode offset they are executing
 * at and what their state is (running, suspended, dead)
 *
 * You can think of them akin to processes
 * on an operating system.
 */


#include "objects/object.h"

