#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib>
#include <ligbus.hpp>

namespace Light {
	void interpret(std::string bytecode) {
		// Initialization
		std::stack<std::string> Stack;
		std::string Construction;
		char Argument1 = OP_NULL;
		char arguments;
		bool Exit_program = false;
		bool IsString = false;
		bool IfState = false;
		bool DoNothingTilEnd = false;
		char ConditionNeed = IF_NULL;
		int NeedArguments = 0;
		
		// Output
		for (char byte : bytecode) {	
			if (IsString) {
				if (byte == OP_STR) {
					IsString = false;
					Argument1 = OP_NULL;
					continue;
				}
				if (Argument1 == OP_NULL) {
					std::cerr << "ARG 1 IS OP_NULL; OP_NULL DOESN'T NEED ARGUMENTS; OP_EXIT IS INIT IMMEDIATE;\n";
					break;
				}

				switch (Argument1) {
					case OP_DEF:
						Construction += byte;
						break;
				}
				continue;
			}
			if (Exit_program) 
			{
				break;
			}
			switch (byte) {
				case OP_NULL:
					break;
				case OP_EXIT:
					Exit_program = true;
					break;
				case OP_STR:
					IsString = true;
					break;
				case OP_DEF:
					Argument1 = OP_DEF;
					break;
				case OP_PUSH:
					if (Construction.empty()) {
						break;
					}
					Stack.push(Construction);
					break;
				case OP_EXEC: {
					const char* Wrapper = Stack.top().c_str();
					std::system(Wrapper);
					break;
				}
				case OP_POP:
					if (Stack.empty()) {
						break;
					}
					Stack.pop();
					break;
			}
		}

		// Overview
	}
}
