#if __cplusplus < 202002L
#error "This is mapped to C++20, please update!"
#endif

#include <iostream>
#include <string>

#ifndef LIGBUS_HPP
#define LIGBUS_HPP

namespace Light {
	typedef enum : char {
		OP_NULL,
		OP_EXIT,
		OP_STR,
		OP_DEF,
		OP_PUSH,
		OP_EXEC,
		OP_POP,
		OP_CHECK,
		OP_JMP,
		OP_DECLARE
	} OP_CODE;

	extern void interpret(char* bytecode);
}

#endif
