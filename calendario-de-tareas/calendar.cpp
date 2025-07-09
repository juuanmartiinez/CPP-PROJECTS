#include "calendar.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

namespace Calendar {

    // Verifica formato YYYY-MM-DD 
    bool isValidate(const string& date) {
        if (date.length() != 10 || date[4] != '-' || date[7] != '-')
            return false;

        int year, month, day;
        char dash1, dash2;
        stringstream ss(date);
        ss >> year >> dash1 >> month >> dash2 >> day;

        if (ss.fail() || dash1 != '-' || dash2 != '-')
            return false;

        if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
            return false;

        //(no incluye años bisiestos)
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
            daysInMonth[1] = 29;

        return day <= daysInMonth[month - 1];
    }

    // Retorna la fecha actual
    string getToday() {
        time_t now = time(0);
        tm* local = localtime(&now);
        stringstream ss;
        ss << put_time(local, "%Y-%m-%d");
        return ss.str();
    }

}
