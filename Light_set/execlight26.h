#ifndef _execlight26_h
#define _execlight26_h

#ifndef _WIN32
extern char** environ;
extern int LightExec(char* const* declaration);
#else
extern int LightExec(wchar_t* declaration);
#endif

#endif
