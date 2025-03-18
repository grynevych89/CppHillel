#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int day, month;

    while (true)
    {
        cout << "Enter day of week and month: ";
        cin >> day >> month;

        if (day >= 1 && day <= 7 && month >= 1 && month <= 12)
        {
            break;
        }

        cout << "Invalid input! Try again." << endl;
    }

    bool isWeekend = (day == 6 || day == 7);
    bool isVacation = (month == 7 || month == 10);

    if (isVacation && isWeekend)
    {
        cout << "off" << endl;
    }
    else if (isVacation || isWeekend)
    {
        printf("10:00\n");
    }
    else
    {
        printf("07:00\n");
    }

    return 0;
}
