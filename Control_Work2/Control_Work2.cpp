//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

// Абстрактний клас, що характеризує фігуру
class figure {
protected:
    double area{}; // Площа фігури

public:
    void show() { // Функція для виводу всіх даних щодо об'єкту
        calculate();
        info();
    }

    // Оголошуємо чисті віртуальні функції
    virtual void info() = 0; // Функція для виведення інформації щодо об'єкту
    virtual void calculate() = 0; // Функція для проведення розрахунків щодо об'єкту

    virtual ~figure() {} // Створюємо віртуальний деструктор
};

// Клас, що характеризує прямокутник
class rectangle : public figure {
private:
    double length{}; // Довжина прямокутника
    double width{}; // Ширина прямокутника

public:
    rectangle() {}

    rectangle(double len, double wid) : length(len), width(wid) {}

    void info() override { // Перевантажена функція для виводу інформації щодо об'єкту
        cout << "Інформація щодо прямокутника: " << endl;
        cout << fixed << setprecision(2) << "Довжина: " << length << " см" << endl;
        cout << "Ширина: " << width << " см" << endl;
        cout << "Площа: " << area << " см^2" << endl;
    }

    void calculate() override { // Перевантажена функція для проведення розрахунків щодо об'єкту
        area = length * width;
    }

    bool operator > (const rectangle& other) const { // Перевантаження оператора > для порівняння площ прямокутників
        return area > other.area;
    }

    friend istream& operator >> (istream&, rectangle&); // Перевантаження оператора >> для введення даних про прямокутник
};

// Клас, що характеризує паралелограм
class parallelogram : public figure {
private:
    double length{}; // Довжина паралелограма
    double height{}; // Висота паралелограма

public:
    parallelogram() {}

    parallelogram(double len, double hg) : length(len), height(hg) {}

    void info() override { // Перевизначення функції для виводу інформації щодо об'єкту
        cout << "Інформація щодо паралелограма: " << endl;
        cout << fixed << setprecision(2) << "Довжина: " << length << " см" << endl;
        cout << "Висота: " << height << " см" << endl;
        cout << "Площа: " << area << " см^2" << endl;
    }

    void calculate() override { // Перевизначення функції для проведення розрахунків щодо об'єкту
        area = length * height;
    }

    bool operator > (const parallelogram& other) const { // Перевантаження оператора > для порівняння площ паралелограмів
        return area > other.area;
    }

    friend istream& operator >> (istream&, parallelogram&); // Перевантаження оператора >> для введення даних про паралелограм
};

istream& operator >> (istream& stream, rectangle& rect) {
    cout << "Введіть дані для прямокутника: " << endl;
    cout << "Довжина: ";
    stream >> rect.length;
    cout << "Ширина: ";
    stream >> rect.width;

    return stream;
}

istream& operator >> (istream& stream, parallelogram& par) {
    cout << "Введіть дані для паралелограма: " << endl;
    cout << "Довжина: ";
    stream >> par.length;
    cout << "Висота: ";
    stream >> par.height;

    return stream;
}

int main()
{
    // Працюємо з масивом паралелограмів
    const int parallelogramNum = 3;
    parallelogram parallelograms[parallelogramNum];

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Введення даних для об'єктів класу паралелограмів через перевантажений оператор >>
    for (int i = 0; i < parallelogramNum; i++) {
        cout << "Введіть дані для паралелограма[" << i << "]: " << endl;
        cin >> parallelograms[i];
        cout << endl;
    }

    // Порівняння об'єктів та виведення результатів
    for (int i = 1; i < parallelogramNum; i++) {
        std::cout << "Порівняння об'єкту [" << i - 1 << "] та [" << i << "]: " << endl << endl;;
        parallelograms[i - 1].show();
        cout << endl;
        parallelograms[i].show();
        cout << endl << "Об'єкт [" << i - 1 << "] більший за [" << i << "]: " << boolalpha << (parallelograms[i - 1] > parallelograms[i]) << endl; // Показ роботи перевизначеного оператору >
        std::cout << "-----------------------------------------" << endl;
    }

    // Працюємо з класом прямокутника через покажчики
    rectangle rect;
    figure* rect_pointer = &rect;

    cout << endl << "Демонстрація роботи з об'єктом прямокутника через покажчик на базовий клас фігура: " << endl;
    cin >> rect; // Введення даних до об'єкту прямокутника через перевантажений оператор >>
    cout << endl;
    rect_pointer->show(); 
}
