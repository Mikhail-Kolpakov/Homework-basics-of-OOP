//Варіант #9
#include <iostream>
#include <windows.h>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що характеризує транспорт
class transport {
    //Оголошення дружніх функцій
    friend istream& operator >> (istream&, transport&);
    friend ostream& operator << (ostream&, const transport&);

protected:
    char name[MAX_NAME_LENGTH]; //Назва транспорту
    char route[MAX_NAME_LENGTH]; //Маршрут
    int human_capacity; //Вмісткість трансопрту
};

//Клас, що характеризує електротранспорт
class electric_transport : public transport {
    //Оголошення дружніх функцій
    friend istream& operator >> (istream&, electric_transport&);
    friend ostream& operator << (ostream&, const electric_transport&);

private:
    int battery_capacity; //Вмісткість батарей електроспоживання
};

//Клас, що характеризує залізничний транспорт
class railway_transport : public transport {
    //Оголошення дружніх функцій
    friend istream& operator >> (istream&, railway_transport&);
    friend ostream& operator << (ostream&, const railway_transport&);

private:
    int carriages_number; //Кількість вагонів
};

//Читаємо дані з потоку для класу transport
istream& operator >> (istream& stream, transport& trans) {
    cout << "Введіть назву транспорта: ";
    cin.getline(trans.name, sizeof(trans.name));
    cout << "Введіть маршрут транспорта: ";
    cin.getline(trans.route, sizeof(trans.route));
    cout << "Введіть пасажировмісткість: ";
    cin >> trans.human_capacity;
    cin.ignore();

    return stream;
}

//Записуємо дані в потік для класу transport
ostream& operator << (ostream& stream, const transport& trans) {
    cout << "Інформація щодо транспорту: " << endl;
    cout << "Назва: " << trans.name << endl;
    cout << "Маршрут: " << trans.route << endl;
    cout << "Пасажировмісткість: " << trans.human_capacity << endl;

    return stream;
}

//Читаємо дані з потоку для класу electric_transport
istream& operator >> (istream& stream, electric_transport& elec_trans) {
    stream >> static_cast<transport&>(elec_trans); //Викликаємо operator >> базового класу
    cout << "Введіть вмісткість батареї електроспоживання (Вт.): ";
    cin >> elec_trans.battery_capacity;
    cin.ignore();

    return stream;
}

//Записуємо дані в потік для класу electric_transport
ostream& operator << (ostream& stream, const electric_transport& elec_trans) {
    stream << static_cast<const transport&>(elec_trans); //Викликаємо operator << базового класу
    cout << "Вмісткість батареї електроспоживання: " << elec_trans.battery_capacity << " Вт." << endl;

    return stream;
}

//Читаємо дані з потоку для класу railway_transport
istream& operator >> (istream& stream, railway_transport& railway_trans) {
    stream >> static_cast<transport&>(railway_trans); //Викликаємо operator >> базового класу
    cout << "Введіть кількість вагонів: ";
    cin >> railway_trans.carriages_number;
    cin.ignore();

    return stream;
}

//Записуємо дані в потік для класу railway_transport
ostream& operator << (ostream& stream, const railway_transport& railway_trans) {
    stream << static_cast<const transport&>(railway_trans); //Викликаємо operator << базового класу
    cout << "Кількість вагонів: " << railway_trans.carriages_number << " шт." << endl;

    return stream;
}

int main()
{
    electric_transport electric_bus;
    railway_transport train;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Заповніть дані для електроавтобуса: " << endl;
    cin >> electric_bus;
    cout << endl;
    cout << electric_bus;

    cout << endl;

    cout << "Заповніть дані для потяга: " << endl;
    cin >> train;
    cout << endl;
    cout << train;
}