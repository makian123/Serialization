#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <type_traits>

template<typename T>
std::string Serialize(T obj);

template<typename T>
T Deserialize(const std::string &in);

//This is all the specializations we will need in the code
//Do not remove or modify the file
#include "generated/serializeSpecializations.h"
#include "generated/deserializeSpecializations.h"

template<typename T>
concept is_vector = requires(T obj) {
	std::is_base_of<std::vector<typename T::value_type, typename T::allocator_type>, T>().value == 1;
	std::begin(obj);
	std::end(obj);
	obj.size();
};

template<class T>
std::string Serialize(T obj) requires is_vector<T> {
	std::string ret;

	ret.resize(sizeof(size_t));
	size_t vecLen = obj.size();
	memcpy(ret.data(), &vecLen, sizeof(size_t));

	for (auto &item : obj) {
		ret += Serialize<typename T::value_type>(item);
	}

	size_t retLen = ret.length();
	ret.insert(0, sizeof(size_t), '\0');
	memcpy(ret.data(), &retLen, sizeof(size_t));

	return ret;
}
template<class T>
T Deserialize(const std::string &in) requires is_vector<T> {
	T ret;
	size_t offset = sizeof(size_t);
	size_t newVecLen;

	memcpy(&newVecLen, (in.data() + offset), sizeof(size_t));

	ret.resize(newVecLen);
	offset += sizeof(size_t);

	size_t tmp;
	for (size_t i = 0; i < newVecLen; ++i) {
		ret[i] = Deserialize<typename T::value_type>(in.substr(offset));
		memcpy(&tmp, in.data() + offset, sizeof(size_t));

		offset += tmp + sizeof(size_t);
	}
	return ret;
}

template<typename T>
std::string Serialize(T obj) {
	std::string ret;
	ret.resize(sizeof(T));

	memcpy(ret.data(), &obj, sizeof(T));

	size_t len = ret.size();
	ret.insert(0, sizeof(size_t), '\0');
	*(size_t *)ret.data() = len;

	return ret;
}

template<typename T>
T Deserialize(const std::string &in) {
	T ret;

	size_t len;
	memcpy(&len, in.data(), sizeof(size_t));

	memcpy(&ret, in.data() + sizeof(size_t), len);

	return ret;
}
