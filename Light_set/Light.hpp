#if __cplusplus < 202002L
#error "This is mapped to C++20, please update!"
#endif

#include <iostream>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <string>
#include <queue>
#include <atomic>
#include <unordered_map>
#include <utility>
#include <functional>
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
		OP_PUSH,
		OP_NOTIFY,
		OP_END,
		OP_SET,
		OP_IF
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
		SE_END = 0xFD
	} SE_CODE;

	typedef enum : char {
		SEC_NULL,
		SEC_0
	} CODE_CATEGORY;

	typedef enum : char {
		TRIG_NULL,
		TRIG_WHEN_ERROR
	} TRIG_CODE;

	typedef enum : char {
		SETA_TRIGGER_IF,
		SETA_TRACKER_TO
	} SETA_CODE;
		
	typedef char byte;
	typedef std::vector<byte> Bytecode;
	struct hash_pair {
		template <class T1, class T2>
		size_t operator()(const std::pair<T1, T2>& p) const;
	};

	extern std::queue<std::string> wrappers;
	extern std::unordered_map<std::pair<char,char>, std::string, hash_pair> translationMap;
	extern std::mutex safe_lock;
	extern std::mutex emptySafe_lock;
	extern std::condition_variable emptySafe;
	extern std::string tempString;
	extern std::vector<std::string> argBox;
	extern bool EXIT_PROGRAM;
	extern int requireArguments;
	extern OP_CODE funcNeed;
	extern bool stringMode;
	extern unsigned int SetterCount;
	extern std::atomic<bool> Triggered;
	extern unsigned int SetterBytesNeed;
	extern TRIG_CODE trigger;
	

	extern void wrapping();

	extern void interpretation(Bytecode bytecode);
	
	extern void interpret(Bytecode bytecode);
}

#endif
