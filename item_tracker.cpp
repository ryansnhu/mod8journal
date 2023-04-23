#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ItemTracker {
    private:
        map<string, int> itemFrequencyMap;

        // Private method to read the input file and update the item frequency map
        void readInputFileAndUpdateMap() {
            ifstream inputFile("CS210_Project_Three_Input_File.txt");
            string itemName;
            int itemQuantity;

            while (inputFile >> itemName >> itemQuantity) {
                itemFrequencyMap[itemName] += itemQuantity;
            }
            inputFile.close();
        }

    public:
        // Constructor to read input file and initialize the item frequency map
        ItemTracker() {
            readInputFileAndUpdateMap();
        }

        // Public method to prompt user for item/word and return its frequency
        void findItemFrequency() {
            string itemName;
            cout << "\nEnter the item/word you wish to look for: ";
            cin >> itemName;
            cout << "The frequency of " << itemName << " is: " << itemFrequencyMap[itemName] << endl;
        }

        // Public method to print the list of all items and their frequency
        void printItemList() {
            cout << "\nList of all items and their frequency: " << endl;
            for (auto it = itemFrequencyMap.begin(); it != itemFrequencyMap.end(); ++it) {
                cout << it->first << " " << it->second << endl;
            }
        }

        // Public method to print a histogram of all items and their frequency
        void printItemHistogram() {
            cout << "\nHistogram of all items and their frequency: " << endl;
            for (auto it = itemFrequencyMap.begin(); it != itemFrequencyMap.end(); ++it) {
                cout << it->first << " ";
                for (int i = 0; i < it->second; i++) {
                    cout << "*";
                }
                cout << endl;
            }
        }

        // Public method to backup the item frequency map to a file
        void backupItemFrequencyMap() {
            ofstream outputFile("frequency.dat");
            for (auto it = itemFrequencyMap.begin(); it != itemFrequencyMap.end(); ++it) {
                outputFile << it->first << " " << it->second << endl;
            }
            outputFile.close();
        }
};

int main() {
    ItemTracker tracker;

    int menuOption = 0;
    while (menuOption != 4) {
        cout << "\n\n***** ITEM TRACKER PROGRAM MENU *****\n" << endl;
        cout << "1. Find item frequency" << endl;
        cout << "2. Print item list" << endl;
        cout << "3. Print item histogram" << endl;
        cout << "4. Exit program\n" << endl;

        cout << "Enter menu option (1-4): ";
        cin >> menuOption;

        switch (menuOption) {
            case 1:
                tracker.findItemFrequency();
                break;
            case 2:
                tracker.printItemList();
                break;
            case 3:
                tracker.printItemHistogram();
                break;
            case 4:
                tracker.backupItemFrequencyMap();
                cout << "\nProgram exiting... " << endl;
                break;
            default:
                cout << "Invalid menu option! Please try again." << endl;
                break;
        }
    }

    return 0;
}
