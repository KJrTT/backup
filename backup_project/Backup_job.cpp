#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include "Restore_point.h"
#include "Backup_job.h"
#include "BackObject.h"
using namespace std;

void BackupJob::create_point(vector<Restore_point>& point) {
    for (auto list : point) {
        for (auto obj : list.getObject()) {
            cout << obj.getPath() << endl;
        }
    }
}

void BackupJob::show_points() {
    if (point.empty()) {
        cout << "No restore points\n";
        return;
    }

    cout << "All points: \n";

    for (auto pt : point) {
        time_t time = pt.getTime();
        std::tm localTime;
        localtime_s(&localTime, &time);
        cout << "Restore Point Time: " << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << endl;
        cout << "Storage Path: " << pt.getStoragePath() << endl;
        cout << "Files in this restore point:\n";

        objects = pt.getObject();
        if (objects.empty()) {
            cout << "Empty file";
        }
        else {
            for (auto obj : objects) {
                cout << "  - " << obj.getPath() << endl;
            }
        }
    }
}