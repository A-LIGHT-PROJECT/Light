#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib>
#include <vector>
#include <lightexe.h>
#include <ligbus.hpp>

namespace Light {
	void interpret(std::string bytecode) {
		// Initialization
		std::stack<std::vector<char*>> Stack;
		std::string tempString;
		std::vector<char*> Construction;
		char Argument1 = OP_NULL;
		char arguments;
		bool Exit_program = false;
		bool IsString = false;
		bool DoNothingTilEnd = false;
		int NeedArguments = 0;
		
		// Output
		for (char byte : bytecode) {	
			if (IsString) {
				if (byte == OP_STR) {
					IsString = false;
					if (Argument1 == OP_DEF) {
						Construction.push_back((char*)tempString.c_str());
					}
					tempString.clear();
					Argument1 = OP_NULL;
					continue;
				}
				if (Argument1 == OP_NULL) {
					std::cerr << "ARG 1 IS OP_NULL; OP_NULL DOESN'T NEED ARGUMENTS; OP_EXIT IS INIT IMMEDIATE;\n";
					break;
				}

				tempString += byte;
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
					Construction.clear();
					break;
				case OP_EXEC: {
					if (Stack.empty()) {
						break;
					}
					char* const* Wrapper = Stack.top().data();
					spawnexee(Wrapper);
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
