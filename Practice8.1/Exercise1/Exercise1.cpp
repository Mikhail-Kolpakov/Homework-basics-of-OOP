//Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

//Клас для характеристики комплексного числа
class complex_number {
    friend bool operator != (const complex_number& o1, const complex_number& o2); //Оголошення дружньої функції

private:
    float Re, Im;

public:
    complex_number(float a, float b) {
        Re = a;
        Im = b;
    }

    void output() { //Метод для консольного виводу характеристики комплексного числа 
        cout << "Дійсна частина = " << Re << endl << "Уявна частина = "<< Im << endl << endl;
    }

    //Перевантаження операторів за допомогою методів класу
    complex_number operator - (const complex_number& other) const { //Перевантаження оператора -
        return complex_number{ Re - other.Re, Im - other.Im };
    }

    complex_number& operator *= (const complex_number& other) { //Перевантаження оператора *=
        Re *= other.Re;
        Im *= other.Im;
        return *this;
    }
};

//Перевантаження оператора за допомогою дружньої функції
bool operator != (const complex_number& o1, const complex_number& o2) { //Перевантаження оператора !=
    return (o1.Re != o2.Re) || (o1.Im != o2.Im);
}

int main()
{
    complex_number comp_num1(7, 2);
    complex_number comp_num2(3, 1);
    complex_number comp_num3 = comp_num1 - comp_num2; //Виклик перевантаження оператора - з класу
    bool is_not_equal;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Після операції '-' для comp_num1 та comp_num2: " << endl;

    comp_num3.output();
    comp_num1 *= comp_num3; //Виклик перевантаження оператора *= з класу

    cout << "Після операції '*=' для comp_num1 та comp_num3: " << endl;
    comp_num1.output();

    is_not_equal = comp_num1 != comp_num2; //Виклик перевантаження оператора != з дружньої функції

    cout << "Після операції '!=' для comp_num1 та comp_num2: " << endl;
    cout << "Чи вони нерівні?: " << boolalpha << is_not_equal << endl;
}