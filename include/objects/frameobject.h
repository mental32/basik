#ifndef _BASIK_OBJECTS_FRAMEOBJECT_H
#define _BASIK_OBJECTS_FRAMEOBJECT_H

#include <stdint.h>

#include "./baseobject.h"

typedef struct {
	// Parent frame, NULL if root.
    FrameObject *parent;

    // Stack bookmark and pointer.
    size_t stack_offset;
    Object **stack;

    // Code offset for source.
    size_t code_offset;
} FrameObject;

#endif
