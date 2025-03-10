#include <iostream>
#include <fstream>
#include <string>
#include "Restore_point.h"
using namespace std;


Restore_point::Restore_point(vector<BackupObject> object, time_t time, string storagePath) : object(object), time(time), storagePath(storagePath) {}


vector <BackupObject> Restore_point::getObject() const {
	return object;
}

time_t Restore_point::getTime() {
	return time;
}

string Restore_point::getStoragePath() {
	return storagePath;
}

void Restore_point::addObjects(BackupObject obj) {
	object.push_back(obj);
}