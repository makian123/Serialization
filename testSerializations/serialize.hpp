#pragma once

#include <string>
#include <vector>

struct Point {
	float x;
	float y;
};

class PointStruct {
	public:
	std::string name;
	Point point;
	std::string name2;
	std::vector<int> vec;
};