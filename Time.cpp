/*
 * Michael Salemi
 * 042597146
 * msalemi4@myseneca.ca
 * July 12, 2021
 *I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time &Time::setToNow() {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min) {
        m_min = min;
    }

    std::ostream &Time::write(ostream &ostr) const {
        int hours = m_min/60;
        int mins = m_min%60;
        ostr.fill('0');
        ostr.width(2);
        ostr << hours;
        ostr << ":";
        ostr.width(2);
        ostr << mins;
        return ostr;
    }

    std::istream &Time::read(istream &istr) {
        int hours = 0;
        int mins = 0;
        istr >> hours;
        if (istr.good()) {
            if (istr.get() != ':') {
                istr.setstate(ios::failbit);
            } else {
                istr >> mins;
            }
            if (hours < 0 || mins < 0 || (istr.peek() != '\n' && istr.peek() != ',')) {
                istr.setstate(ios::failbit);
            }
        }
        if (istr.good()) {
            hours *= 60;
            mins += hours;
            m_min = mins;
        }
        return istr;
    }

    Time &Time::operator-=(const Time &D) {
        int totalMins = m_min - D.m_min;
        while (totalMins < 0) {
            totalMins += 1440;
        }
        m_min = totalMins;
        return *this;
    }

    Time Time::operator-(const Time &D) const {
        int totalMins = m_min - D.m_min;
        while (totalMins < 0) {
            totalMins += 1440;
        }
        return Time(totalMins);
    }

    Time &Time::operator+=(const Time &D) {
        m_min += D.m_min;
        return *this;
    }

    Time Time::operator+(const Time &D) const {
        int totalMins = m_min + D.m_min;
        return Time(totalMins);
    }

    Time &Time::operator=(unsigned int val) {
        m_min = val;
        return *this;
    }

    Time &Time::operator*=(unsigned int val) {
        m_min *= val;
        return *this;
    }

    Time &Time::operator/=(unsigned int val) {
        m_min /= val;
        return *this;
    }

    Time Time::operator*(unsigned int val) const {
        int totalMins = m_min * val;
        return Time(totalMins);
    }

    Time Time::operator/(unsigned int val) const {
        int totalMins = m_min / val;
        return Time(totalMins);
    }

    Time::operator unsigned int() const {
        return m_min;
    }

    Time::operator int() const {
        return m_min;
    }

    std::ostream &operator<<(ostream &ostr, const Time &D) {
        D.write(ostr);
        return ostr;
    }

    std::istream &operator>>(istream &istr, Time &D) {
        D.read(istr);
        return istr;
    }
}