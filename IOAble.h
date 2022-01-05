/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

using namespace std;

namespace sdds {
    class IOAble {
    public:
        virtual ostream &csvWrite(ostream &) const = 0;

        virtual istream &csvRead(istream &) = 0;

        virtual ostream &write(ostream &) const = 0;

        virtual istream &read(istream &) = 0;

        virtual ~IOAble();

    };

    ostream &operator<<(ostream &os, IOAble& ioable);

    istream &operator>>(istream &is, IOAble& ioable);

}

#endif //SDDS_IOABLE_H