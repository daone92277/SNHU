#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>


class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies;

public:
    ItemTracker() {
        // Read input file and populate data structure
        std::ifstream inputFile("input.txt");
        std::string item;
        while (inputFile >> item) {
            // Convert the item to lowercase before storing it in the map
            std::transform(item.begin(), item.end(), item.begin(), ::tolower);
            itemFrequencies[item]++;
        }
        inputFile.close();

        
        // Create backup file and write initial data
        std::ofstream backupFile("frequency.dat");
        for (const auto& pair : itemFrequencies) {
            backupFile << pair.first << " " << pair.second << std::endl;
        }
        backupFile.close();
    }

    // Returns the frequency of the given item.
    int getItemFrequency(const std::string& item) {
        // Convert the item to lowercase to make case-insensitive comparisons.
        std::string lowercaseItem = item;
        std::transform(lowercaseItem.begin(), lowercaseItem.end(), lowercaseItem.begin(), ::tolower);
        return itemFrequencies[lowercaseItem];
    }





    void printItemFrequencies() {
        for (const auto& pair : itemFrequencies) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    void printHistogram() {
        for (const auto& pair : itemFrequencies) {
            std::cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    ItemTracker itemTracker;

    int choice;
    std::string item;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Look up item frequency\n";
        std::cout << "2. Print item frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the item to look up: ";
            std::cin >> item;
            std::cout << "Frequency: " << itemTracker.getItemFrequency(item) << std::endl;
            break;
        case 2:
            itemTracker.printItemFrequencies();
            break;
        case 3:
            itemTracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
