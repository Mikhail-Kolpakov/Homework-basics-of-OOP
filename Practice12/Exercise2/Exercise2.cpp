//Варіант #9
#include <iostream>
#include <windows.h>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що характеризує персону
class person {
    //Оголошення дружніх функцій
    friend istream& operator >> (istream&, person&);
    friend ostream& operator << (ostream&, const person&);

private:
    char* name; //Ім'я
    int age; //Вік
    bool gender; //Стать

public:
    ~person() {
        delete[] name;
    }
};

//Читаємо дані з потоку
istream& operator >> (istream& stream, person& pers) {
    char buffer[MAX_NAME_LENGTH];

    cout << "Введіть ім'я людини: ";
    cin.getline(buffer, sizeof(buffer));
    pers.name = new char[strlen(buffer) + 1]; //Виділяємо пам'ять під нове ім'я
    strcpy_s(pers.name, strlen(buffer) + 1, buffer); //Копіюємо вміст змінної buffer
    cout << "Введіть вік людини: ";
    cin >> pers.age;
    cout << "Введіть стать людини (1 - чоловік, 0 - жінка): ";
    cin >> pers.gender;

    return stream;
}

//Записуємо дані в потік
ostream& operator << (ostream& stream, const person& pers) {
    cout << "Інформація щодо персони: " << endl;
    cout << "Ім'я: " << pers.name << endl;
    cout << "Вік: " << pers.age << " років" << endl;
    cout << "Стать: " << (pers.gender ? "чоловік" : "жінка") << endl;

    return stream;
}

int main()
{
    person mark;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cin >> mark;
    cout << endl;
    cout << mark;
}