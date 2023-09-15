//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

class floating_craft {
    char name[MAX_NAME_LENGTH]; //Назва
    float water_content; //Водотонажність
    char body_material[MAX_NAME_LENGTH]; //Матеріал, з якого виготовлено корпус
    int number_of_crew; //Кількість членів єкіпажу
    float speed; //Швидкість руху

public:
    void input(int i) { //Функція для введення даних
        cout << endl << "Введіть характеристику для плаваючого засобу #" << i + 1 << ": " << endl;
        cout << "Введіть ім'я: ";
        cin.ignore(); //Очищюємо символ нового рядка із буфера
        cin.getline(name, sizeof(name));
        cout << "Введіть водотонажність: ";
        cin >> water_content;
        cout << "Введіть матеріал, з якого виготовлений корпус: ";
        cin.ignore();
        cin.getline(body_material, sizeof(body_material));
        cout << "Введіть кількість членів екіпажу: ";
        cin >> number_of_crew;
        cout << "Введіть швидкість руху: ";
        cin >> speed;
    }

    void output(int i) { //Функція для виведення даних
        cout << endl << "Плаваючий засіб #" << i + 1 << ": " << endl;
        cout << "Ім'я: " << name << endl;
        cout << fixed << setprecision(2) << "Водотонажність: " << water_content << endl;
        cout << "Матеріал, з якого виготовлено корпус: " << body_material << endl;
        cout << "Кількість членів екіпажу: " << number_of_crew << endl;
        cout << fixed << setprecision(2) << "Швидкість: " << speed << endl;
    }

    bool analyse(char* desired_material, float desired_min_speed) { //Функція для виконання порівнянь
        return strcmp(body_material, desired_material) == 0 && speed >= desired_min_speed ? true : false;
    }
};

int main()
{
    int number_of_vessels;
    char desired_material[MAX_NAME_LENGTH];
    float desired_min_speed;
    floating_craft* vessels;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть кількість плаваючих засобів: ";
    cin >> number_of_vessels;

    vessels = new floating_craft[number_of_vessels]; //Створюємо масив об'єктів заданої кількості

    for (int i = 0; i < number_of_vessels; i++) //Заповнюємо характеристичні дані для кожного об'єкту
        vessels[i].input(i);

    cout << endl << "Введіть бажаний матеріал корпусу: ";
    cin.ignore();
    cin.getline(desired_material, sizeof(desired_material));

    cout << "Введіть бажану мінімальну швидкість (км/год): ";
    cin >> desired_min_speed;

    cout << endl << "Плаваючі засоби, які задовільняють ваш вибір: ";
    for (int i = 0; i < number_of_vessels; i++)
        if (vessels[i].analyse(desired_material, desired_min_speed)) //Обираємо які плаваючі хасоби задовільняють умову
            vessels[i].output(i);

    delete [] vessels;
    vessels = nullptr;

    cout << endl;
}