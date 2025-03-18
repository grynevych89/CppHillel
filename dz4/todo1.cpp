#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int hours, minutes;

    while (true)
    {
        cout << "Enter time (hours minutes): ";
        cin >> hours >> minutes;

        if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
        {
            break;
        }

        cout << "Invalid time input! Try again." << endl;
    }

    minutes++;

    if (minutes == 60)
    {
        minutes = 0;
        hours++;
        if (hours == 24)
        {
            hours = 0;
        }
    }

    printf("%02d:%02d\n", hours, minutes);

    return 0;
}
