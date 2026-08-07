#if defined(__WIN32)
#include <windows.h>
#define IS_WINDOWS true
#else
#include <unistd.h>
#define IS_WINDOWS false
#endif
#include <filesystem>

#ifndef __LIGHTEXE_H__
#define __LIGHTEXE_H__
extern void spawnexe(const char* argv[]);
#endif
