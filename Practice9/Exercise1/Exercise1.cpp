//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що характеризує будівлю
class building {
protected:
    char address[MAX_NAME_LENGTH]; //Адреса
    char purpose[MAX_NAME_LENGTH]; //Призначення
    float useful_area; //Корисна площа
    int price; //Ціна

public:
    building(const char* address, const char* purpose, float useful_area, int price) {
        strncpy_s(this->address, address, MAX_NAME_LENGTH); //Копіюємо вміст рядка address в масив this->address
        this->address[MAX_NAME_LENGTH - 1] = '\0'; //Перконуємося, що рядок закінчується нульовим символом
        strncpy_s(this->purpose, purpose, MAX_NAME_LENGTH);
        this->purpose[MAX_NAME_LENGTH - 1] = '\0';
        this->useful_area = useful_area;
        this->price = price;
    }

    void output() { //Функція для виведення даних
        cout << "Адреса: " << address << endl;
        cout << "Призначення: " << purpose << endl;
        cout << "Корисна площа: " << fixed << setprecision(2) << useful_area << " кв. м" << endl;
        cout << "Ціна: " << price << "$" << endl;
    }
};

//Клас, що характеризує житловий будинок
class house : public building {
private: 
    int flats_amount; //Кількість квартир

public:
    //Виклик конструктора базового класу
    house(const char* address, const char* purpose, float useful_area, int price, int flats_amount) : building(address, purpose, useful_area, price) {
        this->flats_amount = flats_amount;
    }

    void output() { //Функція для виведення даних
        building::output(); //Виклик методу базового класу з похідного класу
        cout << "Кількість квартир: " << flats_amount << endl;
    }
};

//Клас, що характеризує дачу
class country_house : public building {
private:
    float kailyard_area; //Площа під город
    int trees_amount; //Кількість дерев у садку

public:
    //Виклик конструктора базового класу
    country_house(const char* address, const char* purpose, float useful_area, int price, float kailyard_area, int trees_amount) : building(address, purpose, useful_area, price) { 
        this->kailyard_area = kailyard_area;
        this->trees_amount = trees_amount;
    }

    void output() { //Функція для виведення даних
        building::output(); //Виклик методу базового класу з похідного класу
        cout << "Площа під город: " << fixed << setprecision(2) << kailyard_area << " кв. м" << endl;
        cout << "Кількість дерев у садку: " << trees_amount << endl;
    }
};

int main()
{
    house house("проспект Шевченка 21", "житловий будинок", 132.75f, 35500, 26);
    country_house country_house("вулиця Куликівська", "дача", 1210, 22000, 400, 20);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Інформація щодо житлового будинку: " << endl;
    house.output();

    cout << endl << "Інформація щодо дачі: " << endl;
    country_house.output();
}