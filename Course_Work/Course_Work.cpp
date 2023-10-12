//Варіант #9
#define _USE_MATH_DEFINES
#define AMOUNT_OF_ITERATIONS 21
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

//Абстрактний клас, що характерихує об'єкт обчислення
class calculation_object {
protected:
    float* calculation_parameter = new float[AMOUNT_OF_ITERATIONS]; //Обчислювальний параметр (активна потужність P_alpha)

public:
    //Чисті віртуальні функції
    virtual void read_from_file(const char* file_name) = 0; //Функція для введення даних із файлу
    virtual void calculation_of_the_parameter() = 0; //Функція для розрахунку обчислювального параметра
    virtual void write_to_file(const char* file_name) const = 0; //Функція для виведення результату та вхідних даних до файлу
    
    virtual ~calculation_object() { //Створюємо віртуальний деструктор
        delete[] calculation_parameter;
    }
};

//Клас, що характеризує діелектрик
class dielectric : public calculation_object {
private:
    float u{}; //Діюче значення змінної напруги
    float f{}; //Частоту змінного струму
    float C{}; //Ємність конденсатора
    float tg_delta{}; //Тангенс кута діелектричних втрат

    //Межі вище вказаних змінних
    float u_limit{};
    float f_limit{};
    float C_limit{};
    float tg_delta_limit{};

    float* u_value_storage = new float[AMOUNT_OF_ITERATIONS]; //Сберігання значень параметру діючого значення змінної напруги u

public:
    dielectric() {} //Порожній конструктор
    
    dielectric(float a, float b, float c, float d, float e, float f, float g, float h)
        : u(a), f(b), C(c), tg_delta(d), u_limit(e), f_limit(f), C_limit(g), tg_delta_limit(h) {} //Конструктор з ініціалізацією списком
    
    dielectric(const dielectric& src) { //Конструктор копіювання
        u = src.u;
        f = src.f;
        C = src.C;
        tg_delta = src.tg_delta;
        u_limit = src.u_limit;
        f_limit = src.f_limit;
        C_limit = src.C_limit;
        tg_delta_limit = src.tg_delta_limit;

        delete[] u_value_storage;
        u_value_storage = new float[AMOUNT_OF_ITERATIONS];

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
            u_value_storage[i] = src.u_value_storage[i];

        delete[] calculation_parameter;
        calculation_parameter = new float[AMOUNT_OF_ITERATIONS];

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
            calculation_parameter[i] = src.calculation_parameter[i];
    }

    void input() { //Метод для введення розрахункових значень для формули у режимі діалогу
        cout << "Заповніть початкові значення для обрахунків: " << endl;
        cout << "Введіть початкове діюче значення змінної напруги u: ";
        cin >> u;
        cout << "Ведіть межу для u: ";
        cin >> u_limit;
        cout << "Введіть початкову частоту змінного струму f: ";
        cin >> f;
        cout << "Ведіть межу для f: ";
        cin >> f_limit;
        cout << "Введіть початкову ємність конденсатора C: ";
        cin >> C;
        cout << "Ведіть межу для C: ";
        cin >> C_limit;
        cout << "Введіть початковий тангенс кута діелектричних втрат tg_delta: ";
        cin >> tg_delta;
        cout << "Ведіть межу для tg_delta: ";
        cin >> tg_delta_limit;
    }

    void output() const { //Метод для виведення до консолі розрахункових значень
        cout << "Початкові розрахункові значення: " << endl;
        cout << fixed << setprecision(2) << "u = " << u << " - " << u_limit << " В" << endl;
        cout << "f = " << f << " - " << f_limit << " Гц" << endl;
        cout << "C = (" << C << " - " << C_limit << ") * 10^(-12) ф" << endl;
        cout << "tg_delta = " << tg_delta << " * 10^(-3) - " << tg_delta_limit << " * 10^(-3)" << endl;
    }

