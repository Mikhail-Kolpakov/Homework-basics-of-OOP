//Варіант #9
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

//Клас, що описує матрицю
class matrica {
private:
    int** matrix; //Покажчик на двомірний масив
    int rows; //Кількість рядків
    int columns; //Кількість стовпчиків
    int sum; //Сума позитивних елементів
    int positive_numbers_amount; //Кількість позитивних елементів

public:
    //Використовуємо конструктор за замовчування для ініціалізації списком даних класу значеннями за замовчуванням
    matrica() : matrix(nullptr), rows(0), columns(0), sum(0), positive_numbers_amount(0) {}

    void calculate_matrix() { //Метод для проведення розрахунків над матрицею

        //Вираховуємо суму та кількість позитивних елементів матриці
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] > 0) {
                    sum += matrix[i][j];
                    positive_numbers_amount++;
                }
            }
        }

        cout << "Сума позитивних елементів: " << sum << endl;
        cout << "Кількість позитивних елементів: " << positive_numbers_amount << endl;
    }

    void read_from_file(const char* file_name) { //Метод для зчитування з файлу
        ifstream input_file(file_name); //Використовуємо конструктор класу ifstream для відкриття файлу для зчитування

        if (!input_file.is_open()) { //Якщо файл не відкрився
            cout << "Виникли помилки при відкритті файлу для зчитування";
            exit(1);
        }

        input_file >> rows >> columns; //Зчитуємо з файлу кількість рядків та стовпців матриці

        //Виділяємо пам'ять для матриці
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[columns];

        //Зчитуємо з файлу значення для елементів матриці
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                input_file >> matrix[i][j];

        input_file.close(); //Закриваємо файл
    }

    void write_to_file(const char* file_name) { //Метод для запису до файлу
        ofstream output_file(file_name); //Використовуємо конструктор класу ofstream для відкриття файлу для запису

        if (!output_file.is_open()) { //Якщо файл не відкрився
            cout << "Виникли помилки при відкритті файлу для запису";
            exit(1);
        }

        //Виводимо значення до файлу
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                output_file << matrix[i][j] << " ";
            output_file << endl;
        }

        //Заносимо інформацію щодо обрахувань до файлу
        output_file << "Сума позитивних елементів: " << sum << endl;
        output_file << "Кількість позитивних елементів: " << positive_numbers_amount << endl;

        output_file.close(); //Закриваємо файл
    }

    ~matrica() { //Створюємо деструктор для вивільнення пам'яті
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};

int main()
{
    matrica matrix;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    matrix.read_from_file("input.txt"); //Зчитуємо з файлу
    matrix.calculate_matrix(); //Робимо розрахунки
    matrix.write_to_file("output.txt"); //Виводимо до файлу

    cout << endl;
}