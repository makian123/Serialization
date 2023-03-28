#include <iostream>
#include <fstream>
#include <filesystem>
#include <clang-c/Index.h>
#include <string>
#include <vector>

#include "Library/parser.h"

#include "Library/serialize.h"

#include <array>

int main(int argv, char *argc[]) {
	std::array<char, 5> vec = { 1, 2, 3, 4, 5 };

	std::string serialized = Serialize<std::array<char, 5>>(vec);

	/*if (argv < 4) {
		std::cout << "Correct syntax: -I \"library_header_path\"/ \"<files>\"";
		return 1;
	}

	std::string libPath;
	std::vector<std::string> files;

	for (size_t i = 1; i < argv; ++i) {
		if (!strcmp(argc[i], "-I")) {
			libPath = std::string(argc[++i]);
			if (libPath.back() != '/' && libPath.back() != '\\') {
				libPath += '/';
			}
			continue;
		}

		files.emplace_back(argc[i]);
	}

	Parser serializer = Parser(libPath);

	serializer.Begin();
	for (size_t i = 0; i < files.size(); ++i) {
		serializer.SerializeFile(files[i]);
	}
	serializer.End();*/

	return 0;
}