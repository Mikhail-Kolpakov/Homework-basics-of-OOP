//Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

void input(int array[], int length) { //Функція для введення елементів масиву
    for (int i = 0; i < length; i++) {
        cout << "Введіть значення для елементу масиву з індексом [" << i << "]: ";
        cin >> array[i];
    }
}

void find_event_count_and_sum(int array[], int length, int& sum, int& count) { //Функція для обробки масиву з використанням посилань
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            sum += array[i];
            count++;
        }
    }
}

int main()
{
    const int length = 10; //Довжина масиву
    int my_array[length];
    int sum = 0; //Сума паних елементів масиву
    int count = 0; //Кількість парних елементів масиву

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    input(my_array, length);
    find_event_count_and_sum(my_array, length, sum, count);

    cout << endl << "Сума парних чисел у масиві: " << sum << endl;
    cout << "Кількість парних чисел у масиві: " << count << endl;
}