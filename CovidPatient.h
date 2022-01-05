/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 20, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_COVIDPATIENT_H
#define SDDS_COVIDPATIENT_H

#include "Patient.h"

namespace sdds {
    class CovidPatient : public Patient {
    public:
        CovidPatient();
        char type() const override;
        istream & csvRead(istream &is) override;
        istream & read(istream &is) override;
        ostream & write(ostream &os) const override;
    };
}


#endif //SDDS_COVIDPATIENT_H
