//Варіант #9
#include <iostream>
#include <windows.h>
#define MAX_NAME_LENGTH 100

using namespace std;

//Клас, що характерихує випробування
class trial {
protected:
    char subject[MAX_NAME_LENGTH]; //Предмет з якого проводиться
    int grade; //Оцінка

public:
    trial(const char* subject, int grade) {
        strncpy_s(this->subject, subject, MAX_NAME_LENGTH); //Копіюємо вміст рядка subject в масив this->subject
        this->subject[MAX_NAME_LENGTH - 1] = '\0'; //Переконуємося, що рядок закінчується нульовим символом
        this->grade = grade;
    }

    //Створюємо віртуальний метод
    virtual void output() {
        cout << "Предмет з якого проводиться: " << subject << endl;
        cout << "Оцінка: " << grade << " балів" << endl;
    }

    virtual ~trial() {} //Створюємо віртуальний деструктор
};

//Клас, що характеризує екзамен
class exam : public trial {
protected:
    int duration_min; //Тривалість в хвилинах

public:
    exam(const char* subject, int grade, int duration_min) : trial(subject, grade) {
        this->duration_min = duration_min;
    }

    //Явним чином вказуємо, що метод перевизначен
    void output() override {
        trial::output();
        cout << "Тривалість: " << duration_min << " хв." << endl;
    }
};

//Клас, що характеризує випускний екзамен
class final_exam : public exam {
private:
    int passing_grade; //Прохідний бал

public:
    final_exam(const char* subject, int grade, int duration_min, int passing_grade) : exam(subject, grade, duration_min) {
        this->passing_grade = passing_grade;
    }

    //Явним чином вказуємо, що метод перевизначен
    void output() override {
        exam::output();
        cout << "Прохідний бал: " << passing_grade << " балів" << endl;
    }
};

//Клас, що характеризує тест
class test : public trial {
private:
    char topic[MAX_NAME_LENGTH]; //Тема тесту
    int questions_number; //Кількість питань

public:
    test(const char* subject, int grade, const char* topic, int questions_number) : trial(subject, grade) {
        strncpy_s(this->topic, topic, MAX_NAME_LENGTH);
        this->topic[MAX_NAME_LENGTH - 1] = '\0';
        this->questions_number = questions_number;
    }

    //Явним чином вказуємо, що метод перевизначен
    void output() override {
        trial::output();
        cout << "Тема тесту: " << topic << endl;
        cout << "Кількість питань: " << questions_number << " шт." << endl;
    }
};

int main()
{
    trial biology_trial("Біологія", 10);
    exam english_exam("Англійска мова", 8, 25);
    final_exam algebra_final_exam("Алгебра", 11, 40, 10);
    test history_test("Історія України", 8, "Україна в часи другої світової війни", 24);
    trial* trial(&biology_trial); //Створюємо покажчик та надаємо йому посилання на об'єкт biology_trial

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    trial->output(); //Викликаємо через покажчик метод output

    cout << endl;

    trial = &english_exam; //Надаємо покажчику посилання на об'єкт english_exam
    trial->output();

    cout << endl;

    trial = &algebra_final_exam;
    trial->output();

    cout << endl;

    trial = &history_test;
    trial->output();
}