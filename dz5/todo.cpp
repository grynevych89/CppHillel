#include <iostream>
#include <cmath>

using namespace std;

void printPoem()
{
        cout << "Hickory, dickory, dock,\n";
        cout << "The mouse ran up the clock;\n";
        cout << "The clock struck one,\n";
        cout << "And down he run,\n";
        cout << "Hickory, dickory, dock.\n\n";
}

void SetAlarm(int dayOfWeek, int month)
{
    bool isWeekend = (dayOfWeek == 6 || dayOfWeek == 7); // Субота або неділя
    bool isVacation = (month == 7 || month == 10);       // Липень або жовтень (відпустка)

    if (isVacation)
    {
        if (isWeekend)
        {
            cout << "off" << endl; // Відпустка і вихідний — будильник вимкнено
        }
        else
        {
            cout << "10:00" << endl; // Відпустка, але робочий день — будильник на 10:00
        }
    }
    else
    {
        if (isWeekend)
        {
            cout << "10:00" << endl; // Вихідний день (але не відпустка) — будильник на 10:00
        }
        else
        {
            cout << "07:00" << endl; // Робочий день — будильник на 07:00
        }
    }
}

void EvaluateParty(int cakes, int teaCups)
{
    if (cakes < 5 || teaCups < 5)
    {
        cout << "Boring" << endl; // Якщо менше 5 тістечок або чаю — нудно
    }
    else if (teaCups >= 2 * cakes || cakes >= 2 * teaCups)
    {
        cout << "Excellent" << endl; // Якщо чаю вдвічі більше за тістечка або навпаки — чудово
    }
    else
    {
        cout << "Good" << endl; // Інакше — добре
    }
}

bool IsLucky(int num1, int num2)
{
    return (num1 == 7 || num2 == 7 || num1 + num2 == 7 || abs(num1 - num2) == 7);
}

void CheckLuck(int num1, int num2)
{
    if (IsLucky(num1, num2))
    {
        cout << "You are lucky!" << endl;
    }
    else
    {
        cout << "Better luck next time!" << endl;
    }
}

int main()
{
    printPoem();
    printPoem();
    printPoem();
    printPoem();

    SetAlarm(5, 4); // Звичайний робочий день
    SetAlarm(6, 4); // Вихідний, не в відпустці
    SetAlarm(6, 7); // Вихідний у відпустці (будильник вимкнено)
    SetAlarm(3, 10); // Робочий день у відпустці (будильник на 10:00)

    cout << endl;
    
    EvaluateParty(3, 10);  // Нудно (тістечок менше 5)
    EvaluateParty(5, 5);   // Добре
    EvaluateParty(10, 20); // Чудово (чаю вдвічі більше)
    EvaluateParty(6, 5);   // Добре
    EvaluateParty(20, 10); // Чудово (тістечок вдвічі більше)

    cout << endl;

    CheckLuck(22, 15);
    CheckLuck(8, 1);
    CheckLuck(9, 1);

    return 0;
}
