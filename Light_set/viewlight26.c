#include <viewlight26.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

SDL3Process LightCreateProcess(char* SDL3WindowName, unsigned WidthSize, unsigned HeightSize, char* bytecode) {
	if (!SDL_WasInit(SDL_INIT_VIDEO)) {
		SDL_Init(SDL_INIT_VIDEO);
	}
	SDL_Window* SDL3Window {
		SDL_CreateWindow(SDL3WindowName, WidthSize, HeightSize, 0);
	};
	
	SDL_Event SDLevent;
	
	SDL3Process DaSDL3_Process;
	DaSDL3_Process.WINDOW = SDL3Window;
	DaSDL3_Process.EVENT = SDLevent;
	
	return DaSDL3_Process;
}

void LightPollEventType(SDL3Process* SDL3CreatedProcess) {
	SDL_Event DaEvent;
	SDL_PollEvent(&DaEvent);
	SDL3CreatedProcess.EVENT = DaEvent;
}

void LightCheck(SDL3Process SDL3CreatedProcess, uint32_t EventCheck, int* ConToBeChanged) {
	if (SDL3CreatedProcess.EVENT.type == (SDL_EventType) EventCheck) {
		ConToBeChanged = 1;
	} else {
		ConToBeChanged = 0;
	}
}

void LightQuit(SDL_Window* SDL3CreatedProcess) {
	SDL_DestroyWindow(SDL3CreatedProcess.WINDOW);
	SDL_Quit();
}


