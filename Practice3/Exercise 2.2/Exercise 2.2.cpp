//Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

char variable[] = "Я Глобальна змінна. Привіт!";

int main()
{
    char variable[] = "І вам привіт! Я Локальна змінна функції main.";
    bool is_print = false;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << :: variable << endl;
    cout << variable << endl;

    for (int i = 0; i < 3; i++) {
        char variable[] = "А я Локальная змінна циклу for. Привіт!";
        cout << variable << endl;

        is_print = !is_print;
        if (is_print) {
            char variable[] = "Здоровенькі були! Я Локальна змінна умовної операції if.";
            cout << variable << endl;
        }
    }

    cout << ::variable << endl;
    cout << variable << endl;
}
