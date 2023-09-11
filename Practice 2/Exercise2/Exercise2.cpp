//Варіант #9
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#define N 5
#define M 4

using namespace std;

enum class TypeOfArray {
    X = 'X',
    Y = 'Y'
};

void input(int[], int, TypeOfArray);
void calculating(int[], int, float&, float&, float&, float(float), float(float), float(float), TypeOfArray);

int main() {
    int x[N], y[M];
    float A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, fita;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    input(x, N, TypeOfArray::X);
    cout << endl;
    input(y, M, TypeOfArray::Y);

    calculating(x, N, A, B, C, sin, cos, tan, TypeOfArray::X);
    calculating(y, M, D, E, F, tan, exp, cos, TypeOfArray::Y);

    fita = (A * sin(B) + B * cos(C)) / (D + E * sin(F));

    cout << endl << "Після проведення розрахунків fita = " << fixed << setprecision(2) << fita << endl;
}

void input(int array[], int length, TypeOfArray type_of_array) {
    cout << "Введіть значення елементів для масиву " << static_cast<char>(type_of_array) << ": " << endl;
    for (int i = 0; i < length; i++) {
        cout << "Введіть значення для елементу [" << i << "]: ";
        cin >> array[i];
    }
}

void calculating(int array[], int length, float& f_par, float& s_par, float& t_par, float f_for(float), float s_for(float), float t_for(float), TypeOfArray type_of_array) {
    float s = 0, p = 1;
    for (int i = 0; i < length; i++) {
        s += array[i];
        p *= array[i];
        f_par += array[i] * f_for(array[i]);
        s_par += array[i] * s_for(array[i]);
        t_par += array[i] * t_for(array[i]);
    }
    if (type_of_array == TypeOfArray::X) {
        f_par *= p;
        s_par *= s;
        t_par *= p + s;
    }
}