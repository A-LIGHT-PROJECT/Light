#ifndef _execlight26_h
#define _execlight26_h
#ifdef __cplusplus
extern "C" {
#endif
#ifndef _WIN32
extern char** environ;
#endif

extern int LightExec(char* const* argv);

#ifdef __cplusplus
}
#endif
#endif
