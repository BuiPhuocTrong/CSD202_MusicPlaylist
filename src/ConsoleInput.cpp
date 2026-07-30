#include "../header/ConsoleInput.h"
#include "../header/Validation.h"

#include <iostream>
#include <string>

using namespace std;

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