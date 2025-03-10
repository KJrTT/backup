#pragma once
#include <iostream>
#include <string>
using namespace std;



class BackupObject {
	string path;

public:
	BackupObject(string path);

	string getPath() const;
	bool CheckingFilePresence();
};