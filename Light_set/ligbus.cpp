#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <lightexe.h>
#include <ligbus.hpp>

namespace Light {
	void interpret(std::string bytecode) {
		// Initialization
		std::stack<char**> Stack;
		char** Declaration = nullptr;
		std::string tempString;
		char Argument1 = OP_NULL;
		char arguments;
		bool Exit_program = false;
		bool IsString = false;
		bool NeedNumberedArgument = true;
		char ArgByte1, ArgByte2;
		int DeclarationAmount = 0;
		int byteNum = 0;
		int byteJumps = 0;
	
		// Output
		for (char byte : bytecode) {
			if (Exit_program) 
			{
				break;
			}

			byteNum++;
			if (byteJumps) {
				byteJumps--;
				continue;
			}
			if (NeedNumberedArgument) {
				if (!ArgByte1) {
					ArgByte1 = byte;
				} else {
					ArgByte2 = byte;
					if (Argument1 = OP_JMP) {
						byteJump = (ArgByte1 << 8) | ArgByte2;
						ArgByte1 = 0;
						ArgByte2 = 0;
					} else if (Argument2 = OP_DECLARE) {
						if (Declaration != nullptr) {
							std::free(Declaration);
							Declaration = nullptr;
							DeclarationAmount = 0;
						}
						size_t allocCommands = ((ArgByte1 << 8) | ArgByte2) + 1;
						DeclarationAmount = ((ArgByte1 << 8) | ArgByte2);
						Declaration = (char**) std::malloc(allocCommands * sizeof(char*));
					}

				}
				continue;
			}
			if (IsString) {
				if (byte == OP_STR) {
					IsString = false;
					if (Argument1 == OP_DEF) {
						Declaration[DeclarationNumber] = tempString.c_str();
					}
					tempString.clear();
					Argument1 = OP_NULL;
					continue;
				}
				if (Argument1 == OP_NULL) {
					std::cerr << "[Light] ARG 1 IS OP_NULL; OP_NULL DOESN'T NEED ARGUMENTS; OP_EXIT IS INIT IMMEDIATE; AT LINE " << byteNum << "\n";
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
					if (!DeclarationNumber) {
						std::cerr << "[Light] MUST OP_DECLARE; OP_DEF AFTER IT; OP_EXIT IS INIT IMMEDIATE;\n";
						Exit_program = true;
						break;
					}
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
					char** Wrapper = Stack.top();
					spawnexee(Wrapper, DeclarationAmount);
					break;
				}
				case OP_POP:
					if (Stack.empty()) {
						break;
					}
					Stack.pop();
					break;
				case OP_DECLARE:
					Argument1 = OP_DECLARE;
					NeedNumberedArgument = true;
					break;
				case OP_JMP:
					Argument1 = OP_JMP;
					NeedNumberedArgument = true;
					break;
				case OP_CHECK:
					Argument1 = OP_CHECK;
					break;
				default:
					std::cerr << "[Light] INVALID BYTE DETECTED; OP_EXIT IS INIT IMMEDIATE;\n";
			}
		}

		// Overview
		if (Declaration != nullptr) {
			std::free(Declaration);
		}
	}
}
