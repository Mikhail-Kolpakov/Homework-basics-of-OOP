//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

inline float calculate(float first_num, float second_num, char operation) {
    if (operation == '+')
        return first_num + second_num;
    else if (operation == '-')
        return first_num - second_num;
    else if (operation == '*')
        return first_num * second_num;
    else 
        return first_num / second_num;
}

int main()
{
    float first_num, second_num;
    char operation;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть перше число: ";
    cin >> first_num;
    cout << "Введіть знак операції(+, -, *, /): ";
    cin >> operation;
    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout << endl << "Введена некорректна операція" << endl;
        return 1;
    }
    cout << "Введіть другое число: ";
    cin >> second_num;

    cout << endl << "Після обчислень відповідь дорівнює: " << fixed << setprecision(2) <<
        calculate(first_num, second_num, operation) << endl;
}