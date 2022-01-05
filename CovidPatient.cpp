/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 26, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "CovidPatient.h"

namespace sdds {
    int nextCovidTicket = 1;

    CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
        nextCovidTicket++;
    }

    char CovidPatient::type() const {
        return 'C';
    }

    istream &CovidPatient::csvRead(istream &is) {
        Patient::csvRead(is);
        nextCovidTicket = number() + 1;
        is.ignore(1000,'\n');
        return is;
    }

    istream &CovidPatient::read(istream &is) {
        if (fileIO()) {
            csvRead(is);
        } else {
            Patient::read(is);
        }
        return is;
    }

    ostream &CovidPatient::write(ostream &os) const {
        if (fileIO()) {
            Patient::csvWrite(os);
        } else {
            os << "COVID TEST" << endl;
            Patient::write(os) << endl;
        }
        return os;
    }
}