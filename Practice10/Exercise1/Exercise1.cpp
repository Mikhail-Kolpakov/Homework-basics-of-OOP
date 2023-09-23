//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що описує транспорт
class transport {
protected:
    char type[MAX_NAME_LENGTH]; //Тип транспорту
    float clear_profit; //Чистий прибуток
    float max_speed; //Максимальна швидкість
    float weight; //Вага

public:
    transport(const char* type, float clear_profit, float max_speed, float weight) {
        strncpy_s(this->type, type, MAX_NAME_LENGTH); //Копіюємо вміст рядка type в масив this->type
        this->type[MAX_NAME_LENGTH - 1] = '\0'; //Переконуємося, що рядок закінчується нульовим символом
        this->clear_profit = clear_profit;
        this->max_speed = max_speed;
        this->weight = weight;
    }

    //Створюємо віртуальний метод
    virtual void output() {
        cout << "Тип транспорту: " << type << endl;
        cout << "Чистий прибуток: " << fixed << setprecision(2) << clear_profit << " грн." << endl;
        cout << "Максимальна швидкість: " << fixed << setprecision(2) << max_speed << " км/год." << endl;
        cout << "Вага: " << fixed << setprecision(2) << weight << " кг." << endl;
    }

    virtual ~transport() {} //Створюємо віртуальний деструктор
};

//Клас, що описує вантажний транспорт
class cargo_transport : public transport {
private:
    float lifting_capacity; //Вантажопідйомність

public:
    cargo_transport(const char* type, float clear_profit, float max_speed, float weight, float lifting_capacity) : transport(type, clear_profit, max_speed, weight) {
        this->lifting_capacity = lifting_capacity;
    }

    //Явним чином вказуємо, що метод перевизначен
    void output() override {
        transport::output();
        cout << "Вантажопідйомність: " << fixed << setprecision(2) << lifting_capacity << " кг." << endl;
    }
};

//Клас, що описує пасажирський транспорт
class passenger_transport : public transport {
private:
    int passenger_amount; //Кількість пасажирів

public:
    passenger_transport(const char* type, float clear_profit, float max_speed, float weight, int passenger_amount) : transport(type, clear_profit, max_speed, weight) {
        this->passenger_amount = passenger_amount;
    }

    //Явним чином вказуємо, що метод перевизначен
    void output() override {
        transport::output();
        cout << "Кількість пасажирів: " << passenger_amount << " шт." << endl;
    }
};

int main()
{
    transport transport_ship("баржа", 45650, 40, 7500);
    cargo_transport transport_truck("вантажівка", 52000, 105, 15750, 6000);
    passenger_transport transport_bus("автобус", 31200, 90, 10400, 52);
    transport* transport(&transport_ship); //Створюємо покажчик та надаємо йому посилання на об'єкт transport_ship

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    transport->output(); //Викликаємо через покажчик метод output

    cout << endl;

    transport = &transport_truck; //Надаємо покажчику посилання на об'єкт transport_truck
    transport->output();

    cout << endl;

    transport = &transport_bus;
    transport->output();

    delete transport;
}