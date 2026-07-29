#include <iostream>
#include <fstream>
#include <mutex>
#include <filesystem>
#include <condition_variable>
#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <atomic>
#include <Light.hpp>

namespace Light {
	
	
	template <class T1, class T2>
	size_t hash_pair::operator()(const std::pair<T1, T2>& p) const
	{
		size_t hash1 = std::hash<T1>{}(p.first);

		size_t hash2 = std::hash<T2>{}(p.second);

		return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
	}
	

	std::queue<std::string> wrappers;
	std::unordered_map<std::pair<char, char>, std::string, hash_pair> translationMap;
	std::mutex safe_lock;
	std::mutex emptySafe_lock;
	std::condition_variable emptySafe;
	std::string tempString;
	std::vector<std::string> argBox;
	bool EXIT_PROGRAM = false;
	int requireArguments = 0;
	OP_CODE funcNeed = OP_NULL;
	bool stringMode = false;
	bool SetterMode = false;
	unsigned int SetterCount = 0;
	unsigned int SetterBytesNeed = 0;
	TRIG_CODE trigger;
	std::atomic<bool> Triggered{false};
#ifdef _WIN32
	std::string home = std::getenv("USERPROFILE");
#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__)
	std::string home = std::getenv("HOME");
#else
#error "Your operating system is not availiable for Light, sorry!"
#endif
	
	void wrapping() {
		while (true) {
			safe_lock.lock();
			if (wrappers.empty()) {
				safe_lock.unlock();
				continue;
			}

			std::string getWrapper = wrappers.front();
			wrappers.pop();

			if (std::system(getWrapper.c_str()) == -1) {
				std::cerr << "A wrapper didn't execute as expected..\n";
			}

			safe_lock.unlock();
		}
	}

