//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

//Абстрактний клас, що характеризує співробітників
class employee {
protected:
    char name[MAX_NAME_LENGTH]; //Ім'я
    float salary; //Зарплатня

public:
    employee(const char* name, float salary) {
        strncpy_s(this->name, name, MAX_NAME_LENGTH); //Копіюємо вміст рядка name в масив this->name
        this->name[MAX_NAME_LENGTH - 1] = '\0'; //Переконуємося, що рядок закінчується нульовим символом
        this->salary = salary;
    }

    //Оголошуємо чисті віртуальні функції
    virtual float calculate_salary() const = 0;
    virtual void output() const = 0;

    virtual ~employee() {} //Створюємо віртуальний деструктор
};

//Клас, що характеризує кадрів
class personnel : public employee {
public:
    personnel(const char* name, float salary) : employee(name, salary) {}

    float calculate_salary() const override { //Функція для розрахування зарплатні
        return salary;
    }

    void output() const override { //Функція для виводу даних
        cout << "Кадри: " << name << endl;
        cout << "Зарплатня всіх разом: " << fixed << setprecision(2) << calculate_salary() << " грн." << endl;
    }
};

//Клас, що характеризує робітника
class worker : public personnel {
private:
    const float difficulty_factor = 1.3; //Коефіцієнт складності

public:
    worker(const char* name, float salary) : personnel(name, salary) {}

    float calculate_salary() const override { //Функція для розрахування зарплатні
        float final_salary = salary * difficulty_factor;
        return final_salary;
    }

    void output() const override { //Функція для виводу даних
        cout << "Робітник: " << name << endl;
        cout << "Зарплатня: " << fixed << setprecision(2) << calculate_salary() << " грн." << endl;
    }
};

//Клас, що характеризує інженера
class engineer : public personnel {
private:
    const float difficulty_factor = 1.9; //Коефіцієнт складності
    const int premium = 570; //Премія

public:
    engineer(const char* name, float salary) : personnel(name, salary) {}

    float calculate_salary() const override { //Функція для розрахування зарплатні
        float final_salary = salary * difficulty_factor + premium;
        return final_salary;
    }

    void output() const override { //Функція для виводу даних
        cout << "Інженер: " << name << endl;
        cout << "Зарплатня: " << fixed << setprecision(2) << calculate_salary() << " грн." << endl;
    }
};

//Клас, що характеризує адміністрацію
class administration : public personnel {
private:
    const float difficulty_factor = 1.8; //Коефіцієнт складності
    const int premium = 1000; //Премія

public:
    administration(const char* name, float salary) : personnel(name, salary) {}

    float calculate_salary() const override { //Функція для розрахування зарплатні
        float final_salary = salary * difficulty_factor + premium;
        return final_salary;
    }

    void output() const override { //Функція для виводу даних
        cout << "Адміністратор: " << name << endl;
        cout << "Зарплатня: " << fixed << setprecision(2) << calculate_salary() << " грн." << endl;
    }
};

int main()
{
    employee* employee = new personnel("Андрій, Богдан, Захарій, Сергій", 88650); //Створюємо покажчик та надаємо йому посилання на об'єкт personnel

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    employee->output();

    cout << endl;

    employee = new worker("Валерій", 9840);
    employee->output();

    cout << endl;

    employee = new engineer("Іван", 12500);
    employee->output();

    cout << endl;

    employee = new administration("Ольга", 11230);
    employee->output();

    delete employee;
    employee = nullptr;
}