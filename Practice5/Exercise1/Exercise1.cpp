//Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

class point {
	float x{}, y{};

public:
	point() { //Порожній конструктор

	}

	point(float a, float b) : x(a), y(b) { //Конструктор з ініціалізацією списком

	}

	point(const point& src) { //Конструктор копіювання
		x = src.x;
		y = src.y;
	}

	void input() { //Функція для введення даних
		cout << endl << "Задайте координати точці: " << endl;
		cout << "Введіть значення для змінної X: ";
		cin >> x;
		cout << "Введіть значення для змінної Y: ";
		cin >> y;
	}

	void output() { //Функція для виведення даних
		cout << endl << "Значення змінної X = " << x << endl;
		cout << "Значенння змінної Y = " << y;
	}
};

int main()
{
	point a; //Приклад виклику порожнього конструктора
	point b(2.43f, 8.1f); //Приклад виклику конструктора з ініціалізацією списком
	point c = b; //Приклад виклику конструктора копіювання

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Для об'єкту класу a: ";
	a.input();
	a.output();

	cout << endl << endl <<"Для об'єкту класу b: ";
	b.output();

	cout << endl << endl << "Для об'єкту класу c: ";
	c.output();

	cout << endl;
}