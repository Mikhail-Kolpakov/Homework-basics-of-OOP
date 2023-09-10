#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

float S(float, float, float);
float S(float);
float S(float, float);
float V(float, float, float);
float V(float);
float V(float, float);

int main()
{
	float parallelepiped_x, parallelepiped_y, parallelepiped_z;
	float sphere_radius, cylinder_radius;
	float cylinder_height;
	float parallelepiped_volume, sphere_volume, cylinder_volume;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Ведіть довжину паралелепіпеда: ";
	cin >> parallelepiped_x;
	cout << "Ведіть ширину паралелепіпеда: ";
	cin >> parallelepiped_y;
	cout << "Ведіть висоту паралелепіпеда: ";
	cin >> parallelepiped_z;

	cout << endl << "Площа поверхні паралелепіпеда = " << fixed << setprecision(2) << 
		S(parallelepiped_x, parallelepiped_y, parallelepiped_z) << endl;
	cout << "Об'єм паралелепіпеда = " << fixed << setprecision(2) <<
		V(parallelepiped_x, parallelepiped_y, parallelepiped_z) << endl;

	cout << endl << "Введіть радіус сфери: ";
	cin >> sphere_radius;

	cout << endl << "Площа поверхні сфери = " << fixed << setprecision(2) <<
		S(sphere_radius) << endl;
	cout << "Об'єм сфери = " << fixed << setprecision(2) <<
		V(sphere_radius) << endl;

	cout << endl << "Введіть радіус циліндра: ";
	cin >> cylinder_radius;
	cout << "Введіть висоту циліндра: ";
	cin >> cylinder_height;

	cout << endl << "Площа поверхні циліндра = " << fixed << setprecision(2) <<
		S(cylinder_radius, cylinder_height) << endl;
	cout << "Об'єм циліндра = " << fixed << setprecision(2) <<
		V(cylinder_radius, cylinder_height) << endl;
}

float S(float parallelepiped_x, float parallelepiped_y, float parallelepiped_z) {
	float result = 2.0 * (parallelepiped_x * parallelepiped_y + parallelepiped_x * parallelepiped_z + 
		parallelepiped_y * parallelepiped_z);
	return result;
}

float S(float sphere_radius) {
	float result = 4.0 * M_PI * pow(sphere_radius, 2.0);
	return result;
}

float S(float cylinder_radius, float cylinder_height) {
	float result = 2.0 * M_PI * cylinder_radius * cylinder_height + 2.0 * M_PI * pow(cylinder_radius, 2);
	return result;
}

float V(float parallelepiped_x, float parallelepiped_y, float parallelepiped_z) {
	float result = parallelepiped_x * parallelepiped_y * parallelepiped_z;
	return result;
}

float V(float sphere_radius) {
	float result = 4.0 / 3.0 * M_PI * pow(sphere_radius, 3);
	return result;
}

float V(float cylinder_radius, float cylinder_height) {
	float result = M_PI * pow(cylinder_radius, 2) * cylinder_height;
	return result;
}