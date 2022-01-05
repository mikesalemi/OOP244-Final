/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "IOAble.h"

namespace sdds {
    IOAble::~IOAble() {/*empty*/ }

    ostream &operator<<(ostream & os, IOAble &ioable) {
        ioable.write(os);
        return os;
    }

    istream &operator>>(istream &is, IOAble &ioable) {
        ioable.read(is);
        return is;
    }
}

