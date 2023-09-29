//Варіант #9
#include <iostream>
#include <windows.h>
#include <fstream>
#define ROWS 3
#define COLUMNS 3

using namespace std;

//Клас, що характеризує матрицю
class matrix {
    //Оголошуємо дружні функції
    friend istream& operator >> (istream&, matrix&);
    friend ostream& operator << (ostream&, const matrix&);

private:
    int data[ROWS][COLUMNS]; //Двомірний масив для збереження матриці

public:
    matrix& operator * (const matrix& other) { //Перевантаження оператора * для множення матриць
        matrix final_matrix;

        //Перебір матриці та виконання операцій множення з ними
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                final_matrix.data[i][j] = 0; //Ініціалізуємо кожен елемент матриці final_matrix нулем
                for (int k = 0; k < COLUMNS; k++)
                    final_matrix.data[i][j] += this->data[i][k] * other.data[k][j]; //Множення елементів однієї матриці на елементи другої
            }
        }

        return final_matrix;
    }
};

//Читаємо дані з потоку
istream& operator >> (istream& stream, matrix& matrix) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
            stream >> matrix.data[i][j];

    return stream;
}

//Записуємо дані в потік
ostream& operator << (ostream& stream, const matrix& matrix) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++)
            stream << matrix.data[i][j] << " ";
        stream << endl;
    }

    return stream;
}

int main()
{
    matrix first_matrix, second_matrix, final_matrix;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input("input.txt"); //Використовуємо конструктор класу ifstream для відкриття файлу для зчитування
    input >> first_matrix; //Введення із файлу елементів першої матриці
    input >> second_matrix; //Введення із файлу елементів другої матриці
    input.close(); //Закриваємо файл

    final_matrix = first_matrix * second_matrix; //Множення матриці на матрицю

    ofstream output("output.txt"); //Використовуємо конструктор класу ofstream для відкриття файлу для запису
    output << final_matrix; //Виведення результату множення матриць в файл
    output.close(); //Закриваємо файл

    cout << "Результат множення матриць був записаний у файл!" << endl;
}