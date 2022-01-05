/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 20, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {
    class TriagePatient : public Patient{
        char* m_symptoms;
    public:
        TriagePatient();
        ~TriagePatient();
        char type() const override;

        ostream &csvWrite(ostream &ostream1) const override;

        istream &csvRead(istream &istream1) override;

        ostream &write(ostream &ostream1) const override;

        istream &read(istream &istream1) override;
    };
}

#endif //SDDS_TRIAGEPATIENT_H
