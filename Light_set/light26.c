#include <stdio.h>
#include <stdlib.h>
#include <light26.h>
#include <execlight26.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int LightProcessor(char* Bytecode, long PointTo) {
	char PointingByte;
	uint32_t Pointer = PointTo;
	bool EXIT_PROGRAM = false;
	int LightMode = 0;
	char** declaration = NULL;
	int declarationNum = 0;
	int tempStringNum = 0;
	char* tempString = NULL;

	printf("before processes v1\n");

	while (!EXIT_PROGRAM) {
		printf("doing processes\n");
		PointingByte = Bytecode[Pointer];
		if (LightMode) {
			switch (LightMode) {
				case LIGHT_MODE_INIT_STRING:
					tempString = malloc(1 * sizeof(char));
					declaration = malloc(2 * sizeof(char*));
					LightMode = LIGHT_MODE_STRING;
					break;
				case LIGHT_MODE_STRING:
					if (PointingByte == ' ' || PointingByte == '\0') {
						{
							char** temp = (char**) realloc(declaration, (declarationNum + 3) * sizeof(char*));
							if (temp == NULL) {printf("[Light26] Reallocation not worked properly\n"); EXIT_PROGRAM = true; break;}
							declaration = temp;
						}
						tempString[tempStringNum] = '\0';
						printf("hello\n");
						declaration[declarationNum] = (char*) malloc((tempStringNum + 2) * sizeof(char));
						printf("hey\n");
						strcpy(declaration[declarationNum++], tempString);
						printf("hi\n");
						free(tempString);
						tempStringNum = 0;
						if (PointingByte == '\0') {
							declaration[declarationNum] = NULL;
							LightExec(declaration);
							free(declaration);
							LightMode = 0;
							break;
						}
						tempString = malloc(1 * sizeof(char));
						break;
					}
					{
						char* temp = (char*) realloc(tempString, (tempStringNum + 2) * sizeof(char));
						if (temp == NULL) {
							printf("[Light26] Reallocation not worked properly\n");
							EXIT_PROGRAM = true;
							break;
						}
						tempString = temp;
					}
					tempString[tempStringNum++] = PointingByte;
					break;
			}
			Pointer++;
			continue;
		}
		switch (PointingByte) {
			case LIGHT_OP_EXIT:
				EXIT_PROGRAM = true;
				break;
			case LIGHT_OP_DEF_THINGS:
				LightMode = LIGHT_MODE_INIT_STRING;
				break;
		}
		Pointer++;
	}

	return 0;
}
