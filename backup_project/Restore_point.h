#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BackObject.h"
#include <ctime>
using namespace std;



class Restore_point {
	vector <BackupObject> object;
	time_t time;
	string storagePath;

public:
	Restore_point(vector<BackupObject> object, time_t time, string storagePath);

	vector<BackupObject> getObject() const;
	time_t getTime();
	string getStoragePath();
	void addObjects(BackupObject obj);
};