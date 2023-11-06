//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

class trapezoid {
private:
	float a{}; //Перша сторона
	float b{}; //Друга сторона
	float h{}; //Висота

	float area; //Параметр, який потрібно обрахувати (площа)

public:
	trapezoid() {} //Порожній конструктор

	trapezoid(float f_side, float s_side, float height) : a(f_side), b(s_side), h(height) {} //Конструктор з ініціалізацією списком

	trapezoid(const trapezoid& src) { //Конструктор копіювання
		a = src.a;
		b = src.b;
		h = src.h;
		area = src.area;
	}

	float get_area() { //Метлд для отримання приватного поля area
		return area;
	}

	void set() { //Метод для введення полів
		cout << "Введіть величини трапеції: " << endl;
		cout << "Введіть першу сторону A: ";
		cin >> a;
		cout << "Введіть другу сторону B: ";
		cin >> b;
		cout << "Введіть висоту H: ";
		cin >> h;
	}

	void show() { //Метод для друку полів
		cout << "Сторона A = " << fixed << setprecision(2) << a << endl;
		cout << "Сторона B = " << b << endl;
		cout << "Висота H = " << h << endl;
		cout << "Площа area = " << area;
	}

	float calculate_area() { //Метод для обчислення площі трапеції
		area = (a + b) / 2 * h;
		return area;
	}

	//Перевантаження операторів
	trapezoid operator + (trapezoid& other) { //Перевантаження оператора +
		trapezoid result;
		result.a = a + other.a;
		result.b = b + other.b;
		result.h = h + other.h;
		result.area = calculate_area() + other.calculate_area();

		return result;
	}

	bool operator < (const trapezoid& other) const { //Перевантаження оператора <
		return (a < other.a) && (b < other.b) && (h < other.h) && (area < other.area);
	}

	trapezoid& operator = (const trapezoid& other) { //Перевантаження оператора =
		if (this == &other) { //Перевірка на самоприсвоювання
			return *this;
		}

		a = other.a;
		b = other.b;
		h = other.h;
		area = other.area;

		return *this;
	}
};

int main()
{
	const float setted_area = 10;
	const int objects_count = 4;
	trapezoid C1;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Для трапеції C1: " << endl;
	C1.set(); //1. Створити об'єкт С1, визначити поля за допомогою ф-ції SET
	C1.calculate_area();

	trapezoid C2(5, 4, 2); //2. Створити об'єкт С2, визначити поля за допомогою конструктора
	C2.calculate_area();
	trapezoid C3 = C2; //3. Створити об'єкт С3 = С2
	C3.calculate_area();
	trapezoid C4 = C1 + C3; //4. С4 = С1 + С3
	C4.calculate_area();

	cout << endl << "С2 менше С1: " << boolalpha << (C2 < C1) << endl << endl; //5. Перевірити С2 < С1

	trapezoid trapezoid_array[objects_count]{ C1, C2, C3, C4 }; //Створюємо масив об'єктів trapezoid

	cout << "Трапеції, площа яких менша заданого setted_area: " << endl;
	for (int i = 0; i < objects_count; i++) {
		if (trapezoid_array[i].get_area() < setted_area) { //Виводимо трапеції, площа яких менша заданого setted_area
			cout << endl << "Дані об'єкту C" << i + 1 << ": " << endl;
			trapezoid_array[i].show();
		}
		cout << endl;
	}
}