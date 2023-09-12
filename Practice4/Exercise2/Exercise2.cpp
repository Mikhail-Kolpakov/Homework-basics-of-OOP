//Варіант #9
#include <iostream>
#include <windows.h>
#include <math.h>
#include <iomanip>

using namespace std;

class rectangle {
private:
	double length, width;

public:
	void vvod(const char* name) {
		cout << "Введіть ширину для " << name << ": ";
		cin >> width;
		cout << "Введіть довжину для " << name << ": ";
		cin >> length;
	}

	double s() { //Метод для обчислення площі
		double s;
		s = length * width;

		return s;
	}

};

int main() {
	double square;
	rectangle rect1, rect2;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	rect1.vvod("rect1");
	square = rect1.s();

	cout << endl << "Для rect1 плоша дорінює: " << fixed << setprecision(2) << square << endl << endl;

	rect2.vvod("rect2");
	square = rect2.s();

	cout << endl << "Для rect2 площа дорінює: " << fixed << setprecision(2) << square << endl;
	cout << endl << "Фініш!" << endl;
}