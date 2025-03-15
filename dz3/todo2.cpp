#include <iostream>

using namespace std;

int main()
{
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << ". You are " << (age >= 18 ? "old" : "young") << endl;

    return 0;
}