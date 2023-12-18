// Варіант #9
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

// Клас, що характеризує вектор
class vector {
private:
    float* array; // Вектор - одновимірний масив
    int size; // Кількість елементів вектора

public:
    vector() : array(nullptr), size(0) {}

    ~vector() {
        delete[] array;
    }

    int count_elements_less_than_average() const { // Метод для обчислення кількості елементів менших за середнє 
        if (size == 0) // Якщо вектор порожній, повертаємо 0
            return 0;

        float sum = 0;

        for (int i = 0; i < size; i++) // Рахуємо суму всії елементів вектору
            sum += array[i];

        float average = sum / size; // Вираховуємо середнє значення
        int count = 0;

        for (int i = 0; i < size; i++) // Знаходимо кількість елементів менших за середнє значення
            if (array[i] < average)
                count++;

        return count;
    }

    friend istream& operator >> (istream& stream, vector& vec) { //Читаємо дані з потоку
        stream >> vec.size;

        vec.array = new float[vec.size];

        for (int i = 0; i < vec.size; i++)
            stream >> vec.array[i];

        return stream;
    }

    friend ostream& operator << (ostream& stream, const vector& vec) { //Записуємо дані в потік
        for (int i = 0; i < vec.size; i++)
            stream << vec.array[i] << " ";

        return stream;
    }

    vector operator * (float value) const { // Перевантажуємо операцію *
        vector result;
        result.size = size;
        result.array = new float[size];

        for (int i = 0; i < size; i++)
            result.array[i] = array[i] * value;

        return result;
    }

    vector operator -= (const vector& other) { // Перевантажуємо операцію -=
        for (int i = 0; i < size; i++)
            array[i] -= other.array[i];

        return *this;
    }
};

int main()
{
    vector A, B, C; // Вектори
    float R; // Дійсне число

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input_file("input.txt"); // Відкриваємо файл(за допомогою конструктора) для зчитування

    if (!input_file.is_open()) { // Якщо файл не відкрився
        cout << "Не вдалося відкрити файл input.txt для зчитування" << endl;
        exit(1);
    }

    input_file >> A >> R;
    input_file.close(); // Закриваємо файл

    C = A * R;
    B -= C;

    int count = C.count_elements_less_than_average();

    ofstream output_file("output.txt"); // Відкриваємо файл(за допомогою конструктора) для запису

    if (!output_file.is_open()) { // Якщо файл не відкрився
        cout << "Не вдалося відкрити файл output.txt для запису" << endl;
        exit(1);
    }

    output_file << C;
    output_file << "\nКількість елементів менших за середнє: " << count;
    output_file.close(); // Закриваємо файл
}
