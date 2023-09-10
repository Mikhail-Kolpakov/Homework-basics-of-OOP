#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

void zarplata(string, int days = 24, float rascenka = 30.5, float premia = 0, float coef_slojnosti = 1.3);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    zarplata("Андрій");
    zarplata("Степан", 26);
    zarplata("Микола", 24, 41);
    zarplata("Йосип", 26, 34.5, 400);
    zarplata("Сергій", 25, 29.8, 350, 1.9);
}

void zarplata(string s, int days, float rascenka, float premia, float coef_slojnosti)
{
    cout << s << " заробив " << days * rascenka * coef_slojnosti  << " грн." << " та премію " << 
        premia << " грн." << endl;
}