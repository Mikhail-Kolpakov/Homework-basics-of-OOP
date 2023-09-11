//Варіант #9
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#define LengthX 10
#define LengthY 8

using namespace std;

enum class TypeOfArray {
    X = 'X',
    Y = 'Y'
};

void input(int[], int, TypeOfArray);
void f_pointer(int[], int, int*, int*);
void f_reference(int array[], int, int&, int&);

int main()
{
    int x[LengthX], y[LengthY];
    int s1, k1, s2, k2;
    float z;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    input(x, LengthX, TypeOfArray::X);

    cout << endl << "Масив X складається з чисел: ";
    for (int number : x)
        cout << number << " ";

    f_pointer(x, LengthX, &s1, &k1);
    cout << endl << endl << "Сума непарних елементів: " << s1 << endl << 
        "Кількість непарних елементів: " << k1 << endl << endl;

    input(y, LengthY, TypeOfArray::Y);

    cout << endl << "Масив Y складається з чисел: ";
    for (int number : y)
        cout << number << " ";

    f_reference(y, LengthY, s2, k2);
    cout << endl << endl << "Сума непарних елементів: " << s2 << endl <<
        "Кількість непарних елементів: " << k2 << endl;

    z = static_cast<float>(exp(s1) + exp(s2)) / (k1 * k2);

    cout << endl << endl << "Z = " << fixed << setprecision(2) << z << endl;
}

void input(int array[], int length, TypeOfArray type_of_array) { //Функція для заповнення масиву числами з клавіатури
    cout << "Заповніть масив " << static_cast<char>(type_of_array) << " числами: " << endl;
    for (int i = 0; i < length; i++) {
        cout << "Введіть значення для елементу [" << i << "]: ";
        cin >> array[i];
    }  
}

void f_pointer(int array[], int length, int* s1, int* k1) { //Для обробки масиву з використанням покажчиків
    *s1 = *k1 = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 != 0) {
            *s1 += array[i];
            (*k1)++;
        }
    }
}

void f_reference(int array[], int length, int& s2, int& k2) { //Для обробки масиву з використанням посилань
    s2 = k2 = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 != 0) {
            s2 += array[i];
            k2++;
        }
    }
}