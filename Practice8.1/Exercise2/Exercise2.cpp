//Варіант #9
#include <iostream>
#include <windows.h>

using namespace std;

//Клас, що описує матрицю
class matrix {
private:
    float** pf;
    int rows, columns;
public:
    void input_size_of_matrix();
    void input_values_for_matrix();
    void output();
    friend void check_sizes_of_matrix(matrix&, matrix&);
    friend matrix operator * (matrix&, matrix&);
};

void matrix::input_size_of_matrix() { //Метод для вводу розмірностей матриці
    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;
    cout << "Введіть кількість стовпчиків матриці: ";
    cin >> columns;
}

void matrix::input_values_for_matrix() { //Метод для вводу значень для матриці
    cout << endl << "Заповніть матрицю з розмірністю [" << rows << "][" << columns << "] значеннями: " << endl;
    pf = new float* [rows]; //Виділяємо пам'ять для rows рядків
    for (int i = 0; i < rows; i++) { //Заповнюємо матрицю значеннями
        pf[i] = new float[columns]; //Виділяємо пам'ять для columns стовпчиків в кожному рядку
        for (int j = 0; j < columns; j++) {
            cout << "Введіть значення для елементу з індексом[" << i << "][" << j << "]: ";
            cin >> pf[i][j];
        }
    }
}

void matrix::output() { //Метод для виводу матриці
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << pf[i][j] << "\t";
        cout << endl;
    }
}

void check_sizes_of_matrix(matrix& a, matrix& b) { //Функція для перевірки двох матриць на придатність для множення
    while (a.columns != b.rows) {
        cout << endl << "Введена не коретна розмірність другої матриці!" << endl 
            << "Кількість стовпців першої матриці повинна дорівнювати кількості рядків другої матриці" << endl 
            << "Введіть занчення ще раз: " << endl;
        b.input_size_of_matrix();
    }
}

int main()
{
    matrix a, b; //Початкові дві матриці для майбутнього множення

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть значення для матриці A: " << endl;
    a.input_size_of_matrix();
    a.input_values_for_matrix();
    cout << endl << "Після введення матриця A має вигляд: " << endl;
    a.output();

    cout << endl << "Введіть значення для матриці B: " << endl;
    b.input_size_of_matrix();
    check_sizes_of_matrix(a, b);
    b.input_values_for_matrix();
    cout << endl << "Після введення матриця B має вигляд: " << endl;
    b.output();

    matrix c; //Матриця, яка буде результатом множення двох матриць A та B
    c = a * b; //Множення двох матриць
    cout << endl << "Після множення матриць кінцева матриця C має вигляд: " << endl;
    c.output();
}

matrix operator * (matrix& a, matrix& b) { //Перевантаження оператора != за допомогою дружньої функції
    matrix c;
    c.rows = a.rows;
    c.columns = b.columns;

    //Перебір матриць та операції множення з ними
    c.pf = new float* [c.rows];
    for (int i = 0; i < c.rows; i++) {
        c.pf[i] = new float[c.columns];
        for (int j = 0; j < c.columns; j++) {
            c.pf[i][j] = 0; //Ініціалізуємо кожен елемент матриці C нулем
            for (int k = 0; k < a.columns; k++)
                c.pf[i][j] += a.pf[i][k] * b.pf[k][j]; //Множення елементів матриці A та B
        }
    }

    return c;
}