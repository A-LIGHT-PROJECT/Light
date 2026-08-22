#ifndef _LIGHT26_
#ifdef __cplusplus
extern "C" {
#endif

typedef enum : char {
	LIGHT_OP_EXIT,
	LIGHT_OP_DEF_THINGS
} LIGHT_OP_SET;

typedef enum : unsigned {
	LIGHT_MODE_ROOT = 0,
	LIGHT_MODE_STRING,
	LIGHT_MODE_INIT_STRING
} LIGHT_OP_MODE;

extern int LightProcessor(char* Bytecode, long PointTo);

#ifdef __cplusplus
}
#endif
#endif
