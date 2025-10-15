#include <iostream>
#include <vector>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct Good{
    string name;
    int amount;
    double price;
};

void def1(vector<Good>& goods) {
    Good temp;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введіть назву товару або '-' щоб вийти з функції: ";
    bool break_indicator;
    do {
        break_indicator = false;
        getline(cin, temp.name);
        if (temp.name == "-")
            return;

        for (int i = 0; i < goods.size(); i++) {
            if (temp.name == goods[i].name) {
                cout << "Помилка! Такий товар вже існує, введіть інший або '-' щоб вийти з функції: ";
                break_indicator = true;
                break;
            }
        }
    } while (break_indicator);

    while (true) {
        cout << "Введіть кількість товару: ";
        cin >> temp.amount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Треба ввести ціле число: ";
        }
        else if (temp.amount < 0) {
            cout << "Помилка! Кількість повинна бути додатньою: ";
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Введіть ціну товару: ";
        cin >> temp.price;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Треба ввести число: ";
        }
        else if (temp.price < 0) {
            cout << "Помилка! Ціна повинна бути додатньою: ";
        }
        else {
            break;
        }
    }
    goods.push_back(temp);
    cout << "Товар додано успішно" << endl;
}

void def2(vector<Good>& goods){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }

    bool break_indicator = false;
    do {
        bool found = false;
        string name;
        cout << "Введіть назву товару який потрібно видалити або '-' щоб вийти з функції: ";
        getline(cin, name);

        if (name == "-") {
            return;
        }

        for(int i = 0; i < goods.size(); i++) {
            if (goods[i].name == name) {
                goods.erase(goods.begin() + i);
                cout << "Товар \"" << name << "\" успішно видалено!" << endl;
                found = true;
                break_indicator = false;
                break;
            }
        }

        if (!found) {
            break_indicator = true;
            cout << "Помилка! Такого товару не існує" << endl;
        }
    } while (break_indicator);
}

void def3(vector<Good>&goods){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (goods.empty()) {
        cout << "В реєстрі немає товарів!" << endl;
        return;
    }
    string name;
    cout << "Введіть назву товару щоб дізнатися його параметри або '-' щоб вийти з функції: ";
    getline(cin, name);
    if (name == "-") {
        return;
    }
    bool found = false;
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name) {
            cout << endl << "Кількість: " << goods[i].amount << endl
                 << "Ціна: " << goods[i].price << endl
                 << "Загальна вартість всього товару: " << goods[i].amount * goods[i].price << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Помилка! Товар не знайдено!" << endl;
    }
}

void def4(vector<Good>&goods){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (goods.empty()) {
        cout << "В реєстрі немає товарів!" << endl;
        return;
    }

    int choice;
    cout << "Виберіть дію\n[0]Купити товар\n[1]Завезти товар\n";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Помилка! Невірний вибір!" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(choice == 0){
        string name;
        cout << "Введіть назву товару для покупки або '-' щоб вийти з функції: ";
        getline(cin, name);
        if (name == "-") {
            return;
        }
        bool found = false;
        for (int i = 0; i < goods.size(); i++) {
            if(goods[i].name == name) {
                found = true;
                bool purchase_success = false;
                int purchase_amount;
                do{
                    cout << "Введіть скільки купити: ";
                    cin >> purchase_amount;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Помилка! Треба ввести ціле число." << endl;
                    }
                    else if(purchase_amount <= 0) {
                        cout << "Помилка! Кількість повинна бути додатньою!" << endl;
                    }
                    else if(goods[i].amount >= purchase_amount) {
                        goods[i].amount -= purchase_amount;
                        cout << "Покупка успішна! Залишилось: " << goods[i].amount << endl;
                        purchase_success = true;
                    } else {
                        cout << "Помилка! Недостатньо товару! Доступно: " << goods[i].amount << ". Спробуйте ще раз." << endl;
                    }
                } while(!purchase_success);
                break;
            }
        }
        if(!found) {
            cout << "Помилка! Товар не знайдено!" << endl;
        }
    }
    else if(choice == 1){
        string name;
        cout << "Введіть назву товару який треба завести або '-' щоб вийти з функції: ";
        getline(cin, name);
        if (name == "-") {
            return;
        }
        bool found = false;
        for (int i = 0; i < goods.size(); i++) {
            if(goods[i].name == name) {
                int amount;
                do{
                    cout << "Введіть скільки завезти: ";
                    cin >> amount;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Помилка! Треба ввести ціле число." << endl;
                        amount = 0;
                    }
                    else if(amount <= 0) {
                        cout << "Помилка! Кількість повинна бути додатньою!" << endl;
                    }
                } while(amount <= 0);
                goods[i].amount += amount;
                cout << "Товар завезено! Тепер на складі: " << goods[i].amount << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "Помилка! Товар не знайдено!" << endl;
        }
    }
    else {
        cout << "Помилка! Невірний вибір!" << endl;
    }
}

void def5(vector<Good>& goods) {
    if (goods.empty()){
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }
    double most_expensive = 0;
    string most_expensive_name;
    for(int i = 0; i < goods.size(); i++) {
        if (goods[i].price > most_expensive) {
            most_expensive = goods[i].price;
            most_expensive_name = goods[i].name;
        }
    }
    if (most_expensive == 0) {
        cout << "Всі товари безкоштовні" << endl;
    }
    else {
        cout << "Найдорожчий товар: " << most_expensive_name << ", ціна: " << most_expensive << endl;
    }
}

void def6(vector<Good>& goods){
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }
    cout << "Всі товари:" << endl;
    for(int i = 0; i < goods.size(); i++){
        cout << goods[i].name << endl;
    }
}

