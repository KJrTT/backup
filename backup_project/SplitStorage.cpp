#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <iomanip>
#include "SplitStorage.h"
#include "BackObject.h"
#include "Restore_point.h"

namespace fs = std::filesystem;

using namespace std;

SplitStorage::SplitStorage(BackupObject objects, Restore_point point) : objects(objects), point(point) {}

void SplitStorage::store(BackupObject objects, Restore_point point) {
    string storagePath = point.getStoragePath();
    if (!fs::exists(storagePath)) {
        try {
            fs::create_directories(storagePath);
            cout << "Created directory at: " << storagePath << endl;
        }
        catch (const fs::filesystem_error& e) {
            cerr << "Error creating directory: " << e.what() << endl;
            throw;
        }
    }

    string sourcePath = objects.getPath();
    if (!fs::exists(sourcePath)) {
        cerr << "Source file does not exist: " << sourcePath << endl;
        return;
    }

    string fileName = fs::path(sourcePath).filename().string();
    string destinationPath = storagePath + "/" + fileName + ".zip";

    std::stringstream zipCommand;
#ifdef _WIN32
    zipCommand << "powershell Compress-Archive -Path \"" << sourcePath << "\" -DestinationPath \""
        << destinationPath << "\" -Force";
#else
    zipCommand << "zip -j \"" << destinationPath << "\" \"" << sourcePath << "\"";
#endif

    int result = std::system(zipCommand.str().c_str());

    if (result != 0) {
        cerr << "Error creating zip archive for file: " << fileName << endl;
        throw std::runtime_error("Error creating zip archive");
    }

    time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    cout << "File archived to: " << destinationPath << " at "
        << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << endl;
    point.addObjects(BackupObject(destinationPath));
}