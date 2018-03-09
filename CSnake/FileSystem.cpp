#include"FileSystem.h"

FileSystem& FileSystem::instance() {
#if PLATFROM == PLAYSTATION3
	static FileSystem *instance = new PS3FileSystem();
#elif PLATFROM == WII
	static FileSystem * instance = new WiiFileSystem();
#endif
	return *instance;
}

//#define DEBUG_CSNAKE_FILESYSTEM_H
#ifdef DEBUG_CSNAKE_FILESYSTEM_H
#include <iostream>

int main() {
	std::cout << FileSystem::instance().read("")<<"\n";
	system("pause");
}

#endif