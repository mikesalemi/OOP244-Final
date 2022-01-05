/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 15, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H

#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
    class Patient : public IOAble {
        char* m_name;
        int m_numOHIP;
        Ticket* m_ticket;
        bool m_fileIO;
    public:
        Patient(int ticketNum = 0, bool fileIO = false);
        virtual ~Patient();
        virtual char type()const = 0;
        bool fileIO()const;
        bool fileIO(bool fileIO);
        bool operator==(char letter)const;
        bool operator==(const Patient& patient)const;
        void setArrivalTime();
        operator Time()const;
        int number()const;
        ostream &csvWrite(ostream &ostream1) const override;
        istream &csvRead(istream &istream1) override;
        ostream &write(ostream &ostream1) const override;
        istream &read(istream &istream1) override;
    };
}


#endif //SDDS_PATIENT_H