#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "SingleStorage.h"
#include "SplitStorage.h"
#include "BackObject.h"
#include "Restore_point.h"
#include "Backup_job.h"

using namespace std;

int main() {
    vector<BackupObject> objects;
    vector<Restore_point> restorePoints;
    BackupJob backupJob(restorePoints, objects);

    while (true) {
        cout << "1. Create Restore Point\n";
        cout << "2. Show Restore Points\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            vector<BackupObject> currentObjects;
            string filePath;
            char addMore;

            do {
                cout << "Enter file path to backup: ";
                cin >> filePath;

                BackupObject backupObj(filePath);
                if (!backupObj.CheckingFilePresence()) {
                    cout << "The file is not in this path\n";
                    continue;
                }
                currentObjects.push_back(backupObj);

                cout << "Add another file? (y/n): ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');

            cout << "\nMethod: \n";
            cout << "1. Single Storage (all location)\n";
            cout << "2. Split Storage (split location)\n";
            cout << "Enter your choice: ";

            int storageChoice;
            cin >> storageChoice;

            time_t currentTime = std::time(nullptr);
            Restore_point restorePoint(currentObjects, currentTime, "backup_storage");

            Storage* storage = nullptr;
            try {
                if (storageChoice == 1) {
                    storage = new SingleStorage(currentObjects[0], restorePoint);
                    cout << "Single Storage selected\n";
                }
                else if (storageChoice == 2) {
                    storage = new SplitStorage(currentObjects[0], restorePoint);
                    cout << "Split Storage selected\n";
                }
                else {
                    cout << "Invalid storage choice\n";
                    continue;
                }

                for (const auto& obj : currentObjects) {
                    storage->store(obj, restorePoint);
                }
                restorePoints.push_back(restorePoint);
                cout << "Backup process completed successfully.\n";
            }
            catch (const exception& e) {
                cout << "Error during backup: " << e.what() << endl;
            }

            delete storage;
        }
        else if (choice == 2) {
            backupJob.show_points();
        }
        else if (choice == 3) {
            cout << "Exiting \n";
            break;
        }
        else {
            cout << "Please try again.\n";
        }
    }

    return 0;
}