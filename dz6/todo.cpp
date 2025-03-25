#include <iostream>
#include <cstdlib>
#include <ctime>

// #1 Функція для виводу 10 випадкових чисел у заданому діапазоні
void printRandomNumbers(int min, int max)
{
    std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел

    int count = 0;
    while (count < 10)
    {
        std::cout << (std::rand() % (max - min + 1) + min) << std::endl;
        count++;
    }
}

// #2 Функція для виведення чисел від заданого значення до 1
void printNumbersDescending(int start)
{
    while (start >= 1)
    {
        std::cout << start << " ";
        start--;
    }
    std::cout << std::endl;
}

// #3 Функція множить число на 2, доки воно не стане більше 10000
void multiplyUntilLimit(int number)
{
    int steps = 0;

    while (number <= 10000)
    {
        std::cout << number << std::endl;
        number *= 2;
        steps++;
    }
    // Вивести останнє число та останній крок, якщо воно перевищує 10000
    std::cout << number << std::endl;
    steps++;
    std::cout << "Steps: " << steps << std::endl;
}

int main()
{
    printRandomNumbers(0, 20); // Виклик функції з діапазоном [0, 20]
    std::cout << std::endl;
    printNumbersDescending(27); // Виводить числа від 'n' до 1
    std::cout << std::endl;
    multiplyUntilLimit(173); // Виклик функції з початковим числом
    return 0;
}
