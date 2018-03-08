#ifndef CSNAKE_UTILITY_MACROS_H
#define CSNAKE_UTILITY_MACROS_H
#include<iostream>
void Assert(bool val, char* string) {
	if (!val) {
		std::cout << "Assertion Failed:" << string << "\n";
		exit(-1);
	}
}
inline int ODD(int x) {
	return (x & 1) != 0;
}
#endif // !CSNAKE_UTILITY_MACROS_H

