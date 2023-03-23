#pragma once

#include <fstream>
#include <string>
#include <clang-c/Index.h>
#include <vector>
#include <filesystem>

//! Serializer class
class Parser {
	private:
	std::filesystem::path headerPath, generatedDirPath;

	std::ofstream generatedSerializerHeader;
	std::ofstream generatedSerializerSource;

	std::ofstream generatedDeserializerHeader;
	std::ofstream generatedDeserializerSource;

	std::vector<std::string> filePaths;

	CXChildVisitResult ParseHeader(CXCursor c, CXCursor parent);

	CXChildVisitResult ParseClass(CXCursor c, CXCursor parent);
	CXChildVisitResult ParseFields(CXCursor c, CXCursor parent);

	static CXChildVisitResult VisitorHeader(CXCursor cursor, CXCursor parent, CXClientData client_data) {
		return static_cast<Parser *>(client_data)->ParseHeader(cursor, parent);
	}
	static CXChildVisitResult VisitorSource(CXCursor cursor, CXCursor parent, CXClientData client_data) {
		return static_cast<Parser *>(client_data)->ParseClass(cursor, parent);
	}
	static CXChildVisitResult VisitorFields(CXCursor cursor, CXCursor parent, CXClientData client_data) {
		return static_cast<Parser *>(client_data)->ParseFields(cursor, parent);
	}
	public:
	Parser(const std::string &headerLocation);

	/// <summary>
	/// Begins the file appending
	/// </summary>
	void Begin();
	/// <summary>
	/// Adds the file from which to generate code
	/// </summary>
	/// <param name="path">Relative filepath containing the structures</param>
	void SerializeFile(const std::string &path);
	/// <summary>
	/// Generates the code, call only after `Begin()`
	/// </summary>
	void End();
};