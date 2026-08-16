#include <stdio.h>
#include <stdlib.h>
#include <light26.hpp>
#include <execlight26.h>
#include <stdint.h>
#include <stdbool.h>

int LightProcessor(char* Bytecode, long PointTo) {
	char PointingByte;
	uint32_t Pointer = PointTo;
	bool EXIT_PROGRAM = false;
	int LightMode = 0;
	size_t declarationSize = 2 * sizeof(char*);
	char** declaration = (char**) malloc(declarationSize);
	int declarationNum = 0;
	char tempString[255];
	int tempStringNum = 0;

	while (!EXIT_PROGRAM) {
		PointingByte = Bytecode[Pointer];
		if (LightMode) {
			switch (LightMode) {
				case LIGHT_MODE_STRING:
					if (PointingByte == '\0') {
						char** temp = (char**) realloc(declaration, declarationSize + (1 * sizeof(char*)));
						if (temp == NULL) {
							printf("[Light26] Direct declaration did not allocate properly...\n");
							break;
						}
						declaration = temp;
						declaration[declarationNum] = NULL;
						LightExec(declaration);
					} 
					if (PointingByte == ' ') {
						declaration[declarationNum] = tempString;
						declarationNum++;
						tempString[0] = '\0';
						tempStringNum = 0;
						break;
					}
					tempString[tempStringNum] = PointingByte;
					tempStringNum++;
					break;
			}
			continue;
		}
		switch (PointingByte) {
			case LIGHT_OP_EXIT:
				EXIT_PROGRAM = true;
				break;
			case LIGHT_OP_DEF_THINGS:
				LightMode = LIGHT_MODE_STRING;
				break;
		}
	}

	return 0;
}
