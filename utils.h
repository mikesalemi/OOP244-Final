/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>

namespace sdds {
    extern bool debug; // making sdds::debug variable global to all the files
    // which include: "utils.h"
    int getInt(const char *prompt = nullptr);

    int getInt(int min, int max, const char *prompt = nullptr, const char *errorMessage = nullptr,
               bool showRangeAtError = true);

    int getTime(); // returns the time of day in minutes
    char *getcstr(const char *prompt = nullptr,   // User entry prompt
                  std::istream &istr = std::cin,  // the Stream to read from
                  char delimiter = '\n');         // Delimiter to mark the end of data
    template<typename type>
    void removeDynamicElement(type *array[], int index, int &size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }

}
#endif // !SDDS_UTILS_H_
