//Варіант #9
#include <iostream>
#include <windows.h>
#include <random>

using namespace std;

void generate_true_or_false(bool&);

int main()
{
    bool is_true_or_false;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < 10; i++) {
        generate_true_or_false(is_true_or_false);
        if (is_true_or_false)
            cout << "Згенерувалось true" << endl;
        else
            cout << "Згенерувалось false" << endl;
    }
}

void generate_true_or_false(bool &variable) { //Функція для генерування true або false
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> distribution(0, 1);
    variable = distribution(gen) == 1;
}