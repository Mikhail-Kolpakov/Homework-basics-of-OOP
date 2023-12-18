// Варіант #9
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float delta_x, float a, float b, float c) { // Функція задана за умовою завдання
    // Робимо перевірки на допустимість вхідних значень для функції заданою мені за умовою
    if (c * delta_x + pow(a, 2.0) < 0) {
        cout << "Підкореневий вираз не може приймати значення менше 0" << endl;
        cout << "delta_x = " << delta_x << ", a = " << a << ", b = " << b << ", c = " << c << endl << endl;
        return -INFINITY;
    }
    if (b <= 0) {
        cout << "Функція натурального логорифму може приймати тільки додатні значення" << endl;
        cout << "delta_x = " << delta_x << ", a = " << a << ", b = " << b << ", c = " << c << endl << endl;
        return -INFINITY;
    }
    if (log(b) == 0) {
        cout << "Знаменник при діленні не може дорівнювати 0" << endl;
        cout << "delta_x = " << delta_x << ", a = " << a << ", b = " << b << ", c = " << c << endl << endl;
        return -INFINITY;
    }

    return (sqrt(c * delta_x + pow(a, 2.0)) + 5) / (log(b)) + sin(a); // Повертаємо результат розрахунків функції заданою мені за умовою 
}

int main()
{
    float x_min, x_max, x_delta;
    float a, b, c;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input_file("input.txt"); // Відкриваємо файл(за допомогою конструктора) для зчитування

    if (!input_file.is_open()) { // Якщо файл не відкрився
        cout << "Не вдалося відкрити файл input.txt для зчитування" << endl;
        exit(1);
    }

    // Зчитуємо дані
    input_file >> x_min >> x_max >> x_delta;
    input_file >> a >> b >> c;

    input_file.close(); // Закриваємо файл

    ofstream output_file("output.txt"); // Відкриваємо файл(за допомогою конструктора) для запису

    if (!output_file.is_open()) { // Якщо файл не відкрився
        cout << "Не вдалося відкрити файл output.txt для запису" << endl;
        exit(1);
    }

    output_file << "Початкові значення для a, b, c відповідно: " << a << ", " << b << ", " << c << endl << endl;
    output_file << setw(15) << "Значення x" << setw(25) << "Значення функції" << endl;
    
    for (float x = x_min; x <= x_max; x += x_delta) { // Робимо основні розрахунки
        float result = function(x, a, b, c);

        if (result == -INFINITY)
            output_file << "Недопустимі значення вхідних параметрів на даному кроці" << endl;
        else
            output_file << setw(15) << x << setw(25) << result << endl;
    }

    output_file.close(); // Закриваємо файл
}
