#if __cplusplus < 202002L
#error "This is mapped to C++20, please update!"
#endif

#include <iostream>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <string>
#include <queue>
#include <unordered_map>
#ifndef BYTEBUILD_H
#define BYTEBUILD_H

namespace Light {
	typedef enum : char {
		OP_NULL, // No operation
		OP_EXIT,
		OP_DEF_WRAPPER,
		OP_STR_WRAP, // like " symbol
		OP_SET_SETTER,
		OP_COPY,
		OP_CREATE,
		OP_CREATEDIR,
		OP_DEF,
		OP_PUSH
	} OP_CODE;
	
	typedef enum : char {
		SE_NOFLAG,
		SE_SOURCE,
		SE_VERSION,
		SE_STR_NONFLAG,
		SE_VERBOSE,
		SE_QUIET,
		SE_WALL,
		SE_WERR,
		SE_ONLY_SYNTAX,
		SE_NO_OPTIMIZE,
		SE_ABIT_OPTIMIZE,
		SE_ALOT_OPTIMIZE,
		SE_MAX_OPTIMIZE,
		SE_END
	} SE_CODE;

	typedef enum : char {
		SEC_0,
		SEC_1
	} CODE_CATEGORY;

	typedef enum : char {
		OPT_QUIET_ERROR,
		OPT_ADD_WHEN_ERROR
	} OPT_CODE;
		
	typedef std::vector<char> Bytecode;

	extern std::queue<std::string> wrappers;
	extern std::unordered_map<char, std::string> translationMap;
	extern std::mutex safe_lock;
	extern std::mutex emptySafe_lock;
	extern std::condition_variable emptySafe;
	extern std::string tempString;
	extern std::vector<std::string> argBox;
	extern bool EXIT_PROGRAM;
	extern int requireArguments;
	extern OP_CODE funcNeed;
	extern bool stringMode;
	extern bool SetterMode;
	extern unsigned int SetterCount;
	extern std::string wrapper;
	extern std::string firstwrapper;

	extern void wrapping(std::queue<std::string> wrappers);

	extern void interpretation(char Byte);
	
	extern void interpret(Bytecode bytecode);
}

#endif
