/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 27, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds {

    PreTriage::PreTriage(const char *dataFilename) :
            m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
            m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        load();
    }

    PreTriage::~PreTriage() {
        ofstream file(m_dataFilename);

        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: ";
        m_averCovidWait.write(cout) << endl;
        m_averCovidWait.write(file);
        file << ',';
        cout << "   Triage: ";
        m_averTriageWait.write(cout) << endl;
        m_averTriageWait.write(file) << endl;

        cout << "Saving m_lineup..." << endl;
        for (int i = 0; i < m_lineupSize; ++i) {
            m_lineup[i]->csvWrite(file) << endl;
            cout << (i + 1) << "- ";
            m_lineup[i]->csvWrite(cout) << endl;
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        cout << "done!" << endl;
    }

    void PreTriage::run() {
        int selection;
        do {
            m_appMenu >> selection;
            if (selection == 1) {
                reg();
            } else if (selection == 2) {
                admit();
            }
        } while (selection != 0);
    }

    void PreTriage::reg() {
        if (m_lineupSize == maxNoOfPatients) {
            cout << "Line up full!" << endl;
        } else {
            int selection;
            m_pMenu >> selection;

            if (selection == 1) {
                m_lineup[m_lineupSize] = new CovidPatient;
            } else if (selection == 2) {
                m_lineup[m_lineupSize] = new TriagePatient;
            }

            if (selection == 1 || selection == 2) {
                m_lineup[m_lineupSize]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->fileIO(false);
                m_lineup[m_lineupSize]->read(cin);
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[m_lineupSize]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl << endl;
                m_lineupSize++;
            }
        }
    }

    void PreTriage::admit() {
        int selection;
        m_pMenu >> selection;
        char type;

        if (selection == 1) {
            type = 'C';
        } else if (selection == 2) {
            type = 'T';
        }
        if (selection != 0) {
            int first = indexOfFirstInLine(type);

            if (first != -1) {
                cout << endl << "******************************************" << endl;
                m_lineup[first]->fileIO(false);
                cout << "Calling for ";
                m_lineup[first]->write(cout);
                cout << "******************************************" << endl << endl;
                setAverageWaitTime(*m_lineup[first]);
                removePatientFromLineup(first);
            }
        }
    }

    const Time PreTriage::getWaitTime(const Patient &p) const {
        int numAhead = 0;
        int minutes;
        for (int i = 0; m_lineup[i]->number() != p.number(); i++) {
            if (m_lineup[i]->type() == p.type()) {
                numAhead++;
            }
        }
        if (p.type() == 'C') {
            minutes = int(m_averCovidWait) * numAhead;
        } else {
            minutes = int(m_averTriageWait) * numAhead;
        }
        return Time(minutes);
    }

    void PreTriage::setAverageWaitTime(const Patient &p) {
        Time currentTime;

        currentTime.setToNow();
        if (p.type() == 'C') {
            m_averCovidWait = ((int(currentTime - Time(p))) + (int(m_averCovidWait) * (p.number() - 1))) / p.number();
        } else {
            m_averTriageWait = ((int(currentTime - Time(p))) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
        }
    }

    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        int firstIndex = -1;
        for (int i = 0; i < m_lineupSize && firstIndex == -1; i++) {
            if (m_lineup[i]->type() == type) {
                firstIndex = i;
            }
        }
        return firstIndex;
    }

    void PreTriage::load() {
        m_lineupSize = 0;
        cout << "Loading data..." << endl;
        ifstream file(m_dataFilename);
        if (file) {
            m_averCovidWait.read(file);
            file.ignore();
            m_averTriageWait.read(file);
            file.ignore();
        }
        Patient *p = nullptr;
        for (int i = 0; i < maxNoOfPatients && (file.peek() == 'C' || file.peek() == 'T'); i++) {
            char type = file.get();
            file.ignore();
            if (type == 'C') {
                p = new CovidPatient;
            } else if (type == 'T') {
                p = new TriagePatient;
            }
            p->fileIO(true);
            p->csvRead(file);
            p->fileIO(false);
            m_lineup[i] = p;
            m_lineupSize++;
        }
        if (m_lineupSize == maxNoOfPatients && !file.eof()) {
            cout << "Warning: number of records exceeded " << m_lineupSize << endl;
        }
        if (m_lineupSize == 0) {
            cout << "No data or bad data file!" << endl;
        } else {
            cout << m_lineupSize << " Records imported..." << endl;
        }
        cout << endl;
    }
}