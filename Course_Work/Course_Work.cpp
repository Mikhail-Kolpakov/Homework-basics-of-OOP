//Варіант #9
#define _USE_MATH_DEFINES
#define AMOUNT_OF_ITERATIONS 21
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

//Структура для зберігання діапазону допустимих значень формульних змінних для подальшої перевірки
struct range {
public:
    float min_value;
    float max_value;
};

//Абстрактний клас, що характерихує об'єкт обчислення
class calculation_object {
protected:
    float calculation_parameter[AMOUNT_OF_ITERATIONS]; //Обчислювальний параметр (активна потужність P_alpha)

public:
    //Чисті віртуальні функції
    virtual void read_from_file(const char* file_name) = 0; //Функція для введення даних із файлу
    virtual void calculation_of_the_parameter() = 0; //Функція для розрахунку обчислювального параметра
    virtual void write_to_file(const char* file_name, const char* object_name, bool with_results) const = 0; //Функція для виведення результату та вхідних даних до файлу
    
    virtual ~calculation_object() {} //Створюємо віртуальний деструктор
};

//Клас, що характеризує діелектрик
class dielectric : public calculation_object {
private:
    float u{}; //Діюче значення змінної напруги
    float f{}; //Частоту змінного струму
    float C{}; //Ємність конденсатора
    float tg_delta{}; //Тангенс кута діелектричних втрат

    //Межі вище вказаних полів для подальшої перевірки на коректність зчитаного значення
    const range u_limits = { 1000, 1500 };
    const range f_limits = { 1000, 10000 };
    const range C_limits = { 1000, 4000 };
    const range tg_delta_limits = { 1, 8 };

    float u_value_storage[AMOUNT_OF_ITERATIONS]; //Сберігання значень параметру діючого значення змінної напруги u

    void check_limits_of_value(float value, float min_value, float max_value, const char* variable_name, const char* degree) { //Метод для перевірки зчитаного значення на коректність
        if (value < min_value || value > max_value) {
            cout << "Помилка! Значення для змінної " << variable_name << " " << C << " не входить в інтервал " << min_value << degree << " - " << max_value << degree << endl;
            exit(1);
        }
    }

public:
    dielectric() {} //Порожній конструктор
    
    dielectric(float a, float b, float c, float d) : u(a), f(b), C(c), tg_delta(d) {} //Конструктор з ініціалізацією списком
    
    dielectric(const dielectric& src) { //Конструктор копіювання
        u = src.u;
        f = src.f;
        C = src.C;
        tg_delta = src.tg_delta;

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++) {
            u_value_storage[i] = src.u_value_storage[i];
            calculation_parameter[i] = src.calculation_parameter[i];
        }
    }

    void input() { //Метод для введення розрахункових значень для формули у режимі діалогу
        cout << "Заповніть значення для обрахунків: " << endl;
        cout << "Введіть діюче значення змінної напруги u: ";
        cin >> u;
        cout << "Введіть частоту змінного струму f: ";
        cin >> f;
        cout << "Введіть ємність конденсатора C: ";
        cin >> C;
        cout << "Введіть тангенс кута діелектричних втрат tg_delta: ";
        cin >> tg_delta;

        //Робимо перевірки зчитаних даних на коректність
        check_limits_of_value(u, u_limits.min_value, u_limits.max_value, "u", "");
        check_limits_of_value(f, f_limits.min_value, f_limits.max_value, "f", "");
        check_limits_of_value(C, C_limits.min_value, C_limits.max_value, "C", " * 10^(-12)");
        check_limits_of_value(tg_delta, tg_delta_limits.min_value, tg_delta_limits.max_value, "tg_delta", " * 10^(-3)");
    }

    void read_from_file(const char* file_name) override { //Метод для зчитування вхідних даних з файлу
        ifstream input_file(file_name); //Використовуємо конструктор класу ifstream для відкриття файлу для зчитування

        if (!input_file.is_open()) { //Якщо файл не відкрився
            cout << "Виникли помилки при відкритті файлу " << file_name << " для зчитування" << endl;
            exit(1);
        }

        input_file >> u >> f >> C >> tg_delta;

        //Робимо перевірки зчитаних даних на коректність
        check_limits_of_value(u, u_limits.min_value, u_limits.max_value, "u", "");
        check_limits_of_value(f, f_limits.min_value, f_limits.max_value, "f", "");
        check_limits_of_value(C, C_limits.min_value, C_limits.max_value, "C", " * 10^(-12)");
        check_limits_of_value(tg_delta, tg_delta_limits.min_value, tg_delta_limits.max_value, "tg_delta", " * 10^(-3)");

        if (input_file.fail()) { //Перевіряємо успішність операції зчитування
            cout << "Виникла помилка при зчитування даних з файлу " << file_name << endl;
            exit(1);
        }

        input_file.close(); //Закриваємо файл
    }

    void calculation_of_the_parameter() override { //Метод для проведення головних розрахунків
        float temp_u = u;
        const float temp_C = static_cast<float>(C * 1e-12);
        const float temp_tg_delta = static_cast<float>(tg_delta * 1e-3);
        const float step = (u_limits.max_value - u) / (AMOUNT_OF_ITERATIONS - 1); //Крок Δ для табуляції змінної u
        
        for (int i = 0; i <= AMOUNT_OF_ITERATIONS; i++, temp_u += step) { //Основний обчислювальний цикл
            calculation_parameter[i] = static_cast<float>(pow(temp_u, 2) * 2 * M_PI * f * temp_C * temp_tg_delta);
            u_value_storage[i] = temp_u;
        }
    }

    void write_to_file(const char* file_name, const char* object_name, bool with_results) const override { //Метод для дозапису даних до файлу
        ofstream output_file(file_name, ios::app); //Використовуємо конструктор класу ofstream для відкриття файлу для дозапису

        if (!output_file.is_open()) { //Якщо файл не відкрився
            cout << "Виникли помилки при відкритті файлу " << file_name << "для запису" << endl;
            exit(1);
        }

        //Заносимо початкові дані
        output_file << "Значення змінних (об'єкт " << object_name << "): " << endl;
        output_file << fixed << setprecision(2) << "u = " << u << " В" << endl;
        output_file << "f = " << f << " Гц" << endl;
        output_file << "C = " << C << " * 10^(-12) ф" << endl;
        output_file << "tg_delta = " << tg_delta << " * 10^(-3)" << endl << endl;

        if (with_results) {
            //Заносимо результати розрахунків
            output_file << "Результати розрахунків: " << endl;
            for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
                output_file << fixed << setprecision(4) << i + 1 << ".\tu = " << u_value_storage[i] << "\t\tP_alpha = " << calculation_parameter[i] << endl;
        }

        output_file.close(); //Закриваємо файл
    }

    //Перевантаження операторів за допомогою методів класу
    bool operator == (const dielectric& other) const { //Перевантаження оператора ==
        return !(*this < other) && !(other < *this);
    }

    bool operator != (const dielectric& other) const { //Перевантаження оператора !=
        return !(*this == other);
    }

    bool operator > (const dielectric& other) const { //Перевантаження оператора >
        return other < *this;
    }

    bool operator < (const dielectric& other) const { //Перевантаження оператора <
        bool temp = true;

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
            if (!(calculation_parameter[i] < other.calculation_parameter[i]))
                temp = false;

        return temp;
    }

    bool operator >= (const dielectric& other) const { //Перевантаження оператора >=
        return !(*this < other);
    }

    bool operator <= (const dielectric& other) const { //Перевантаження оператора <=
        return !(*this > other);
    }

    dielectric& operator = (const dielectric& other) { //Перевантаження оператора =
        if (this == &other) //Перевірка на самоприсвоювання
            return *this;

        u = other.u;
        f = other.f;
        C = other.C;
        tg_delta = other.tg_delta;

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++) {
            u_value_storage[i] = other.u_value_storage[i];
            calculation_parameter[i] = other.calculation_parameter[i];
        }

        return *this;
    }
};

