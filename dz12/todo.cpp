#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    double height;
    string internationalPassportNumber;
    int age;

public:
    Person(const string &name, double height, int age, const string &passportNumber)
        : name(name), height(height), age(age), internationalPassportNumber(passportNumber) {}

    virtual ~Person() = default;

    void sayHello() const
    {
        cout << "Hello! My name is " << name
             << ", my height is " << height << " cm, and I am "
             << age << " years old." << endl;
    }

    virtual void showDocument() const
    {
        cout << "My international passport number is: " << internationalPassportNumber << endl;
    }
};

class Tourist : public Person
{
public:
    Tourist(const string &name, double height, int age, const string &passportNumber)
        : Person(name, height, age, passportNumber) {}
};

class Driver : public Person
{
private:
    int drivingExperience;
    string licenseNumber;

public:
    Driver(const string &name, double height, int age, const string &passportNumber,
           int drivingExperience, const string &licenseNumber)
        : Person(name, height, age, passportNumber),
          drivingExperience(drivingExperience), licenseNumber(licenseNumber) {}

    void showDocument() const
    {
        Person::showDocument();
        cout << "My driver's license number is: " << licenseNumber
             << ", driving experience: " << drivingExperience << " years." << endl;
    }
};

class Scientist : public Person
{
private:
    string degree;
    string researchID;

public:
    Scientist()
        : Person("Default Scientist", 170.0, 50, "SC000000000"),
          degree("PhD in Physics"), researchID("RSCH-123456") {}

    Scientist(const string &name, double height, int age, const string &passportNumber,
              const string &degree, const string &researchID)
        : Person(name, height, age, passportNumber),
          degree(degree), researchID(researchID) {}

    void showDocument() const
    {
        Person::showDocument();
        cout << "Scientific degree: " << degree << endl;
        cout << "Researcher ID: " << researchID << endl;
    }
};

void showPersonInfo(const Person &person)
{
    person.sayHello();
    person.showDocument();
    cout << endl;
}

void showAllDocuments()
{
    // Туристи
    Tourist tourist1("Alex", 180.5, 28, "TR123456789");
    Tourist tourist2("Maria", 165.2, 32, "TR987654321");

    // Водії
    Driver driver1("John", 175.0, 35, "AB654321", 10, "DL987654321");
    Driver driver2("Kate", 160.0, 29, "CD111222", 5, "DL555666777");

    // Вчені
    Scientist scientist1;
    Scientist scientist2("Dr. Emma", 168.0, 45, "SC222333", "PhD in Chemistry", "RSCH-789012");

    // Вивід усіх
    cout << "=== Tourists ===" << endl;
    showPersonInfo(tourist1);
    showPersonInfo(tourist2);

    cout << "=== Drivers ===" << endl;
    showPersonInfo(driver1);
    showPersonInfo(driver2);

    cout << "=== Scientists ===" << endl;
    showPersonInfo(scientist1);
    showPersonInfo(scientist2);
}

int main()
{
    showAllDocuments();
    return 0;
}
