#pragma once

#include <functional>

namespace HasFunction {
	typedef std::function <unsigned int(const char*, unsigned int) > HashFunc;

	//implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length);

	//Add Your functions Here
	unsigned int secondHash(const char* data, unsigned int length);
	unsigned int thirdHash(const char* data, const char* data2, unsigned int length);
	unsigned int fourthHash(const char* data, const char* data2, unsigned int length);
	unsigned int fifthHash(const char* data, const char* data2, unsigned int length);

	// a helper to access a default hash function
	static HashFunc Default = badHash;
}