// Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

// Абстрактний клас, що характеризує фігуру
class shape {
public:
    virtual float area() const = 0; // Віртуальний метод для розрахунку площі фігури

    virtual ~shape() {} // Віртуальний деструктор
};

// Клас, що характеризує прямокутний трикутник
class right_triangle : public shape {
private:
    float leg1; // Перший катет
    float leg2; // Другий катет

public:
    right_triangle(float l1, float l2) : leg1(l1), leg2(l2) {
        if (l1 <= 0 || l2 <= 0)
            throw invalid_argument("Не коректні розмірності катетів для прямокутного трикутника");
    }

    float area() const override { // Перевизначений метод для обрахунку площі прямокутного трикутника
        return 0.5 * leg1 * leg2;
    }
};

// Клас, що характеризує трапецію
class trapezoid : public shape {
private:
    float base1; // Перша основа
    float base2; // Друга основа
    float height; // Висота

public:
    trapezoid(float b1, float b2, float h) : base1(b1), base2(b2), height(h) {
        if (b1 <= 0 || b2 <= 0 || h <= 0)
            throw invalid_argument("Не коректні розмірності сторін для трапеції");
    }

    float area() const override { // Перевизначений метод для обрахунку площі трапеції
        return (base1 + base2) / 2 * height;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        shape* r_triangle = new right_triangle(5, 10); // Коректний об'єкт прямокутного трикутника
        shape* trapez1 = new trapezoid(2, 6, 4); // Коректний об'єкт трапеції

		cout << "Площа (коректного) прямокутного трикутника: " << fixed << setprecision(2) << r_triangle->area() << " см^2" << endl;
        cout << "Площа (коректної) трапеції: " << trapez1->area() << " см^2" << endl;

        shape* trapez2 = new trapezoid(-5, 4, 0); // Не коректний об'єкт трапеції

        cout << "Площа (не коректної) трапеції: " << trapez2->area() << " см^2" << endl;

        // Вивільняємо ресурси
        delete r_triangle;
        delete trapez1;
        delete trapez2;
    }
    catch(const invalid_argument& e) {
        cout << "\nВиникша помилка: " << e.what() << endl;
    }
}
