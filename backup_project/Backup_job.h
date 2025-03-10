#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "Restore_point.h"
#include "BackObject.h"
using namespace std;


class BackupJob {
	vector <Restore_point>& point;
	vector <BackupObject>& objects;

public:
	BackupJob(vector <Restore_point>& point, vector <BackupObject> objects) : point(point), objects(objects) {};

	void create_point(vector <Restore_point>& point);
	void show_points();
};