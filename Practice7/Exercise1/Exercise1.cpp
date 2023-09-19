//Варіант #9
#include <iostream>
#include <windows.h>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що описує автомобіль
class Automobile {
    //Оголошуємо дружні функцій
    friend void drive(const Automobile&);
    friend void set_price(Automobile&, int);

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

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    automobile.output();
    drive(automobile);
    set_price(automobile, 850);
    automobile.output();
}

void drive(const Automobile &car) { //Функція для вождіння автомобіля
    cout << endl << "Ви їдете на автомобілі " << car.name<< endl;
    cout << "Який же ви крутий!" << endl << endl ;
}

void set_price(Automobile &car, int price) { //Функція для встановлення ціни автомобіля
    car.price = price;
}