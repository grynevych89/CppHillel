#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void processNumbers()
{
    std::vector<int> numbers(5);

    std::cout << "Enter 5 numbers: ";
    for (int &num : numbers)
    {
        std::cin >> num;
    }

    std::cout << "Numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    std::cout << "\nNumbers in reverse: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

void printMultiplicationTable()
{
    // Виведення таблиці для чисел 1 до 5
    for (int row = 1; row <= 10; ++row)
    {
        for (int col = 1; col <= 5; ++col)
        {
            std::cout << col << "x" << row << "=" << (col * row) << "\t";
        }
        std::cout << std::endl; // Перехід на новий рядок після кожного ряду
    }

    std::cout << std::endl; // Пустий рядок між двома блоками таблиці

    // Виведення таблиці для чисел 6 до 10
    for (int row = 1; row <= 10; ++row)
    {
        for (int col = 6; col <= 10; ++col)
        {
            std::cout << col << "x" << row << "=" << (col * row) << "\t";
        }
        std::cout << std::endl; // Перехід на новий рядок після кожного ряду
    }
}

bool hasSameDigits(int num)
{
    std::string strNum = std::to_string(num);
    return std::all_of(strNum.begin(), strNum.end(), [&](char digit)
                       { return digit == strNum[0]; });
}

bool isBeautifulNumber(int num)
{
    return (num >= 70 && num <= 500 && num % 3 == 0 && num % 8 != 0) || (num >= 70 && hasSameDigits(num));
}

int getBeautifulNumber()
{
    int num;
    do
    {
        std::cout << "Enter a beautiful number: ";
        std::cin >> num;
        if (!isBeautifulNumber(num))
            std::cout << num << " is not a beautiful number! Please enter another." << std::endl;
    } while (!isBeautifulNumber(num));
    return num;
}

double calculateAverage(int count)
{
    double sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += getBeautifulNumber();
    }
    return sum / count;
}

void processBeautifulNumbers()
{
    std::cout << "Average: " << calculateAverage(4) << std::endl;
}

void drawTree(int levels)
{
    for (int i = 1; i <= levels; ++i)
    {
        // Малюємо зірочки
        for (int j = 0; j < i; ++j)
        {
            std::cout << "*";
        }
        // Малюємо плюси
        for (int j = 0; j < i; ++j)
        {
            std::cout << "+";
        }
        std::cout << std::endl;
    }
}

void inputAndDrawTree()
{
    int levels;
    std::cout << "Enter the number of levels for the tree: ";
    std::cin >> levels;
    drawTree(levels);
}

int generatePokemons()
{
    return rand() % 4 + 3; // Від 3 до 6
}

void playRaceRound(int &goal, int &scoreJay, int &scoreBob)
{
    int jayTotal = 0, bobTotal = 0;
    int day = 1;

    std::cout << "\nNew race started! Goal: " << goal << " pokemons\n";

    while (jayTotal < goal && bobTotal < goal)
    {
        int jayCaught = generatePokemons();
        int bobCaught = generatePokemons();
        jayTotal += jayCaught;
        bobTotal += bobCaught;

        std::cout << "Day " << day++ << ":\n";
        std::cout << "  Jay caught " << jayCaught << " (total: " << jayTotal << ")\n";
        std::cout << "  Bob caught " << bobCaught << " (total: " << bobTotal << ")\n\n";
    }

    if (jayTotal >= goal && bobTotal >= goal)
    {
        std::cout << "It's a tie! They decided to rematch. Competition goal is " << goal << ".\n";
    }
    else if (jayTotal >= goal)
    {
        ++scoreJay;
        goal = static_cast<int>(goal * 1.5);
        std::cout << "Jay wins! Bob demands rematch! Competition goal is now " << goal << ".\n";
        }
    else
    {
        ++scoreBob;
        goal = static_cast<int>(goal * 1.5);
        std::cout << "Bob wins! Jay demands rematch! Competition goal is now " << goal << ".\n";
    }
}

void startPokemonCompetition()
{
    srand(static_cast<unsigned int>(time(0)));

    int goal;
    std::cout << "Enter the starting competition goal: ";
    std::cin >> goal;

    int scoreJay = 0, scoreBob = 0;

    while (scoreJay < 3 && scoreBob < 3)
    {
        playRaceRound(goal, scoreJay, scoreBob);
    }

    std::cout << "\nFinal Result:\n";
    if (scoreJay == 3)
        std::cout << "Jay wins the competition!\n";
    else
        std::cout << "Bob wins the competition!\n";
}

int main()
{
    // processNumbers();
    // printMultiplicationTable();
    // processBeautifulNumbers();
    // inputAndDrawTree();
    startPokemonCompetition();
    return 0;
}
