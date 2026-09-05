#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#ifndef _VIEWLIGHT_H
#define _VIEWLIGHT_H

typedef struct {
	SDL_Window WINDOW;
	SDL_Event EVENT;
} SDL3Process;

SDL3Process LightCreateProcess(char* SDL3WindowName, int WidthSize, int HeightSize, char* bytecode);
void LightPollEventType(SDL3Process* SDL3CreatedProcess);
void LightCheck(SDL3Process SDL3CreatedProcess, uint32_t EventCheck, int* ConToBeChanged);
void LightQuit(SDL3Process SDL3Window);

#endif
