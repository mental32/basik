#ifndef _BASIK_OBJECTS_BASEOBJECT_H
#define _BASIK_OBJECTS_BASEOBJECT_H

#include <stdint.h>

enum objectType {
    _OBJKIND_NULL = 0,
    _OBJKIND_STR
};

typedef struct {
    bool marked;
    size_t kind;
    void *data;
} Object;

#endif
