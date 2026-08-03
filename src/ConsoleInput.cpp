#include "../header/ConsoleInput.h"
#include "../header/Validation.h"
#include "../header/PlaylistManagement.h"
#include "../header/Subjects.h"

#include <iostream>
#include <string>

using namespace std;

//Input integer
void inputIntegerInRange(int& target, int min, int max, const string& prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin, input);

        if (!isIntegerBelongRange(input, min, max)) {
            cout << "Only enter a number from "
                 << min << " to " << max << "." << endl;
            continue;
        }

        target = stoi(input);
        return;
    }
}

//Input string
//Enter prompt, return input from user
string inputString(const string& prompt)
{
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty())
        {
            cout << "Input cannot be empty.\n";
            continue;
        }

        return input;
    }
}

// Input Song
Song PlaylistManagement::inputSong(){
    string id;
    while (true) {
        id = inputString("Song ID: ");

        Node* temp = head;
        
        while (temp != nullptr) {
            if (temp->data.getId() == id) {
                cout << "ID already exists. Please enter a unique ID.\n";
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            break;
        }
    }

    // Nhập các thông tin còn lại bằng biến Stack thông thường
    string title = inputString("Title: ");
    string artist = inputString("Artist: ");
    
    int duration = 0;
    inputIntegerInRange(duration, 1, 100000, "Duration (seconds): ");

    // Tạo đối tượng Song gọn gàng
    Song song;
    song.setId(id);
    song.setTitle(title);
    song.setArtist(artist);
    song.setDuration(duration);

    return song;
}

void waitEnter(){
    cout << "\nPress Enter to back...";
    cin.get();
}