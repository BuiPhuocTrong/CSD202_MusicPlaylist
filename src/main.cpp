
#include "../header/ConsoleInput.h"

#include <iostream>

using namespace std;
/*
-class
-4 data attributes, 1 pointer
-add, delete, sort, search, update, display
- have menu
*/

// Recall showMenu() 
// Handle user input
// No parameters, no return value
// Function to display the menu, no parameters, no return value

bool isRunning = 1;
void showMenu (){
    cout << "==============================\n";
    cout << "MUSIC PLAYLIST MANAGEMENT\n";
    cout << "1. Add song\n";
    cout << "2. Delete song\n";
    cout << "3. Search song\n";
    cout << "4. Sort playlist\n";
    cout << "5. Update song information\n";
    cout << "6. Display playlist\n";
    cout << "0. Exit\n";
    cout << "==============================\n";
}

void loopMenu (){
    int choice = -1;
    do {
        showMenu();
        inputIntegerInRange(choice, 0, 9, "==> Enter your selection: ");
        switch (choice) {
            case 1:
                // Add song
                break;
            case 2:
                // Delete song
                break;
            case 3:
                // Search song
                break;
            case 4:
                // Sort playlist
                break;
            case 5:
                // Update song information
                break;
            case 6:
                // Display playlist
                break;
            case 0:
                isRunning = false;
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (isRunning);
}



int main (){
    loopMenu();
    return 0;
}