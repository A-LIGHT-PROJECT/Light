#ifndef __LIGHTEXE_H_
#define __LIGHTEXE_H_
#ifdef __cplusplus
extern "C" {
#endif

extern char** environ;
extern int spawnexee(char* const* argv);

typedef struct {
	char* c_str;
	int NumOfChars;
	int AllocMax;
} ligtempstring;

extern void LIGstrpush(ligtempstring* TempString, char Character);

extern char* LIGstrreturn(ligtempstring* TempString);

extern void LIGstrinit(ligtempstring* TempString);

#ifdef __cplusplus
}
#endif
#endif
