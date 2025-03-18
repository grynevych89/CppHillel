#include <iostream>
using namespace std;

bool isHoliday(int day, int month)
{
    if ((month == 3 || month == 4 || month == 5 || month == 9 || month == 10 || month == 11) && day <= 3)
    {
        return true;
    }
    if ((month == 6 || month == 7 || month == 8) && day > 20)
    {
        return true;
    }
    return false;
}

int main()
{
    int day, month;

    while (true)
    {
        cout << "Enter date: ";
        cin >> day >> month;

        if (day >= 1 && day <= 31 && month >= 1 && month <= 12)
        {
            break;
        }

        cout << "Invalid input! Try again." << endl;
    }

    if (isHoliday(day, month))
    {
        cout << "This is a holiday" << endl;
    }
    else
    {
        cout << "This is not a holiday" << endl;
    }

    return 0;
}