void def7(vector<Good>& goods){
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }
    double S = 0;
    for (int i = 0; i < goods.size(); i++) {
        S += goods[i].price * goods[i].amount;
    }
    cout << "Ціна всіх товарів: " << S << endl;
}

void def8(vector<Good>& goods){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }
    string name;
    cout << "Введіть назву товару для застосування знижки (якщо товар дорожчий за 1000) або '-' щоб вийти з функції: ";
    getline(cin, name);
    if (name == "-") {
        return;
    }

    bool found_item = false;

    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name){
            found_item = true;

            if(goods[i].price > 1000){
                goods[i].price *= 0.9;
                cout << "Знижку було зроблено для товару " << name << ". Ціна після знижки: " << goods[i].price << endl;
            }
            else {
                cout << "Помилка! Товар дешевший за 1000 грн, неможливо зробити знижку!" << endl;
            }
            break;
        }
    }
    if (!found_item) {
        cout << "Помилка! Товар з назвою " << name << " не знайдено в реєстрі" << endl;
    }
}

void def9(vector<Good>& goods) {
    vector<string> goods_names_cheaper_than_100;
    int goods_cheaper_than_100 = 0;
    for (int i = 0; i < goods.size(); i++) {
        if (goods[i].price < 100) {
            goods_cheaper_than_100++;
            goods_names_cheaper_than_100.push_back(goods[i].name);
        }
    }
    if (goods_cheaper_than_100 == 0) {
        cout << "Товарів дешевших за 100 грн немає" << endl;
    }
    else{
        cout << "Товарів дешевших за 100: " << goods_cheaper_than_100 << endl;
        cout << "Товари дешевші за 100:" << endl;
        for (const string& n : goods_names_cheaper_than_100) {
            cout << n << endl;
        }
    }
}

void def10(vector<Good>& goods) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }
    string name;
    cout << "Введіть назву товару ціну якого потрібно змінити або '-' щоб вийти з функції: ";
    getline(cin, name);
    if (name == "-") {
        return;
    }
    bool found_item = false;
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name){
            found_item = true;
            while (true) {
                cout << "Введіть нову ціну: ";
                cin >> goods[i].price;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Помилка! Треба ввести число: ";
                }
                else if (goods[i].price < 0) {
                    cout << "Помилка! Ціна повинна бути додатньою: ";
                }
                else {
                    break;
                }
            }
            cout << "Ціну товару " << name << " було змінено на " << goods[i].price << endl;
            return;
        }
    }
    if (!found_item) {
        cout << "Помилка! Товар з назвою " << name << " не знайдено в реєстрі." << endl;
    }
}

int main(){
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    vector<Good> goods;
    int a;
    do {
        cout << "============================================" << endl;
        cout << " __       __" << endl;
        cout << "/  \\     /  |" << endl;
        cout << "$$  \\   /$$ |  ______   _______   __    __" << endl;
        cout << "$$$  \\ /$$$ | /      \\ /       \\ /  |  /  |" << endl;
        cout << "$$$$  /$$$$ |/$$$$$$  |$$$$$$$  |$$ |  $$ |" << endl;
        cout << "$$ $$ $$/$$ |$$    $$ |$$ |  $$ |$$ |  $$ |" << endl;
        cout << "$$ |$$$/ $$ |$$$$$$$$/ $$ |  $$ |$$ \\__$$ |" << endl;
        cout << "$$ | $/  $$ |$$       |$$ |  $$ |$$    $$/ " << endl;
        cout << "$$/      $$/  $$$$$$$/ $$/   $$/  $$$$$$/  " << endl;
        cout << "============================================" << endl;
        cout << endl << endl << endl;
        cout << "Виберіть опцію:" << endl;
        cout << "[0]вийти" << endl;
        cout << "[1]додати в реєстр" << endl;
        cout << "[2]забрати з реєстру" << endl;
        cout << "[3]пошук за назвою" << endl;
        cout << "[4]купити або завезти товар" << endl;
        cout << "[5]знайти найдорожчий товар" << endl;
        cout << "[6]показати всі товари" << endl;
        cout << "[7]порахувати загальну вартість всіх товарів" << endl;
        cout << "[8]зробити знижку 10% в реєстрі" << endl;
        cout << "[9]порахувати, скільки товарів дешевші за 100 грн" << endl;
        cout << "[10]змінити ціну товара" << endl;
        cout << "============================================" << endl;
        cin >> a;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Введіть число від 0 до 10" << endl;
            continue;
        }

        switch (a) {
            case 0:
                cout << "Роботу програми завершено" << endl;
                return 0;
            case 1:
                def1(goods);
                break;
            case 2:
                def2(goods);
                break;
            case 3:
                def3(goods);
                break;
            case 4:
                def4(goods);
                break;
            case 5:
                def5(goods);
                break;
            case 6:
                def6(goods);
                break;
            case 7:
                def7(goods);
                break;
            case 8:
                def8(goods);
                break;
            case 9:
                def9(goods);
                break;
            case 10:
                def10(goods);
                break;
            default:
                cout << "Помилка! Невірна опція!" << endl;
                continue;
        }

        int b;
        cout << endl << "Бажаєте продовжити чи завершити?" << endl;
        cout << "[0]Завершити" << endl;
        cout << "[1]Продовжити" << endl;
        cin >> b;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(b){
            case 0:
                cout << "Роботу програми завершено" << endl;
                return 0;
            case 1:
                continue;
            default:
                cout << "Помилка! Невірний вибір! Програма продовжує роботу " << endl;
        }

    } while (a != 0);
    return 0;
}