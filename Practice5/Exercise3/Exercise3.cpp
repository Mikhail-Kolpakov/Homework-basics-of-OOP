//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define N 10

using namespace std;

class vektor
{
    float x[N]{};

public:
    vektor() { //Порожній конструктор

    }

    vektor(const vektor& b) { //Конструктор копіювання
        for (int i = 0; i < N; i++)
            x[i] = b.x[i];
    }

    void vvod() { //Функція для введення даних
        for (int i = 0; i < N; i++) {
            cout << "Введіть заначення для елементу з індексом [" << i << "]: ";
            cin >> x[i];
        }
    }

    void vivod() { //Функція для виведення даних
        cout << endl << "Значення, що належать вектору: " << endl;
        for (int i = 0; i < N; i++)
            cout << fixed << setprecision(2) << x[i] << " ";
    }

    void multiply(float num) { //Функція для множення всіх елементів на число (за завданням 10)
        for (int i = 0; i < N; i++)
            x[i] *= num;
    }

    float max_v() { //Функція для знаходження максимального значення
        float temp = x[0];

        for (int i = 1; i < N; i++)
            if (x[i] > temp)
                temp = x[i];

        return temp;
    }

//Закоментовано, аби можно було виконувати присвоювання, як потребується за умовою (v3 = v2)
/*private:
    vektor& operator = (const vektor& b);*/
};

int main()
{
    vektor v1, v3;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть значення для для об'єкту класу v1: " << endl;
    v1.vvod();
    v1.vivod();
    cout << endl << "Максимальне значення для вектору v1 = " << fixed << setprecision(2) << v1.max_v();

    vektor v2 = v1;

    cout << endl << endl << "Для об'єкту класу v2: ";
    v2.vivod();
    v2.multiply(10);
    cout << endl << "Множимо всі значення вектора v2 на 10";
    v2.vivod();

    v3 = v2; //Оператором присвоювання

    cout << endl << endl << "Для об'єкту класу v3: ";
    v3.vivod();
    cout << endl << "Максимальне значення для вектору v1 = " << fixed << setprecision(2) << v3.max_v();

    cout << endl;
}
