#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

int main()
{
    float sphere_radius, cylinder_radius;
    float cylinder_height;
    float sphere_volume, cylinder_volume;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть радіус сфери: ";
    cin >> sphere_radius;

    sphere_volume = 4.0 / 3.0 * M_PI * pow(sphere_radius, 3);

    cout << endl << "Об'єм сфери = " << fixed << setprecision(2) << sphere_volume << endl;

    cout << endl << "Введіть радіус циліндра: ";
    cin >> cylinder_radius;
    cout << "Введіть висоту циліндра: ";
    cin >> cylinder_height;

    cylinder_volume = M_PI * pow(cylinder_radius, 2) * cylinder_height;

    cout << endl << "Об'єм циліндра = " << fixed << setprecision(2) << cylinder_volume << endl;
}