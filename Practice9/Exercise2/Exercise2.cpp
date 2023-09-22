//Варіант #9
#include <iostream>
#include <windows.h>
#include <iomanip>
#define MAX_NAME_LENGTH 100

using namespace std;

//Перерахування, що характеризує для кого призначена річ
enum class ForWhom {
    Boy,
    Girl
};

//Клас, що характеризує товар
class goods {
protected:
    char name[MAX_NAME_LENGTH]; //Назва товару
    char made_in[MAX_NAME_LENGTH]; //Де виготовлено товар
    float price; //Ціна товару

public:
    goods(const char* name, const char* made_in, float price) {
        strncpy_s(this->name, name, MAX_NAME_LENGTH); //Копіюємо вміст рядка name в масив this->name
        this->name[MAX_NAME_LENGTH - 1] = '\0'; //Перконуємося, що рядок закінчується нульовим символом
        strncpy_s(this->made_in, made_in, MAX_NAME_LENGTH);
        this->made_in[MAX_NAME_LENGTH - 1] = '\0';
        this->price = price;
    }

    void output() { //Функція для виведення даних
        cout << "Назва: " << name << endl;
        cout << "Зроблено в: " << made_in << endl;
        cout << "Ціна: " << fixed << setprecision(2) << price << " грн." << endl;
    }
};

//Клас, що характеризує іграшку
class toy : public goods {
private:
    ForWhom for_whom; //Для кого призначена іграшка
    int recommended_min_age; //Мінімальний рекомендаційний вік для користування іграшкою
    char color[MAX_NAME_LENGTH]; //Колір іграшки

public:
    //Виклик конструктора базового класу
    toy(const char* name, const char* made_in, float price, ForWhom for_whom, int recommended_min_age, const char* color) : goods(name, made_in, price) {
        this->for_whom = for_whom;
        this->recommended_min_age = recommended_min_age;
        strncpy_s(this->color, color, MAX_NAME_LENGTH);
        this->color[MAX_NAME_LENGTH - 1] = '\0';
    }

    void output() { //Функція для виведення даних
        goods::output(); //Виклик методу базового класу з похідного класу
        cout << "Для кого призначена: " << (for_whom == ForWhom::Boy ? "хлопчик" : "дівчинка") << endl;
        cout << "Рекомендаційний вік: " << recommended_min_age << '+' << endl;
        cout << "Колір: " << color << endl;
    }
};

//Клас, що характеризує продукт
class product : protected goods {
protected:
    float weight; //Вага продукта

public:
    //Виклик конструктора базового класу
    product(const char* name, const char* made_in, float price, float weight) : goods(name, made_in, price) {
        this->weight = weight;
    }

    void output() { //Функція для виведення даних
        goods::output(); //Виклик методу базового класу з похідного класу
        cout << "Вага: " << fixed << setprecision(2) << weight << " кг" << endl;
    }
};

//Клас, що характеризує молочний продукт
class milk_product : public product {
private:
    char expiration_date[MAX_NAME_LENGTH]; //Термін придатності

public:
    //Виклик конструктора базового класу
    milk_product(const char* name, const char* made_in, float price, float weight, const char* expiration_date) : product(name, made_in, price, weight) {
        strncpy_s(this->expiration_date, expiration_date, MAX_NAME_LENGTH);
        this->expiration_date[MAX_NAME_LENGTH - 1] = '\0';
    }

    void output() { //Функція для виведення даних
        product::output(); //Виклик методу наслідуваного класу з похідного класу
        cout << "Термін придатності: " << expiration_date << endl;
    }
};

int main()
{
    goods goods("годинник", "Швейцарія", 23480);
    toy toy("машинка Nissan Leaf", "Китай", 340, ForWhom::Boy, 6, "сріблястий");
    product product("печиво", "Україна", 58.75f, 0.25f);
    milk_product milk_product("сметана", "Польща", 35.5f, 0.45f, "до 15 травня 2024 року"); 

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Інформація щодо товару: " << endl;
    goods.output();

    cout << endl << "Інформація щодо іграшки: " << endl;
    toy.output();

    cout << endl << "Інформація щодо продукту: " << endl;
    product.output();

    cout << endl << "Інформація щодо молочного продукту: " << endl;
    milk_product.output();

    //Будуємо граф наслідування класів у консолі
    cout << endl << endl << "Ієрархія наслідування класів у вигляді графу: " << endl << endl << endl;
    cout << "                                    товар(goods)" << endl;
    cout << "                                      /" << "       \\" << endl;
    cout << "                                     /" << "         \\" << endl;
    cout << "                        продукт(product)" << "      іграшка(toy)" << endl;
    cout << "                            /" << endl;
    cout << "                           /" << endl;
    cout << "молочний продукт(milk_product)" << endl << endl;
}