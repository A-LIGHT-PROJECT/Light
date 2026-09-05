#ifndef _LIGHT26_
#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define HAVEWINDOWS 1
#else
#define HAVEWINDOWS 0
#endif

typedef enum : char {
	LIGHT_OP_EXIT,
	LIGHT_OP_DEF_THINGS,
	LIGHT_OP_CMP,
	LIGHT_OP_IFJMP,
	LIGHT_OP_JMP
} LIGHT_OP_SET;

typedef enum : char {
	LIGHT_IF_NULL,
	LIGHT_IF_WINDOWSOS
} LIGHT_IF;

typedef enum : unsigned {
	LIGHT_MODE_ROOT = 0,
	LIGHT_MODE_STRING,
	LIGHT_MODE_INIT_STRING,
	LIGHT_MODE_IF_SET,
	LIGHT_MODE_IF_JMP
} LIGHT_OP_MODE;

extern int LightProcessor(char* Bytecode, long PointTo);

#ifdef __cplusplus
}
#endif
#endif