    static void operation_test(const dielectric& first_obj, const dielectric& second_obj) { //Метод для консольної демонстрації роботи перевантажених операторів
        dielectric temp_obj; //Тимчасовий об'єкт для проведення операцій присвоєння
        
        cout << "Об'єкт X: " << endl;
        cout << "Інформація щодо об'єкту: " << endl;
        cout << fixed << setprecision(2) << "u = " << first_obj.u << " - " << first_obj.u_limit << " В" << endl;
        cout << "f = " << first_obj.f << " - " << first_obj.f_limit << " Гц" << endl;
        cout << "C = (" << first_obj.C << " - " << first_obj.C_limit << ") * 10^(-12) ф" << endl;
        cout << "tg_delta = " << first_obj.tg_delta << " * 10^(-3) - " << first_obj.tg_delta_limit << " * 10^(-3)" << endl << endl;

        cout << "Об'єкт Y: " << endl;
        cout << "Інформація щодо об'єкту: " << endl;
        cout << fixed << setprecision(2) << "u = " << second_obj.u << " - " << second_obj.u_limit << " В" << endl;
        cout << "f = " << second_obj.f << " - " << second_obj.f_limit << " Гц" << endl;
        cout << "C = (" << second_obj.C << " - " << second_obj.C_limit << ") * 10^(-12) ф" << endl;
        cout << "tg_delta = " << second_obj.tg_delta << " * 10^(-3) - " << second_obj.tg_delta_limit << " * 10^(-3)" << endl << endl;

        cout << "Оператор == між об'єктом X та Y: " << endl;
        cout << "Результат = " << boolalpha << (first_obj == second_obj) << endl << endl;

        cout << "Оператор != між об'єктом X та Y: " << endl;
        cout << "Результат = " << boolalpha << (first_obj != second_obj) << endl << endl;

        cout << "Оператор > між об'єктом X та Y: " << endl;
        cout << "Результат = " << boolalpha << (first_obj > second_obj) << endl << endl;

        cout << "Оператор < між об'єктом X та Y: " << endl;
        cout << "Результат = " << boolalpha << (first_obj < second_obj) << endl << endl;

        cout << "Оператор >= між об'єктом X та Y: " << endl;
        cout << "Результат = " << boolalpha << (first_obj >= second_obj) << endl << endl;

        cout << "Оператор <= між об'єктом X та Y: " << endl;
        cout << "Результат = " << boolalpha << (first_obj <= second_obj) << endl << endl;

        cout << "Оператор += між об'єктом X та Y: " << endl;
        temp_obj = first_obj;
        temp_obj += second_obj;
        temp_obj.output();

        cout << endl << "Оператор -= між об'єктом X та Y: " << endl;
        temp_obj = first_obj;
        temp_obj -= second_obj;
        temp_obj.output();

        cout << endl << "Оператор *= між об'єктом X та Y: " << endl;
        temp_obj = first_obj;
        temp_obj *= second_obj;
        temp_obj.output();

        cout << endl << "Оператор /= між об'єктом X та Y: " << endl;
        temp_obj = first_obj;
        temp_obj /= second_obj;
        temp_obj.output();
    }

    void read_from_file(const char* file_name) override {
        ifstream input_file(file_name); //Використовуємо конструктор класу ifstream для відкриття файлу для зчитування

        if (!input_file.is_open()) { //Якщо файл не відкрився
            cout << "Виникли помилки при відкритті файлу " << file_name << " для зчитування" << endl;
            exit(1);
        }

        input_file >> u >> f >> C >> tg_delta;

        if (input_file.fail()) { //Перевіряємо успішність операції зчитування
            cout << "Виникла помилка при зчитування даних з файлу " << file_name << " (1-ший рядок)" << endl;
            exit(1);
        }

        input_file >> u_limit >> f_limit >> C_limit >> tg_delta_limit;

        if (input_file.fail()) {
            cout << "Виникла помилка при зчитування даних з файлу " << file_name << " (2-гий рядок)" << endl;
            exit(1);
        }
        else
            cout << "Зчитування даних з файлу пройшло успішно" << endl;

        input_file.close(); //Закриваємо файл
    }

    void calculation_of_the_parameter() override {
        float temp_u = u;
        float temp_f = f;
        float temp_C = static_cast<float>(C * pow(10, -12));
        float temp_tg_delta = static_cast<float>(tg_delta * pow(10, -3));
        int i = 0;
        
        while (temp_u <= u_limit) { //Основний обчислювальний цикл
            calculation_parameter[i] = static_cast<float>(pow(temp_u, 2) * 2 * M_PI * temp_f * temp_C * temp_tg_delta);
            u_value_storage[i] = temp_u;

            temp_u += (u_limit - u) / (AMOUNT_OF_ITERATIONS - 1);
            temp_f += (f_limit - f) / (AMOUNT_OF_ITERATIONS - 1);
            temp_C += static_cast<float>((C_limit - C) * pow(10, -12) / (AMOUNT_OF_ITERATIONS - 1));
            temp_tg_delta += static_cast<float>((tg_delta_limit - tg_delta) * pow(10, -3) / (AMOUNT_OF_ITERATIONS - 1));
            i++;
        }
    }

