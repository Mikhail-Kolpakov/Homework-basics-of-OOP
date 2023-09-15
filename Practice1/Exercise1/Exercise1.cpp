#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

float V(float);
float V(float, float);

int main()
{
    float sphere_radius, cylinder_radius;
    float cylinder_height;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть радіус сфери: ";
    cin >> sphere_radius;

    cout << endl << "Об'єм сфери = " << fixed << setprecision(2) << V(sphere_radius) << endl;

    cout << endl << "Введіть радіус циліндра: ";
    cin >> cylinder_radius;
    cout << "Введіть висоту циліндра: ";
    cin >> cylinder_height;

    cout << endl << "Об'єм циліндра = " << fixed << setprecision(2) << V(cylinder_radius, cylinder_height) << endl;
}

float V(float sphere_radius) { //Функція для обрахунку об'єму сфери
    float sphere_volume = 4.0 / 3.0 * M_PI * pow(sphere_radius, 3);
    return sphere_volume;
}

float V(float cylinder_radius, float cylinder_height) { //Функція для обрахунку об'єму циліндра
    float cylinder_volume = M_PI * pow(cylinder_radius, 2) * cylinder_height;
    return cylinder_volume;
}