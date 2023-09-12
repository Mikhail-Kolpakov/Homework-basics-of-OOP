//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

inline float calculate(float first_num, float second_num, char operaton) {
    switch (operaton) {
        case '+':
            return first_num + second_num;
            break;
        case '-':
            return first_num - second_num;
            break;
        case '*':
            return first_num * second_num;
            break;
        case '/':
            return first_num / second_num;
            break;
    }
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

    cout << endl << "Після побчислень відповідь дорівнює: " << fixed << setprecision(2) <<
        calculate(first_num, second_num, operation) << endl;
}