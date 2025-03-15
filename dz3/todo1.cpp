#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double celsius, kelvin, fahrenheit;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    kelvin = celsius + 273.15;
    fahrenheit = (celsius * 9.0 / 5.0) + 32;

    printf("----------------------------------------------\n");
    printf("Temperature in Celsius: %.2f\n", celsius);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f\n", kelvin);

    return 0;
}
