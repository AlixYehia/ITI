#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d = 0, int m = 0, int y = 0)
    {
        day = d;
        month = m;
        year = y;
    }

    // Print the date
    void printDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }

    // Operator overload for difference between dates
    int operator- (Date d)
    {
        return (this-> year - d.year) * 365 + (this-> month - d.month) * 30 + (this-> day - d.day);
    }

    // Operator overload to add days to the date
    Date operator+ (int days)
    {
        Date newDate = *this;
        newDate.day += days;

        while (newDate.day > 30)
        {
            newDate.day -= 30;
            newDate.month++;
            if (newDate.month > 12)
            {
                newDate.month = 1;
                newDate.year++;
            }
        }
        return newDate;
    }

    // Prefix increment operator
    Date operator++()
    {
        day++;
        if (day > 30) { // Assuming 30 days for simplicity
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this; // Return the incremented object
    }

    // Postfix increment operator
    Date operator++ (int)
    {
        Date temp = *this; // Store the current date
        day++;
        if (day > 30)
        {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return temp;
    }

    // Assignment operator
    void operator= (Date d)
    {
        day = d.day;
        month = d.month;
        year = d.year;
    }

    // Equality operator
    bool operator== (Date d)
    {
        return (this-> day == d.day && this-> month == d.month && this-> year == d.year);
    }

    // Casting operator
    operator int() // Casting operator
    {
        return this-> year * 10000 + this-> month * 100 + this-> day; // Return an integer representation
    }

    // Indexing operator
    int operator[](char ch)
    {
        if (ch == 'd')
            return day;
        else if (ch == 'm')
            return month;
        else if (ch == 'y')
            return year;

        return -1;
    }
};

int main() {
    Date d3;

    Date d1(15, 8, 2021);
    d1.printDate();

    cout << "Testing operator+ for d1 + 10" << "\n";
    Date d2 = d1 + 10;
    d2.printDate();

    cout << "Testing prefix ++ for Date 1" << "\n";
    d3 = ++d1;
    d3.printDate();

    cout << "Testing postfix ++ for Date 1" << "\n";
    d3 = d1++;
    d3.printDate();

    cout << "Difference d2 - d1: " << d2 - d1 << " days" << endl;

    cout << "Testing operator==" << "\n";
    if (d1 == d2)
    {
        cout << "Dates are equal." << endl;
    } else
    {
        cout << "Dates are not equal." << endl;
    }

    cout << "Testing operator[] for extracting each part of date for Date 1" << "\n";
    cout << "Year: " << d1['y'] << ", Month: " << d1['m'] << ", Day: " << d1['d'] << endl;

    // Using the casting operator
    int x = (int)d1; // Convert d1 to an integer
    cout << "Integer representation of Date 1: " << x << endl;

    return 0;
}
