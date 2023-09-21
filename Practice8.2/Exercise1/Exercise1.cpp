//Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

//Клас, що характерихує логічні змінні
class Bool {
    //Оголошення дружніх функцій
    friend Bool operator + (const Bool&, const Bool&);
    friend Bool operator * (const Bool&, const Bool&);
    friend Bool operator ^ (const Bool&, const Bool&);
    friend Bool operator + (const Bool&, int);
    friend Bool operator + (int, const Bool&);
    friend Bool operator * (const Bool&, int);
    friend Bool operator * (int, const Bool&);
    friend Bool operator ^ (const Bool&, int);
    friend Bool operator ^ (int, const Bool&);
    friend ostream& operator << (ostream&, const Bool&);

private:
    bool value = false;

public:
    Bool(bool value) {
        this->value = value;
    }

    //Перевантаження операторів за допомогою методів класу
    bool operator == (const Bool& other) const { //Перевантаження оператора ==
        return value == other.value;
    }

    bool operator != (const Bool& other) const { //Перевантаження оператора !=
        return value != other.value;
    }
};

//Перевантаження операторів за допомогою дружніх функцій
//Дружні функції для здійснення операцій зі змінними класу Bool
Bool operator + (const Bool& o1, const Bool& o2) { //Перевантаження оператора + для логічного АБО
    return Bool{ o1.value || o2.value };
}

Bool operator * (const Bool& o1, const Bool& o2) { //Перевантаження оператора * для логічного І
    return Bool{ o1.value && o2.value };
}

Bool operator ^ (const Bool& o1, const Bool& o2) { //Перевантаження оператора ^ для ВИКЛЮЧНОГО АБО
    return Bool{ o1.value != o2.value };
}

//Дружні функції для здійснення операцій зі змінними вбудованого int  
Bool operator + (const Bool& obj, int val) {
    return Bool{ obj.value || (val != 0) };
}

Bool operator + (int val, const Bool& obj) {
    return Bool{ (val != 0) || obj.value };
}

Bool operator * (const Bool& obj, int val) {
    return Bool{ obj.value && (val != 0) };
}

Bool operator * (int val, const Bool& obj) {
    return Bool{ (val != 0) && obj.value };
}

Bool operator ^ (const Bool& obj, int val) {
    return Bool{ obj.value != (val != 0) };
}

Bool operator ^ (int val, const Bool& obj) {
    return Bool{ (val != 0) != obj.value };
}

//Перевантаження оператора << для зручного виводу на екран
ostream& operator << (ostream& stream, const Bool& obj) {
    stream << (obj.value ? "true" : "false");
    return stream;
}

int main()
{
    int x = 1, y = 0;
    Bool a(true);
    Bool b(false);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Значення змінної A типу Bool: " << a << endl;
    cout << "Значення змінної B типу Bool: " << b << endl << endl;

    Bool c = a + b;
    cout << "Значення змінної C після операції A + B (АБО): " << c << endl;

    Bool d = a * b;
    cout << "Значення змінної D після операції A * B (І): " << d << endl;

    Bool e = a ^ b;
    cout << "Значення змінної E після операції A ^ B (ВИКЛЮЧНЕ АБО): " << e << endl;

    cout << endl << "Значення змінної X: " << x << endl;
    cout << "Значення змінної Y: " << y << endl << endl;

    Bool f = a + x;
    cout << "Значення змінної F після операції A + X: " << f << endl;

    Bool g = y + b;
    cout << "Значення змінної G після операції Y + B: " << g << endl;
}