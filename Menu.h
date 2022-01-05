/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_MENU_H
#define SDDS_MENU_H


namespace sdds {
    class Menu{
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu(const char* menuContent, int noOfSelections);
        virtual ~Menu();
        int& operator>>(int& selection);
        // add safe copying logic
        Menu(Menu& menu);
        Menu& operator=(Menu& menu);
    };
}


#endif //SDDS_MENU_H
