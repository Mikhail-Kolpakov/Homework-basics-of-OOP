//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

//Абстрактний клас, що характеризує корабель
class ship {
protected:
    char name[MAX_NAME_LENGTH]{}; //Назва корабля
    char belong_to_country[MAX_NAME_LENGTH]{}; //Якій країні належить
    float weight{}; //Вага

public:
    //Оголошуємо чисті віртуальні функції
    virtual void input() = 0;
    virtual void output() const = 0;

    virtual ~ship() {} //Створюємо віртуальний деструктор
};

//Клас, що характеризує ректний катер
class missile_boat : public ship {
private:
    int missiles_number{}; //Кількість ракет на борту

public:
    void input() override { //Функція для введення даних
        cout << "Введіть дані для ракетного катера: " << endl;
        cout << "Назва: ";
        cin.getline(name, sizeof(name));
        cout << "Країна якій належить: ";
        cin.getline(belong_to_country, sizeof(belong_to_country));
        cout << "Вага: ";
        cin >> weight;
        cout << "Кількість ракет на борту: ";
        cin >> missiles_number;

        cin.ignore(); //Очищюємо символ нового рядка із буфера
    }

    void output() const override { //Функція для виводу даних
        cout << "Інформація щодо ракетного катера: " << endl;
        cout << "Назва: " << name << endl;
        cout << "Країна якій належить: " << belong_to_country << endl;
        cout << "Вага: " << fixed << setprecision(2) << weight << " т." << endl;
        cout << "Кількість ракет на борту: " << missiles_number << " шт." << endl;
    }
};

//Клас, що характеризує пасажирський лайнер
class passenger_boat : public ship {
private:
    int passengers_capacity{}; //Пасажиромісткість

public:
    void input() override { //Функція для введення даних
        cout << "Введіть дані для пасажирського лайнера: " << endl;
        cout << "Назва: ";
        cin.getline(name, sizeof(name));
        cout << "Країна якій належить: ";
        cin.getline(belong_to_country, sizeof(belong_to_country));
        cout << "Вага: ";
        cin >> weight;
        cout << "Пасажиромісткість: ";
        cin >> passengers_capacity;

        cin.ignore(); //Очищюємо символ нового рядка із буфера
    }

    void output() const override { //Функція для виводу даних
        cout << "Інформація щодо ракетного катера: " << endl;
        cout << "Назва: " << name << endl;
        cout << "Країна якій належить: " << belong_to_country << endl;
        cout << "Вага: " << fixed << setprecision(2) << weight << " т." << endl;
        cout << "Пасажиромісткість: " << passengers_capacity << " шт." << endl;
    }
};

int main()
{
    ship* ship = new missile_boat(); //Створюємо покажчик та надаємо йому посилання на об'єкт missile_boat

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ship->input();
    cout << endl;
    ship->output();

    cout << endl << endl;

    ship = new passenger_boat();
    ship->input();
    cout << endl;
    ship->output();

    delete ship;
    ship = nullptr;
}