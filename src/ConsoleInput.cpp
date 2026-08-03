#include "../header/ConsoleInput.h"
#include "../header/Validation.h"

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
Song inputSong()
{
    string *id = new string;
    *id = inputString("Song ID: ");

    string *title = new string;
    *title = inputString("Title: ");

    string *artist = new string;
    *artist = inputString("Artist: ");

    int *duration = new int;
    inputIntegerInRange(*duration, 1, 100000, "Duration (seconds): ");

    Song song;
    song.setId(*id);
    song.setTitle(*title);
    song.setArtist(*artist);
    song.setDuration(*duration);

    delete id;
    delete title;
    delete artist;
    delete duration;

    return song;
}

void waitEnter(){
    cout << "\nPress Enter to back...";
    cin.get();
}