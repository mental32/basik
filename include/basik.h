#ifndef _BASIK_H
#define _BASIK_H

#include <stdint.h>

Object *Basik_String(void);
Object *Basik_String_FromStr(char *src);


Object *Basik_Integer(void);
Object *Basik_Integer_FromSize(size_t value);

#endif

