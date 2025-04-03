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

void playRound(const std::string &player1, const std::string &player2, int &goal, int &score1, int &score2)
{
    int player1Score, player2Score;

    std::cout << "Enter the scores for " << player1 << " and " << player2 << " (two numbers separated by space): ";

    while (!(std::cin >> player1Score >> player2Score)) // Перевірка правильності введення
    {
        std::cin.clear();             // Очистити флаг помилки
        std::cin.ignore(10000, '\n'); // Видалити некоректний ввід
        std::cout << "Invalid input. Please enter two numbers: ";
    }

    if (player1Score > player2Score)
    {
        score1++;
        goal = static_cast<int>(goal * 1.5);
        std::cout << player1 << " wins! " << player2 << " demands a rematch! New competition goal: " << goal << ".\n";
    }
    else if (player2Score > player1Score)
    {
        score2++;
        goal = static_cast<int>(goal * 1.5);
        std::cout << player2 << " wins! " << player1 << " demands a rematch! New competition goal: " << goal << ".\n";
    }
    else
    {
        std::cout << "It's a tie! They decided to rematch. Competition goal remains: " << goal << ".\n";
    }
}

void startCompetition()
{
    int goal;
    std::cout << "Enter the starting goal: ";

    while (!(std::cin >> goal)) // Перевірка правильності введення
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }

    int scoreJay = 0, scoreBob = 0;

    while (scoreJay < 3 && scoreBob < 3)
    {
        playRound("Jay", "Bob", goal, scoreJay, scoreBob);
        std::cout << "Current Score -> Jay: " << scoreJay << " | Bob: " << scoreBob << "\n\n";
    }

    if (scoreJay == 3)
        std::cout << "Jay wins the tournament! He is the final winner!\n";
    else
        std::cout << "Bob wins the tournament! He is the final winner!\n";
}

int main()
{
    processNumbers();
    printMultiplicationTable();
    processBeautifulNumbers();
    inputAndDrawTree();
    startCompetition();
    return 0;
}
