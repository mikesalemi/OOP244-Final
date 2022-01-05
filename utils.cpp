/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"

using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getInt(const char *prompt) {
        int num;
        bool isValid = false;
        if (prompt) {
            cout << prompt;
        }
        while (!isValid) {
            cin >> num;
            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
            } else if (cin.peek() != '\n') {
                cout << "Enter only an integer, try again: ";
            } else {
                isValid = true;
            }
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return num;
    }

    int getInt(int min, int max, const char *prompt,const char* errorMessage, bool showRangeAtError) {
        int num;
        bool isValid = false;
        if (prompt) {
            cout << prompt;
        }
        while (!isValid) {
            num = getInt();
            if (num < min || num > max) {
                cout << errorMessage;
                if (showRangeAtError) {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
            } else {
                isValid = true;
            }
        }
        return num;
    }

    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invalid time, try again (HH:MM): ";
                    cin.clear();
                } else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        } else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    char *getcstr(const char *prompt, istream &istr, char delimiter) {
        if (prompt) {
            cout << prompt;
        }
        string str;
        getline(cin, str, delimiter);
        char* chrArr = new char[str.length()+1];
        strcpy(chrArr,str.c_str());
        return chrArr;
    }
}