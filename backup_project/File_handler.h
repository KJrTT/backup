#pragma once
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class FileHandler {
	string filePath;
public:
	FileHandler(string filePath) : filePath(filePath) {};
	bool file_create(string filePath);
	string absolute_path(string filePath);
};
