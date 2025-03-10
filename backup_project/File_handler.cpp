#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "File_handler.h"
using namespace std;

bool FileHandler::file_create(string filePath) {
    ofstream outfile(filePath);
    if (!outfile.is_open()) {
        return false;
    }
    outfile.close();
    return true;
}

string FileHandler::absolute_path(string filePath) {
    if (filesystem::exists(filePath)) {
        return filesystem::absolute(filePath).string();
    }
    return "";
}
