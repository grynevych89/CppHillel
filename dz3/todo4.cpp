#include <iostream>

using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    // Україна: мінімальний вік для покупки алкоголю - 18 років
    cout << "Ukraine - " << (age >= 18 ? "Yes" : "No") << endl;

    // США: мінімальний вік для покупки алкоголю - 21 рік
    cout << "USA - " << (age >= 21 ? "Yes" : "No") << endl;

    // Кувейт: алкоголь заборонено
    cout << "Kuwait - No" << endl;

    return 0;
}
