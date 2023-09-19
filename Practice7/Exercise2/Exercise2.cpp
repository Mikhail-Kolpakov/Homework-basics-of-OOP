//Варіант #9
#include <iostream>
#include <windows.h>
#define MAX_NAME_LENGTH 100

using namespace std;

class Automobile; //Оголошуємо клас Automobile, щоб Person бачив цей клас

//Клас, що описує людину
class Person {
private:
    char name[MAX_NAME_LENGTH]; //Ім'я людини

public:
    Person(const char* name) {
        strncpy_s(this->name, name, MAX_NAME_LENGTH); //Копіюємо вміст рядка name в масив this->name
        this->name[MAX_NAME_LENGTH - 1] = '\0'; //Перконуємося, що рядок закінчується нульовим символом
    }

    void drive(const Automobile&);
    void set_price(Automobile&, int);
};

//Клас, що описує автомобіль
class Automobile {
    //Оголошуємо дружній клас
    friend class Person;

private:
    char name[MAX_NAME_LENGTH]; //Назва автомобілю
    int price; //Ціна автомобіля

public:
    Automobile(const char* name, int price) {
        strncpy_s(this->name, name, MAX_NAME_LENGTH); //Копіюємо вміст рядка name в масив this->name
        this->name[MAX_NAME_LENGTH - 1] = '\0'; //Перконуємося, що рядок закінчується нульовим символом
        this->price = price;
    }

    void output() { //Функція для виводу інформації щодо автомобіля
        cout << "Автомобіль " << name << " коштує " << price << "$" << endl;
    }
};

int main()
{
    Automobile automobile("Vaz2107", 1000);
    Person Grigoriy("Григорій");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    automobile.output();
    Grigoriy.drive(automobile);
    Grigoriy.set_price(automobile, 850);
    automobile.output();
}

void Person::drive(const Automobile& car) { //Функція для вождіння автомобіля
    cout << endl << name << " їде на автомобілі " << car.name << endl;
    cout << "Який же він крутий!" << endl << endl;
}

void Person::set_price(Automobile& car, int price) { //Функція для встановлення ціни автомобіля
    car.price = price;
}