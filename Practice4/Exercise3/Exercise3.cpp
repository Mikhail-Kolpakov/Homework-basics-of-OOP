//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>

using namespace std;

class math_expression {
    float x, y, z, t;

public:
    void vvod() {
        cout << endl << "Введіть X: ";
        cin >> x;
        cout << "Введіть Y: ";
        cin >> y;
        cout << "Введіть Z: ";
        cin >> z;
    }

    void vivod() {
        Run();
        cout << endl << "(" << x << ", " << y << ", " << z << ") = " << t << endl;
    }

    void Run() {
        t = static_cast<float>(fabs(pow(x, y / x) - cbrtf(y / x))) + 
            static_cast<float>((y - x) * ((cosf(y) - z / (y - x)) / (1 + pow(y - x, 2))));
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Прямий виклик: ";
    math_expression a;
    a.vvod();
    a.vivod();

    cout << endl << "Непрямий виклик:";
    math_expression a1;
    math_expression *b = &a1;
    b->vvod();
    b->vivod();

    cout << endl << "Динамічне виділення пам'яті: ";
    math_expression *c = new math_expression;
    c->vvod();
    c->vivod();
    delete c;

    cout << endl << "Непрямий + динамічне виділення пам'яті: ";
    math_expression *c1 = new math_expression;
    math_expression *d = c1;
    d->vvod();
    d->vivod();
    delete d;

    cout << endl;
}