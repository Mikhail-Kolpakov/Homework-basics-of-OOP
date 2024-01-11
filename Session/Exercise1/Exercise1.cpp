// Варіант #12
#define _USE_MATH_DEFINES
#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

// Абстрактний клас, що характеризує просторову фігуру
class Figure {
public:
    // Чисті віртуальні функції
    virtual void inputData() = 0;
    virtual double calculateVolume() const = 0;
    virtual double calculateSurfaceArea() const = 0;
    virtual void displayInfo() const = 0;
};

// Клас, що характеризує паралелепіпед
class Parallelepiped : public Figure {
private:
    double length{}; // Довжина
    double width{}; // Ширина
    double height{}; // Висота

public:
    void inputData() override {
        cout << "Введіть значення для вимірів паралелепіпеда: " << endl;
        cout << "Введіть довжину: ";
        cin >> length;
        cout << "Введіть ширину: ";
        cin >> width;
        cout << "Введіть висоту: ";
        cin >> height;
    }

    double calculateVolume() const override { // Перевантажений метод для розрахунку об'єму
        return length * width * height;
    }

    double calculateSurfaceArea() const override { // Перевантажений метод для розрахунку площі
        return 2 * (length * width + width * height + height * length);
    }

    void displayInfo() const override { // Перевантажений метод для виводу інформації до консолі
        cout << endl << "Паралелепіпед:" << endl;
        cout << "Об'єм: " << calculateVolume() << " см^3" << endl;
        cout << "Площа: " << calculateSurfaceArea() << " см^2" << endl;
    }
};

// Клас, що характеризує циліндр
class Cylinder : public Figure {
private:
    double radius{}; // Радіус
    double height{}; // Висота

public:
    void inputData() override {
        cout << "Введіть значення для вимірів циліндра: " << endl;
        cout << "Введіть радіус: ";
        cin >> radius;
        cout << "Введіть висоту: ";
        cin >> height;
    }

    double calculateVolume() const override { // Перевантажений метод для розрахунку об'єму
        return M_PI * pow(radius, 2) * height;
    }

    double calculateSurfaceArea() const override { // Перевантажений метод для розрахунку площі
        return 2 * M_PI * radius * (radius + height);
    }

    void displayInfo() const override { // Перевантажений метод для виводу інформації до консолі
        cout << endl << "Циліндр:" << endl;
        cout << "Об'єм: " << calculateVolume() << " см^3" << endl;
        cout << "Площа: " << calculateSurfaceArea() << " см^2" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Використовуємо покажчики базового класу для роботи з об'єктами обох класів
    Figure* figure1 = new Parallelepiped();
    figure1->inputData();
    figure1->displayInfo();
    delete figure1;

    cout << endl;

    Figure* figure2 = new Cylinder();
    figure2->inputData();
    figure2->displayInfo();
    delete figure2;
}