int main()
{
    dielectric a;
    dielectric b(1360, 3000, 3000, 4);
    b.calculation_of_the_parameter();
    dielectric c(1200, 2100, 2950, 3);
    c.calculation_of_the_parameter();
    dielectric d(c);
    const char input_file_name[] = "input.txt";
    const char output_file_name[] = "output.txt";

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream output_app_file(output_file_name, ios::app); //Використовуємо конструктор класу ofstream для відкриття файлу для дозапису

    if (!output_app_file.is_open()) { //Якщо файл не відкрився
        cout << "Виникли помилки при відкритті файлу " << output_file_name << "для запису" << endl;
        exit(1);
    }

    //Перевірка роботи різних видів конструкторів
    output_app_file << "---------------Тестування роботи конструкторів---------------" << endl << endl;
    output_app_file << "Пустий конструктор: " << endl;
    a.write_to_file(output_file_name, "a", false);
    output_app_file << "Конструктор ініціалізації списком: " << endl;
    b.write_to_file(output_file_name, "b", false);
    output_app_file << "Конструктор копіювання: " << endl;
    d.write_to_file(output_file_name, "d", false);

    output_app_file << endl << "---------------Тестування зчитування з файлу---------------" << endl << endl;

    a.read_from_file(input_file_name); //Зчитуємо вхідні дані з файлу
    a.calculation_of_the_parameter(); //Робимо розрахунки на основі зчитаних даних
    output_app_file << "Дані для об'єкту a були зчитані з файлу" << endl << endl;
    a.write_to_file(output_file_name, "a", true); //Записуємо вхідні дані та результати розрахунків у вихідний файл

    //Демонструємо роботу перевантажених операторів
    output_app_file << endl << endl << "---------------Тестування перевантажених операторів---------------" << endl << endl;
    output_app_file << "Інформація щодо об'єкту X: " << endl;
    b.write_to_file(output_file_name, "b", true);

    output_app_file << endl << "Інформація щодо об'єкту Y: " << endl;
    c.write_to_file(output_file_name, "c", true);

    output_app_file << endl << "Оператор == між об'єктом X та Y: " << endl;
    output_app_file << "Результат = " << boolalpha << (b == c) << endl << endl;

    output_app_file << "Оператор != між об'єктом X та Y: " << endl;
    output_app_file << "Результат = " << boolalpha << (b != c) << endl << endl;

    output_app_file << "Оператор > між об'єктом X та Y: " << endl;
    output_app_file << "Результат = " << boolalpha << (b > c) << endl << endl;

    output_app_file << "Оператор < між об'єктом X та Y: " << endl;
    output_app_file << "Результат = " << boolalpha << (b < c) << endl << endl;

    output_app_file << "Оператор >= між об'єктом X та Y: " << endl;
    output_app_file << "Результат = " << boolalpha << (b >= c) << endl << endl;

    output_app_file << "Оператор <= між об'єктом X та Y: " << endl;
    output_app_file << "Результат = " << boolalpha << (b <= c) << endl << endl;

    d.input(); //Перевірка роботи функцій для встановлення значень вручну
    output_app_file << endl << "---------------Тестування зчитування з клавіатури---------------" << endl << endl;
    d.calculation_of_the_parameter();
    d.write_to_file(output_file_name, "d", true);
}