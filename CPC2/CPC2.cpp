// Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

// Приклад шаблонного класу
template <typename T>
class element_counter {
private:
	const T* array;

public:
	element_counter(const T arr[]) : array(arr) {}

	// Приклад шаблонної функції
	template <typename V, unsigned N>
	decltype(auto) count_elements_greater_then(const V& value) {
		auto count = 0;

		for (int i = 0; i < N; i++)
			if (array[i] > value)
				count++;

		return count;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Перевіряємо для типу даних int
	int int_array[] = { 0, 2, 3, 4, 3, 6 };
	int int_value = 5;
	element_counter<int> int_counter(int_array);
	auto count1 = int_counter.count_elements_greater_then<int, sizeof(int_array) / sizeof(int_array[0])>(int_value);

	cout << "Кількість елементів більших за " << int_value << ": " << count1 << endl;
	cout << "Функція отримує параметр int_value типу " << (typeid(int_value).name()) << " та повертає значення count1 типу " << (typeid(count1).name()) << endl << endl;

	// Перевіряємо для типу даних float
	float float_array[] = { 0.5F, 2.3F, 3.7F, 4.1F, 3.8F, 6.2F };
	float float_value = 3.0F;
	element_counter<float> float_counter(float_array);
	auto count2 = float_counter.count_elements_greater_then<float, sizeof(float_array) / sizeof(float_array[0])>(float_value);

	cout << "Кількість елементів більших за " << float_value << ": " << count2 << endl;
	cout << "Функція отримує параметр float_value типу " << (typeid(float_value).name()) << " та повертає значення count2 типу " << (typeid(count2).name()) << endl;
}
