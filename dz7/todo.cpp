#include <iostream>
#include <cstdlib>
#include <ctime>

bool isValidYear(int year)
{
    if (year < 1600)
    {
        std::cout << "Year must be 1600 or greater." << std::endl;
        return false;
    }
    return true;
}

bool isValidMonth(int month)
{
    if (month < 1 || month > 12)
    {
        return false;
    }
    return true;
}

int getDaysInMonthByYear(int month, int year)
{
    if (month == 2)
    {
        // Перевірка на високосний рік для лютого
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 29; // Високосний рік
        }
        else
        {
            return 28; // Не високосний рік
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

bool isValidDate(int day, int month, int year)
{
    if (!isValidYear(year))
    {
        return false;
    }

    if (!isValidMonth(month))
    {
        return false;
    }

    int daysInMonth = getDaysInMonthByYear(month, year);
    return (day >= 1 && day <= daysInMonth);
}

int getDaysInMonth(int month)
{
    // Передбачається, що рік 2025
    return getDaysInMonthByYear(month, 2025);
}

void printDaysInMonth()
{
    int month;
    std::cout << "Enter month number (1-12): ";
    std::cin >> month;

    if (!isValidDate(1, month, 2025))
    {
        std::cout << "Invalid date!" << std::endl;
        return;
    }

    int days = getDaysInMonth(month);
    std::cout << "Days in month: " << days << std::endl;
}

void printNextDates(int day, int month, int year, int numberOfDays)
{
    if (!isValidDate(day, month, year))
    {
        std::cout << "Invalid date!" << std::endl;
        return;
    }

    for (int i = 0; i < numberOfDays; ++i)
    {
        std::cout << (day < 10 ? "0" : "") << day << "." << (month < 10 ? "0" : "") << month << "." << year << std::endl;

        ++day;

        // Перевірка дня в місяці
        int daysInMonth = getDaysInMonthByYear(month, year);

        if (day > daysInMonth)
        {
            day = 1;
            month++;

            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }
}

void inputAndPrintNextDates()
{
    int day, month, year, numberOfDays;
    std::cout << "Enter date (day month year): ";
    std::cin >> day >> month >> year;
    std::cout << "Enter number of days: ";
    std::cin >> numberOfDays;

    printNextDates(day, month, year, numberOfDays);
}

void printMultiplicationTable()
{
    for (int i = 1; i <= 10; i++)
    {
        std::cout << "4 x " << i << " = " << (4 * i) << std::endl;
    }
}

void simulatePokemonCompetition()
{
    std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел
    int bobTotal = 0, jayTotal = 0;

    for (int day = 1; day <= 7; day++)
    {
        int bobCaught = 3 + std::rand() % 4; // Випадкове число від 3 до 6
        int jayCaught = 3 + std::rand() % 4; // Випадкове число від 3 до 6

        bobTotal += bobCaught;
        jayTotal += jayCaught;

        std::cout << "Day " << day << "\n";
        std::cout << "Bob caught " << bobCaught << " pokemons (now he has " << bobTotal << ")\n";
        std::cout << "Jay caught " << jayCaught << " pokemons (now he has " << jayTotal << ")\n\n";
    }

    std::cout << "Bob got " << bobTotal << " pokemons\n";
    std::cout << "Jay got " << jayTotal << " pokemons\n";

    if (bobTotal > jayTotal)
    {
        std::cout << "Bob wins!\n";
    }
    else if (jayTotal > bobTotal)
    {
        std::cout << "Jay wins!\n";
    }
    else
    {
        std::cout << "It is a tie.\n";
    }
}

void simulatePokemonRace()
{
    srand(time(0));
    int bobTotal = 0, jayTotal = 0;
    int bet;

    std::cout << "Enter your bet:\n1 - Jay\n2 - Bob\n";
    std::cin >> bet;
    std::cout << "You have chosen " << (bet == 1 ? "Jay" : "Bob") << ".\n\n";

    int day = 1;
    while (bobTotal < 90 && jayTotal < 90)
    {
        int bobCaught = rand() % 4 + 3;
        int jayCaught = rand() % 4 + 3;

        bobTotal += bobCaught;
        jayTotal += jayCaught;

        std::cout << "Day " << day << "\n";
        std::cout << "Bob caught " << bobCaught << " pokemons (now he has " << bobTotal << ")\n";
        std::cout << "Jay caught " << jayCaught << " pokemons (now he has " << jayTotal << ")\n\n";

        day++;
    }

    std::cout << "Bob got " << bobTotal << " pokemons\n";
    std::cout << "Jay got " << jayTotal << " pokemons\n";

    if (bobTotal >= 90 && jayTotal >= 90)
    {
        std::cout << "It is a tie.\n";
        std::cout << "You lost the bet!\n";
    }
    else if (bobTotal >= 90)
    {
        std::cout << "Bob wins!\n";
        if (bet == 2)
            std::cout << "You won the bet!\n";
        else
            std::cout << "You lost the bet!\n";
    }
    else
    {
        std::cout << "Jay wins!\n";
        if (bet == 1)
            std::cout << "You won the bet!\n";
        else
            std::cout << "You lost the bet!\n";
    }
}

int main()
{
    printMultiplicationTable();
    std::cout << "------------------------------------------------" << std::endl;

    printDaysInMonth();
    std::cout << "------------------------------------------------" << std::endl;

    simulatePokemonCompetition();
    std::cout << "------------------------------------------------" << std::endl;

    simulatePokemonRace();
    std::cout << "------------------------------------------------" << std::endl;

    inputAndPrintNextDates();
    std::cout << "------------------------------------------------" << std::endl;

    return 0;
}
