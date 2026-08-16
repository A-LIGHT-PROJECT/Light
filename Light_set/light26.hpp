#ifndef _LIGHT26_
#define _LIGHT26_ 1
#include <LightDef.hpp>

typedef enum : char {
	LIGHT_OP_EXIT,
	LIGHT_OP_DEF_THINGS
} LIGHT_OP_SET;

typedef enum : unsigned {
	LIGHT_MODE_ROOT = 0,
	LIGHT_MODE_STRING
} LIGHT_OP_MODE;

extern int LightProcessor(char* Bytecode, long PointTo);

#endif
