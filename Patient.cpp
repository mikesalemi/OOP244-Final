/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 15, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <cstring>
#include "Patient.h"
#include "utils.h"

namespace sdds {
    Patient::Patient(int ticketNum, bool fileIO){
        m_name = nullptr;
        m_ticket = new Ticket(ticketNum);
        m_fileIO = fileIO;
    }

    Patient::~Patient() {
        delete[] m_name;
        delete m_ticket;
    }

    bool Patient::fileIO() const {
        return m_fileIO;
    }

    bool Patient::fileIO(bool fileIO) {
        m_fileIO = fileIO;
        return fileIO;
    }

    bool Patient::operator==(char letter) const {
        return type() == letter;
    }

    bool Patient::operator==(const Patient &patient) const {
        return type() == patient.type();
    }

    void Patient::setArrivalTime() {
        m_ticket->resetTime();
    }

    Patient::operator Time() const {
        return Time(*m_ticket);
    }

    int Patient::number() const {
        return m_ticket->number();
    }

    ostream &Patient::csvWrite(ostream &ostr) const {
        ostr << type() << ',' << m_name << ',' << m_numOHIP << ',';
        m_ticket->csvWrite(ostr);
        return ostr;
    }

    istream &Patient::csvRead(istream &istr) {
        string name;
        getline(istr,name,',');
        delete[] m_name;
        m_name = new char[strlen(name.c_str()) + 1];
        strcpy(m_name, name.c_str());
        istr >> m_numOHIP;
        istr.get();
        m_ticket->read(istr);
        return istr;
    }

    ostream &Patient::write(ostream &ostr) const {
        m_ticket->write(ostr) << endl;
        for (int i = 0; i < 25 && m_name[i] != '\0'; i++) {
            ostr << m_name[i];
        }
        ostr << ", OHIP: " << m_numOHIP;

        return ostr;
    }

    istream &Patient::read(istream &istr) {
        cout << "Name: ";
        string name;
        getline(istr, name);
        m_name = new char[strlen(name.c_str()) + 1];
        strcpy(m_name, name.c_str());
        m_numOHIP = getInt(100000000,999999999,"OHIP: ", "Invalid OHIP Number, ", true);
        return istr;
    }
}