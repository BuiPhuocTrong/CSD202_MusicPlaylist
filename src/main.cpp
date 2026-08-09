#include "../header/ConsoleInput.h"
#include "../header/PlaylistManagement.h"

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

/*
-class
-4 data attributes, 1 pointer
-add, delete, sort, search, update, display
-have menu
*/

#define ASCENDING true
#define DESCENDING false

#define A_to_Z true
#define Z_to_A false

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

PlaylistManagement playlist;
bool isRunning = true;

// Display Main Menu
void showMenu()
{
    clearScreen();
    cout << "\n=========================================\n";
    cout << "        MUSIC PLAYLIST MANAGEMENT\n";
    cout << "=========================================\n";
    cout << "1. Add song\n";
    cout << "2. Delete song\n";
    cout << "3. Search song\n";
    cout << "4. Sort playlist\n";
    cout << "5. Update song information\n";
    cout << "6. Display playlist\n";
    cout << "0. Exit\n";
    cout << "=========================================\n";
}

// Loop Menu
void loopMenu()
{
    int choice;

    do
    {
        showMenu();

        inputIntegerInRange(choice, 0, 6, "==> Enter your selection: ");

        switch (choice)
        {
        // ADD
        case 1:
        {
            int option;

            cout << "\n------ ADD SONG ------\n";
            cout << "1. Add First\n";
            cout << "2. Add Last\n";
            cout << "3. Add At Position\n";
            while (true){
               
                if (inputIntegerWithQuit(option, "Choose (or 'q' to quit): "))
                {
                    break; // Exit if user chooses to quit
                }
                else if (option >= 1 && option <= 3)
                {
                    break; // Valid option, exit loop
                }
                else
                {
                    cout << "Invalid option. Please choose a valid option.\n";
                }
               
            }

            // if (inputIntegerWithQuit(option, "Choose (or 'q' to quit): "))
            // {
            //     break; // Exit if user chooses to quit
            // }
            //  else {
            //     cout << "Invalid option. Please choose a valid option.\n";
            //     break;
            // }

            clearScreen();

            switch (option)
            {
            case 1:
                playlist.addFirst();
                break;
            case 2:
                playlist.addLast();
                break;
            case 3:
                playlist.addIndex(playlist.getSize());
                break;
            }

            break;
        }

        // DELETE
        case 2:
        {
            int option;

            cout << "\n------ DELETE SONG ------\n";
            cout << "1. Delete First\n";
            cout << "2. Delete Last\n";
            cout << "3. Delete By ID\n";
            cout << "4. Delete At Position\n";

            if (inputIntegerWithQuit(option, "Choose(or 'q' to quit): "))
            {
                break;
            }

            clearScreen();

            switch (option)
            {
            case 1:
                playlist.deleteFirst();
                break;

            case 2:
                playlist.deleteLast();
                break;

            case 3:
                playlist.deleteById();
                break;

            case 4:
                playlist.deleteIndex(playlist.getSize());
                break;
            default:
                cout << "Invalid option.\n";
            }

            break;
        }

        // SEARCH
        case 3:
        {
            int option;

            cout << "\n------ SEARCH SONG ------\n";
            cout << "1. Search By ID\n";
            cout << "2. Search By Title\n";

            if (inputIntegerWithQuit(option, "Choose(or 'q' to quit): "))
            {
                break;
            }

            clearScreen();

            if (option == 1)
            {
                Node *result = playlist.searchById();

                if (result == nullptr)
                {
                    cout << "Song not found.\n";
                }
                else
                {
                    result->data.display();
                }
                waitEnter();
            }
            else
            {
                playlist.searchByTitle();
            }

            break;
        }

        // SORT
        case 4:
        {
            int option;

            cout << "\n------ SORT PLAYLIST ------\n";
            cout << "1. Duration Ascending\n";
            cout << "2. Duration Descending\n";
            cout << "3. Title A-Z\n";
            cout << "4. Title Z-A\n";

            if (inputIntegerWithQuit(option, "Choose(or 'q' to quit): "))
            {
                break;
            }

            clearScreen();
            switch (option)
            {
            case 1:
                playlist.sortDuration(ASCENDING);
                break;

            case 2:
                playlist.sortDuration(DESCENDING);
                break;

            case 3:
                playlist.sortTitle(A_to_Z);
                break;

            case 4:
                playlist.sortTitle(Z_to_A);
                break;
            }

            break;
        }
        

        //=========================
        // UPDATE
        //=========================
        case 5:
    
            clearScreen();
            playlist.updateSong();

            break;
        

        //=========================
        // DISPLAY
        //=========================
        case 6:
       
            clearScreen();
            playlist.displayPlaylist();
            break;
        

        //=========================
        // EXIT
        //=========================
        case 0:
        {
            isRunning = false;
            cout << "Exiting the program...\n";
            break;
        }

        default:
            cout << "Invalid choice.\n";
        }

    } while (isRunning);
}

// ======================
// Main
// ======================

int main()
{
    clearScreen();
    loopMenu();
    return 0;
}