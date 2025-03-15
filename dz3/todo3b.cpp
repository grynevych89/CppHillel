#include <iostream>

using namespace std;

int main()
{
    double num1, num2, num3;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the third number: ";
    cin >> num3;

    double max = num1; // Припускаємо, що перше число найбільше

    if (num2 > max)
    {
        max = num2;
        if (num3 > max)
        {
            max = num3;
        }
    }
    else
    {
        if (num3 > max)
        {
            max = num3;
        }
    }

    cout << "The biggest number is: " << max << endl;

    return 0;
}
