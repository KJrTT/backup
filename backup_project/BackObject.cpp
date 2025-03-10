#include <iostream>
#include <fstream>
#include <string>
#include "BackObject.h"
using namespace std;

BackupObject::BackupObject(string path) : path(path) {};


string BackupObject::getPath() const{
	return path;
}

bool BackupObject::CheckingFilePresence() {
	ifstream file(path);
	return file.good();
}

