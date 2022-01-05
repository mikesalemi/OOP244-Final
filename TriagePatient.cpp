/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 26, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <iostream>
#include <cstring>
#include "TriagePatient.h"

using namespace std;
namespace sdds {
    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
        m_symptoms = nullptr;
        nextTriageTicket++;
    }

    TriagePatient::~TriagePatient() {
        delete[] m_symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    ostream &TriagePatient::csvWrite(ostream &os) const {
        Patient::csvWrite(os);
        os << ',' << m_symptoms;
        return os;
    }

    istream &TriagePatient::csvRead(istream &is) {
        delete[] m_symptoms;
        Patient::csvRead(is);
        is.ignore();
        string tmpSymptoms;
        getline(is, tmpSymptoms);
        m_symptoms = new char[strlen(tmpSymptoms.c_str()) + 1];
        strcpy(m_symptoms, tmpSymptoms.c_str());
        nextTriageTicket = number() + 1;
        return is;
    }

    ostream &TriagePatient::write(ostream &os) const {
        if (fileIO()) {
            csvWrite(os);
        } else {
            os << "TRIAGE" << endl;
            Patient::write(os) << endl;
            os << "Symptoms: " << m_symptoms << endl;
        }
        return os;
    }

    istream &TriagePatient::read(istream &is) {
        if (fileIO()) {
            csvRead(is);
        } else {
            delete[] m_symptoms;
            Patient::read(is);
            cout << "Symptoms: ";
            string tmpSymptoms;
            getline(is, tmpSymptoms, '\n');
            m_symptoms = new char[tmpSymptoms.length() + 1];
            strcpy(m_symptoms, tmpSymptoms.c_str());
        }
        return is;
    }
}