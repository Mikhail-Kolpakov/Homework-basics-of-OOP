//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <random>

using namespace std;

enum class TypeOfArray {
    X = 'X',
    Y = 'Y'
};

void input(float[], int, TypeOfArray);
void print_values(float[], int, bool, TypeOfArray);
float calculating(float[], int);

int main()
{
    float* x, *y;
    bool is_changed = false;

    //Створюємо генератор випадкових чисел
    random_device rand; //Створюємо джерело ентропії
    mt19937 gen(rand()); //Створюємо об'єкт генератора випадкових чисел Mersenne Twister
    uniform_int_distribution<int> dist(3, 20); //Задаємо діапазон для генерування чисел (2 < N < 20)
    int N = dist(gen); //Генеруємо випадкове число

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Масиви A та B матимуть розмір(випадково згенерований): " << N << endl;

    x = new float[N];
    y = new float[N];

    input(x, N, TypeOfArray::X);
    input(y, N, TypeOfArray::Y);

    cout << endl << "Масиви після введення значень: ";
    print_values(x, N, is_changed, TypeOfArray::X);
    print_values(y, N, is_changed, TypeOfArray::Y);

    cout << endl << endl << "Найбільше значення у масиві X: " << calculating(x, N) << endl;
    cout << "Найбільше значення у масиві Y: " << calculating(y, N) << endl;

    is_changed = true;

    cout << endl << "Масиви після виконання необхідних розрахунків: ";
    print_values(x, N, is_changed, TypeOfArray::X);
    print_values(y, N, is_changed, TypeOfArray::Y);

    delete [] x;
    x = nullptr;
    delete [] y;
    y = nullptr;

    cout << endl;
}

void input(float array[], int length, TypeOfArray type_of_array) { //Функція для заповнення масиву числами з клавіатури
    cout << endl << "Введіть значення елементів для масиву " << static_cast<char>(type_of_array) << ": " << endl;
    for (int i = 0; i < length; i++) {
        cout << "Введіть значення для елементу [" << i << "]: ";
        cin >> array[i];
    }
}

void print_values(float array[], int length, bool is_changed , TypeOfArray type_of_array) { //Функція для виводу вмісту масивів
    cout << endl << "Значення масиву " << static_cast<char>(type_of_array) << ": " << endl;
    for (int i = 0; i < length; i++) {
        if (!is_changed)
            cout << array[i] << " ";
        else
            cout << fixed << setprecision(2) << array[i] << " ";
    }
}

float calculating(float array[], int length) { //Функція для проведення необхідних розрахунків
    float max = array[0];

    for (int i = 1; i < length; i++) //Пошук найбільшого значення у масиві
        if (array[i] > max)
            max = array[i]; 
    for (int i = 0; i < length; i++) //Ділення всіх значень масиву на набільше значення
        array[i] /= max;

    return max;
}