#include <iostream>
#include <vector>
#include <cmath>

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
    char firstDigit = std::to_string(num)[0];
    for (char digit : std::to_string(num))
    {
        if (digit != firstDigit)
            return false;
    }
    return true;
}

bool isBeautifulNumber(int num)
{
    return (num >= 70 && num <= 500 && num % 3 == 0 && num % 8 != 0) || (num >= 70 && hasSameDigits(num)); 
}

int getBeautifulNumber()
{
    int num;
    while (true)
    {
        std::cout << "Enter a beautiful number: ";
        std::cin >> num;
        if (isBeautifulNumber(num))
            return num;
        std::cout << num << " is not a beautiful number! Please enter another." << std::endl;
    }
}

void processBeautifulNumbers()
{
    std::vector<int> numbers;
    for (int i = 0; i < 4; ++i)
    {
        numbers.push_back(getBeautifulNumber());
    }

    double sum = 0;
    for (int num : numbers)
        sum += num;

    std::cout << "Average: " << sum / numbers.size() << std::endl;
}

void drawTree(int levels)
{
    for (int i = 1; i <= levels; ++i)
    {
        // Малюємо кожен рівень ялинки
        for (int j = 1; j <= levels - i; ++j)
        {
            std::cout << " "; // Відступи для симетрії
        }
        for (int j = 1; j <= 2 * i - 1; ++j)
        {
            std::cout << "*"; // Зірочки
        }
        std::cout << std::endl;
    }

    // Малюємо стовпчик ялинки
    for (int i = 0; i < levels - 1; ++i)
    {
        std::cout << " "; // Відступи для стовпчика
    }
    std::cout << "*" << std::endl;
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

    std::cout << "Enter the scores for " << player1 << " and " << player2 << ": ";
    std::cin >> player1Score >> player2Score;

    if (player1Score > player2Score)
    {
        score1++;
        std::cout << player1 << " wins! " << player2 << " demands rematch! Competition goal is now " << goal * 1.5 << ".\n";
    }
    else if (player2Score > player1Score)
    {
        score2++;
        std::cout << player2 << " wins! " << player1 << " demands rematch! Competition goal is now " << goal * 1.5 << ".\n";
    }
    else
    {
        std::cout << "It's a tie. They decided to rematch. Competition goal is " << goal << ".\n";
    }

    goal = static_cast<int>(goal * 1.5);
}

void startCompetition()
{
    int goal;
    std::cout << "Enter the starting goal: ";
    std::cin >> goal;

    int scoreJay = 0, scoreBob = 0;

    while (scoreJay < 3 && scoreBob < 3)
    {
        playRound("Jay", "Bob", goal, scoreJay, scoreBob);
    }

    if (scoreJay == 3)
        std::cout << "Jay wins! He is the final winner!\n";
    else
        std::cout << "Bob wins! He is the final winner!\n";
}



int main()
{
    // processNumbers();
    // printMultiplicationTable();
    // processBeautifulNumbers();
    // inputAndDrawTree();
    // startCompetition();
    return 0;
}