	void interpretation(Bytecode bytecode) {
			
		std::string firstwrapper;
		std::string wrapper;
		
		auto checkArguments = []() {
			if (requireArguments > 0) {
			EXIT_PROGRAM = true;
				emptySafe.notify_all();
				std::cerr << "[Light] Need " << requireArguments 
				<< " arguments in order to execute properly\n";
			} else if (requireArguments < 0) {
				EXIT_PROGRAM = true;
				emptySafe.notify_all();
				std::cerr << "[Light] There was no required argument needed...\n";
			}
		};
		
		auto checkFileForTrans = [](std::ifstream &file) {
			char someChar;
			SE_CODE NeedFlag = SE_NOFLAG;
			bool Exit_Flagger = false;
			char FirstFlagByte = SEC_NULL;			
			while (someChar = file.get()) {
				if (stringMode) {
					if (someChar == OP_STR_WRAP) {
						stringMode = false;
						translationMap.insert({{FirstFlagByte, NeedFlag}, tempString});
						tempString.clear();
						NeedFlag = SE_NOFLAG;
						FirstFlagByte = SEC_NULL;
						continue;
					}
					tempString += someChar;
					continue;
				}
				if (FirstFlagByte == SEC_0) {
					switch (someChar) {
						case OP_STR_WRAP:
							stringMode = true;
							break;
						case SE_SOURCE:
							NeedFlag = SE_SOURCE;
							break;
						case SE_VERSION:
							NeedFlag = SE_VERSION;
							break;
						case SE_VERBOSE:
							NeedFlag = SE_VERBOSE;
							break;
						case SE_QUIET:
							NeedFlag = SE_QUIET;
							break;
						case SE_WALL:
							NeedFlag = SE_WALL;
							break;
						case SE_WERR:
							NeedFlag = SE_WERR;
							break;
						case SE_ONLY_SYNTAX:
							NeedFlag = SE_ONLY_SYNTAX;
							break;
						case SE_NO_OPTIMIZE:
							NeedFlag = SE_NO_OPTIMIZE;
							break;
						case SE_MAX_OPTIMIZE:
							NeedFlag = SE_MAX_OPTIMIZE;
							break;
						case SE_END:
							Exit_Flagger = true;	
					}
					if (Exit_Flagger) {
						break;
					}
				} else {
					switch (someChar) {
						case SEC_0:
							FirstFlagByte = SEC_0;
							break;
						default:
							std::cerr << "[Light] Invalid first byte....\n";
					}
				}
			}

		};
		
		char CategorySetter;

		for (byte Byte : bytecode) { 
			
			if (SetterBytesNeed) {
				SetterBytesNeed -= 1;
				if (SetterBytesNeed == 1) {
					CategorySetter = Byte;
					continue;
				}
				if (translationMap.contains({CategorySetter, Byte})) {
					wrapper += " " + translationMap.at({CategorySetter, Byte});
				} else
					std::cerr << "[Light] Flag" << SetterCount <<  "isn't availible according to this translation... This wont affect the program.\n";
				
				SetterMode = false;
			}

			if (stringMode) {
				if (Byte == OP_STR_WRAP)
					stringMode = false;
					std::string translationMain;
					requireArguments -= 1;
					if (funcNeed == OP_DEF_WRAPPER) {
						firstwrapper = tempString;
						tempString.clear();
						std::filesystem::path LightTranslationLayer(home + "/.config/Light_build/translationLayer");
						if (!wrapper.empty()) {
							wrappers.push(wrapper);
						}
						if (std::filesystem::exists(std::filesystem::path(firstwrapper))) {
							std::filesystem::path wrapperTransLookFor(std::filesystem::path(firstwrapper).stem().string() + ".light");
							std::filesystem::path LightTranslation = LightTranslationLayer / wrapperTransLookFor;
							if (std::filesystem::exists(LightTranslation)) {
								std::ifstream TranslationFile(LightTranslation.string());
								checkFileForTrans(TranslationFile);
								TranslationFile.close();
							} else {
								std::cerr << "[Light] this translation doesn't exist inside the folder translationLayer\n";
							}

						} else {
							std::filesystem::path wrapperTransLookFor(firstwrapper + ".light");

							std::filesystem::path LightTranslation = LightTranslationLayer / wrapperTransLookFor;
							if (std::filesystem::exists(LightTranslation)) {
								std::ifstream TranslationFile(LightTranslation.string());
								checkFileForTrans(TranslationFile);
								TranslationFile.close();
							} else {
								std::cerr << "[Light] this translation doesn't exist inside the folder translationLayer\n";
							}
						}
						wrapper = firstwrapper;
					} else if (funcNeed == OP_COPY) {
						switch (requireArguments) {
							case 1:
								argBox.push_back(tempString);
								tempString.clear();
								break;
							case 0:
								std::filesystem::copy(std::filesystem::path(argBox.at(0)), std::filesystem::path(tempString));
								tempString.clear();
						}
					} else if (funcNeed == OP_CREATE) {
						std::ofstream MyFile(tempString);
						MyFile << " ";
						MyFile.close();
						tempString.clear();
					} else if (funcNeed == OP_CREATEDIR) {
						std::filesystem::create_directories(tempString);
						tempString.clear();
					} else if (funcNeed == OP_DEF) {
						wrapper += tempString;
						tempString.clear();
					}
					funcNeed = OP_NULL;
			} else
				tempString.push_back(Byte);

			switch (Byte) {
				case OP_NULL:
					break;
				case OP_EXIT:
					EXIT_PROGRAM = true;
					if (!wrapper.empty())
						wrappers.push(wrapper);
					safe_lock.unlock();
					break;
				case OP_DEF_WRAPPER:
					checkArguments();
					funcNeed = OP_DEF_WRAPPER;
					requireArguments = 1;
					break;
				case OP_STR_WRAP:
					stringMode = true;
					break;
				case OP_COPY:
					checkArguments();
					funcNeed = OP_COPY;
					requireArguments = 2;
					break;
				case OP_CREATE:
					checkArguments();
					funcNeed = OP_CREATE;
					requireArguments = 1;
					break;
				case OP_CREATEDIR:
					checkArguments();
					funcNeed = OP_CREATEDIR;
					requireArguments = 1;
					break;
				case OP_DEF:
					checkArguments();
					funcNeed = OP_DEF;
					requireArguments = 1;
					break;
				case OP_SET_SETTER:
					SetterBytesNeed = 2;
					SetterCount += 1;
					break;
				case OP_PUSH:
					wrappers.push(wrapper);
					safe_lock.unlock();
					safe_lock.lock();	
				default:
					std::cerr << "[Light] Invalid byte... Turn into OP_NULL...\n";
			}
		}

	}

	void interpret(Bytecode bytecode) {

		std::thread InterpretThread(interpretation, bytecode);
		std::thread WrapperThread(wrapping);

		if (!InterpretThread.joinable() || !WrapperThread.joinable()) {
			std::cerr << "[Light] The wrapper or interpretation thread is not joinable for execution.\n";
			return;
		}

		InterpretThread.join();
		WrapperThread.join();
	}
}
