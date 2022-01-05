/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds {
    void Menu::display() const {
        cout << m_text << endl;
    }

    Menu::Menu(const char *menuContent, int noOfSelections) {
        m_text = new char[strlen(menuContent) + 1];
        strcpy(m_text, menuContent);
        m_noOfSel = noOfSelections;
    }

    Menu::Menu(Menu &menu) {
        if (menu.m_text != nullptr) {
            m_text = new char[strlen(menu.m_text) + 1];
            strcpy(m_text, menu.m_text);
            m_noOfSel = menu.m_noOfSel;
        }
    }

    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }

    int &Menu::operator>>(int& selection) {
        display();
        cout << "0- Exit" << endl;
        selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
        return selection;
    }

    Menu &Menu::operator=(Menu &menu) {
        if(menu.m_text != nullptr) {
            delete[] m_text;
            m_text = new char[strlen(menu.m_text) + 1];
            strcpy(m_text,menu.m_text);
            m_noOfSel = menu.m_noOfSel;
        }
        return *this;
    }
}
