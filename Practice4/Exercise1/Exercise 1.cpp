//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

enum class TypeOfCube {
    First,
    Second
};

class cube {
public:
    float side;

    float volume() {
        return (side * side * side);
    }

    static void vvod(float &value) {
        cout << "Введіть довжину куба: ";
        cin >> value;
    }

    static void vivod(cube object, TypeOfCube type_of_cube) {
        if(type_of_cube == TypeOfCube::First)
            cout << endl << "Об'єм першого куба дорівнює: " << fixed << setprecision(2) << object.volume() << endl;
        else
            cout << "Об'єм другого куба дорівнює: " << fixed << setprecision(2) << object.volume() << endl;
    }
};

int main()
{
    cube c1 {}, c2 {};

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cube::vvod(c1.side);

    cube::vivod(c1, TypeOfCube::First);

    c2.side = c1.side + 2;

    cube::vivod(c2, TypeOfCube::Second);
}