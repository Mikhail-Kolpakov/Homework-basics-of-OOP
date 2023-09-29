//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що характеризує компьютерний процесор
class processor {
    //Оголошення дружніх функцій
    friend istream& operator >> (istream&, processor&);
    friend ostream& operator << (ostream&, const processor&);

private:
    char manufacturer[MAX_NAME_LENGTH]; //Фірма-виробник процесору
    char name[MAX_NAME_LENGTH]; //Назва процесору
    int cores_number, streams_number; //Кількість ядер/потоків процесору
    float min_frequency, max_frequency; //Мінімальна/максимальна частота роботи процесора
    int energy_consumption; //Енергоспоживання
};

//Читаємо дані з потоку
istream& operator >> (istream& stream, processor& proc) {
    cout << "Введіть назву фірми-виробника процесора: ";
    cin.getline(proc.manufacturer, sizeof(proc.manufacturer));
    cout << "Введіть назву процесора: ";
    cin.getline(proc.name, sizeof(proc.name));
    cout << "Введіть кількість ядер процесора: ";
    cin >> proc.cores_number;
    cout << "Введіть кількість потоків процесора: ";
    cin >> proc.streams_number;
    cout << "Введіть мінімальну частоту роботи процесора: ";
    cin >> proc.min_frequency;
    cout << "Введіть максимальну частоту роботи процесора: ";
    cin >> proc.max_frequency;
    cout << "Введіть енергоспоживання процесора: ";
    cin >> proc.energy_consumption;

    return stream;
}

//Записуємо дані в потік
ostream& operator << (ostream& stream, const processor& proc) {
    cout << "Інформація щодо процесора: " << endl;
    cout << "Фірма-виробник: " << proc.manufacturer << endl;
    cout << setw(20);
    cout.setf(ios::left);
    cout << "Назва: " << proc.name << endl;
    cout << "Кількість ядер: " << proc.cores_number << " шт." << endl;
    cout << "Кількість потоків: " << proc.streams_number << " шт." << endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout << "Частота роботи: " << setprecision(1) << proc.min_frequency << " — " 
        << proc.max_frequency << " ГГц." << endl;
    cout.unsetf(ios::showpos);
    cout << "Енергоспоживання: " << oct << proc.energy_consumption << " Вт." << endl;

    return stream;
}

int main()
{
    processor proc;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cin >> proc;
    cout << endl;
    cout << proc;
}