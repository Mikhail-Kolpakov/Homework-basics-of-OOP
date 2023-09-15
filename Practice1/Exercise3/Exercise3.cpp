#include <iostream>
#include <windows.h>

using namespace std;

void zarplata(const char* s, int days = 24, float rascenka = 30.5, float premia = 0, float coef_slojnosti = 1.3);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    zarplata("Андрій"); //Працював 24 дні по 30.5 грн/день з премією 0 грн. та коеф. праці 1.3
    zarplata("Степан", 26); //Працював 26 днів по 30.5 грн/день з премією 0 грн. та коеф. праці 1.3
    zarplata("Микола", 24, 41); //Працював 24 дні по 41 грн/день з премією 0 грн. та коеф. праці 1.3
    zarplata("Йосип", 26, 34.5, 400); //Працював 26 днів по 34.5 грн/день з премією 400 грн. та коеф. праці 1.3
    zarplata("Сергій", 25, 29.8, 350, 1.9); //Працював 25 днів по 29.8 грн/день з премією 350 грн. та коеф. праці 1.9
}

void zarplata(const char* s, int days, float rascenka, float premia, float coef_slojnosti)
{
    cout << s << " заробив " << days * rascenka * coef_slojnosti  << " грн." << " та премію " << 
        premia << " грн." << endl;
}