    void write_to_file(const char* file_name) const override {
        ofstream output_file(file_name); //Використовуємо конструктор класу ofstream для відкриття файлу для запису

        if (!output_file.is_open()) { //Якщо файл не відкрився
            cout << "Виникли помилки при відкритті файлу " << file_name << "для запису" << endl;
            exit(1);
        }

        //Заносимо початкові дані
        output_file << "Початкові дані, що визначені за умовою завдання: " << endl;
        output_file << fixed << setprecision(2) << "u = " << u << " - " << u_limit << " В" << endl;
        output_file << "f = " << f << " - " << f_limit << " Гц" << endl;
        output_file << "C = (" << C << " - " << C_limit << ") * 10^(-12) ф" << endl;
        output_file << "tg_delta = " << tg_delta << " * 10^(-3) - " << tg_delta_limit << " * 10^(-3)" << endl << endl;

        //Заносимо результати розрахунків
        output_file << "Результати розрахунків: " << endl;
        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
            output_file << fixed << setprecision(4) << i + 1 << ".\tu = " << u_value_storage[i] << "\t\tP_alpha = " << calculation_parameter[i] << endl;

        cout << "Дані були успішно записані до файлу" << endl;

        output_file.close(); //Закриваємо файл
    }

    ~dielectric() {
        delete[] u_value_storage;
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
        return (u < other.u) && (f < other.f) && (C < other.C) && (tg_delta < other.tg_delta) &&
            (u_limit < other.u_limit) && (f_limit < other.f_limit) && (C_limit < other.C_limit) && (tg_delta_limit < other.tg_delta_limit);
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
        u_limit = other.u_limit;
        f_limit = other.f_limit;
        C_limit = other.C_limit;
        tg_delta_limit = other.tg_delta_limit;

        delete[] u_value_storage;
        u_value_storage = new float[AMOUNT_OF_ITERATIONS];

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
            u_value_storage[i] = other.u_value_storage[i];

        delete[] calculation_parameter;
        calculation_parameter = new float[AMOUNT_OF_ITERATIONS];

        for (int i = 0; i < AMOUNT_OF_ITERATIONS; i++)
            calculation_parameter[i] = other.calculation_parameter[i];

        return *this;
    }

    dielectric& operator += (const dielectric& other) { //Перевантаження оператора +=
        u += other.u;
        f += other.f;
        C += other.C;
        tg_delta += other.tg_delta;
        u_limit += other.u_limit;
        f_limit += other.f_limit;
        C_limit += other.C_limit;
        tg_delta_limit += other.tg_delta_limit;
        return *this;
    }

    dielectric& operator -= (const dielectric& other) { //Перевантаження оператора -=
        u -= other.u;
        f -= other.f;
        C -= other.C;
        tg_delta -= other.tg_delta;
        u_limit -= other.u_limit;
        f_limit -= other.f_limit;
        C_limit -= other.C_limit;
        tg_delta_limit -= other.tg_delta_limit;
        return *this;
    }

    dielectric& operator *= (const dielectric& other) { //Перевантаження оператора *=
        u *= other.u;
        f *= other.f;
        C *= other.C;
        tg_delta *= other.tg_delta;
        u_limit *= other.u_limit;
        f_limit *= other.f_limit;
        C_limit *= other.C_limit;
        tg_delta_limit *= other.tg_delta_limit;
        return *this;
    }

    dielectric& operator /= (const dielectric& other) { //Перевантаження оператора /=
        u /= other.u;
        f /= other.f;
        C /= other.C;
        tg_delta /= other.tg_delta;
        u_limit /= other.u_limit;
        f_limit /= other.f_limit;
        C_limit /= other.C_limit;
        tg_delta_limit /= other.tg_delta_limit;
        return *this;
    }
};

int main()
{
    dielectric a;
    dielectric b(2150, 3000, 3000, 4, 3700, 12450, 7600, 9);
    dielectric c(1600, 2100, 2950, 3, 3600, 8900, 6850, 7);
    dielectric d(c);
    const char input_file[] = "input.txt";
    const char output_file[] = "output.txt";

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Перевірка роботи різних видів конструкторів
    cout << "Пустий конструктор: " << endl << endl;
    a.output();
    cout << endl << endl << "Конструктор ініціалізації списком: " << endl << endl;
    b.output();
    cout << endl << endl << "Конструктор копіювання: " << endl << endl;
    d.output();

    cout << endl << endl;

    a.read_from_file(input_file); //Зчитуємо вхідні дані з файлу
    a.calculation_of_the_parameter(); //Робимо розрахунки на основі зчитаних даних
    a.write_to_file(output_file); //Записуємо вхідні дані та результати розрахунків у вихідний файл

    cout << endl;

    dielectric::operation_test(b, c); //Перевірка роботи перевантажених операторів

    cout << endl << endl;

    d.input(); //Перевірка роботи функцій для встановлення значень вручну
    cout << endl;
    d.output(); //Перевірка роботи функції для виводу значень полів класу
}