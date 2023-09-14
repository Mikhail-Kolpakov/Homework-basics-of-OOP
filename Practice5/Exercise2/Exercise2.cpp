//Варіант #9
#include <iostream>
#include <windows.h>
#define MAX_NAME_LENGTH 100

using namespace std;

class person {
	const char* name{};
	int age{};
	bool gender{}; //true(1) - чоловік, false(0) - жінка

public:
	person() { //Порожній конструктор

	}

	person(const char* name, int age, bool gender) : name(name), age(age), gender(gender) { //Конструктор з ініціалізацією списком

	}

	person(const person& src) { //Конструктор копіювання
		name = src.name;
		age = src.age;
		gender = src.gender;
	}

	void input() { //Функція для введення даних
		char buffer[MAX_NAME_LENGTH];

		cout << endl << "Задайте характеристику персоні: " << endl;
		cout << "Введіть ім'я: ";
		cin >> buffer;

		int name_length = static_cast<int>(strlen(buffer)); //Дізнаємось довжину імені
		name = new char[name_length + 1];
		strcpy_s(const_cast<char*>(name), name_length + 1, buffer); //Копіюємо вміст змінної buffer

		cout << "Введіть вік: ";
		cin >> age;
		cout << "Введіть стать (1 - чоловік, 0 - жінка): ";
		cin >> gender;
	}

	void output() { //Функція для виведення даних
		cout << endl << "Ім'я: " << name << endl;
		cout << "Вік: " << age << endl;
		if (gender)
			cout << "Стать: чоловік";
		else 
			cout << "Стать: жінка";
	}
};

int main()
{
	person human; //Приклад виклику порожнього конструктора
	person candy("Candy", 21, false); //Приклад виклику конструктора з ініціалізацією списком
	person undefined = candy; //Приклад виклику конструктора копіювання

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	cout << "Для об'єкту класу human: ";
	human.input();
	human.output();

	cout << endl << endl << "Для об'єкту класу candy: ";
	candy.output();

	cout << endl << endl << "Для об'єкту класу undefined: ";
	undefined.output();

	cout << endl;
}