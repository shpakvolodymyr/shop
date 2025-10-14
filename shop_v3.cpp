#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <limits>
using namespace std;

struct Good{
    string name;
    int amount;
    double price;
};


void def1(vector<Good>& goods) {
    Good temp;
    cout << "Введіть назву товару: ";
    bool break_indicator = 0;
    do {
        break_indicator = 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, temp.name);
        for (int i = 0; i < goods.size(); i++) {
            if (temp.name == goods[i].name) {
                cout << "Такий товар вже існує, введіть інший: ";
                break_indicator = 1;
            }
        }
    }while (break_indicator == 1);
    while (true) {
        cout << "Введіть кількість товару: ";
        cin >> temp.amount;
        while (temp.amount < 0) {
            cout << "Кількість повинна бути додатньою " << endl;
            cin >> temp.amount;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Помилка! Треба ввести ціле число: ";
        }
        else {
            break;
        }
    }
    while (true) {
        cout << "Введіть ціну товару: ";
        cin >> temp.price;
        while (temp.price < 0) {
            cout << "Ціна повинна бути додатньою " << endl;
            cin >> temp.price;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Помилка! Треба ввести число: ";
        }
        else {
            break;
        }
    }
    goods.push_back(temp);
    cout << "Товар додано успішно" << endl;
}

void def2(vector<Good>& goods){
    if (goods.empty()) {
        cout << "В реєстрі поки némає товарів " << endl;
        return;
    }

    bool break_indicator = false;
    do {
        bool found = false;
        string name;
        cout << "Введіть назву товару який потрібно видалити або 0 щоб відмінити операцію: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        if (name == "0") {
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
            cout << "Такого товару не існує" << endl;
        }
    } while (break_indicator);
}


void def3(vector<Good>&goods){
    if (goods.empty()) {
        cout << "В реєстрі немає товарів!" << endl;
        return;
    }
    string name;
    cout << "Введіть назву товару щоб дізнатися його параметри: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    bool found = 0;
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name) {
            cout << endl << "Кількість: " << goods[i].amount << endl << "Ціна: " << goods[i].price << endl;
            found = 1;
            break;
        }
    }
    if(!found) {
        cout << "Товар не знайдено!" << endl;
    }
}

void def4(vector<Good>&goods){
    if (goods.empty()) {
        cout << "В реєстрі немає товарів!" << endl;
        return;
    }

    int choice;
    cout << "Виберіть дію\n[0]Купити товар\n[1]Завезти товар\n";
    cin >> choice;

    if(choice == 0){
        string name;
        int purchase_amount;
        cout << "Введіть назву товару для покупки: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "Введіть кількість для покупки: ";
        cin >> purchase_amount;

        bool found = false;
        for (int i = 0; i < goods.size(); i++) {
            if(goods[i].name == name) {
                found = true;
                if(goods[i].amount >= purchase_amount) {
                    goods[i].amount -= purchase_amount;
                    cout << "Покупка успішна! Залишилось: " << goods[i].amount << endl;
                } else {
                    cout << "Недостатньо товару! Доступно: " << goods[i].amount << endl;
                }
                break;
            }
        }
        if(!found) {
            cout << "Товар не знайдено!" << endl;
        }
    }
    else if(choice == 1){
        string name;
        int amount;
        cout << "Введіть назву товару який треба завести: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "Введіть скільки товару завезли: ";
        cin >> amount;

        bool found = false;
        for (int i = 0; i < goods.size(); i++) {
            if(goods[i].name == name) {
                goods[i].amount += amount;
                cout << "Товар завезено! Тепер на складі: " << goods[i].amount << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "Товар не знайдено!" << endl;
        }
    }
    else {
        cout << "Невірний вибір!" << endl;
    }
}

    void def5(vector<Good>& goods) {
    if (goods.empty()){
        cout << "В реєстрі поки немає товарів " << endl;
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
            cout << "Всі товари безкоштовні " << endl;
        }
        else
            cout << most_expensive_name << ", ціна: " << most_expensive << endl;
    }


    void def6(vector<Good>& goods){
        if (goods.empty()) {
            cout << "В реєстрі поки немає товарів "<<endl;
            return;
        }
        cout << "Всі товари: " << endl;
        for(int i = 0; i < goods.size(); i++){
            cout << goods[i].name << endl;
        }
    }

    void def7(vector<Good>& goods){
        if (goods.empty()) {
            cout << "В реєстрі поки немає товарів ";
            return;
        }
        double S = 0;
        for (int i = 0; i < goods.size(); i++) {
            S += goods[i].price * goods[i].amount;
        }
        cout << "Ціна всіх товарів: " << S << endl;
    }

void def8(vector<Good>& goods){
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів ";
        return;
    }
    string name;
    cout << "Введіть назву товару для застосування знижки (якщо товар дорожчий за 1000): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    bool found_item = false;

    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name){
            found_item = true;

            if(goods[i].price > 1000){
                goods[i].price *= 0.9;
                cout << "Знижку було зроблено для товару " << name << ". Ціна після знижки: " << goods[i].price << endl;
            }
        }
    }
    if (!found_item) {
        cout << "Товар з назвою " << name << " не знайдено в реєстрі" << endl;
    }
}

    void def9(vector<Good>& goods){
        int goods_cheaper_than_100 = 0;
        for (int i = 0; i < goods.size(); i++) {
            if (goods[i].price < 100) {
                goods_cheaper_than_100 += 1;
                cout << "Товар дешевший за 100: " << goods[i].name << endl;
            }
        }
        if (goods_cheaper_than_100 == 0)
            cout << "Товарів дешевших за 100 грн немає " << endl;
        else
            cout << "Товарів дешевших за 100: " << goods_cheaper_than_100 << endl;
    }

void def10(vector<Good>& goods) {
    if (goods.empty()) {
        cout << "В реєстрі поки немає товарів" << endl;
        return;
    }
    string name;
    cout << "Введіть назву товару ціну якого потрібно змінити: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    bool found_item = false;
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name){
            found_item = true;
            while (true) {
                cout << "Введіть нову ціну: ";
                cin >> goods[i].price;
                while (goods[i].price < 0) {
                    cout << "Ціна повинна бути додатньою " << endl;
                    cin >> goods[i].price;
                }
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Помилка! Треба ввести число: ";
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
        cout << "Товар з назвою " << name << " не знайдено в реєстрі." << endl;
    }
}

    int main(){
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
        vector<Good> goods;
        int a;
    do {    cout << "============================================" << endl;
            cout<<" __       __"<<endl;
            cout<<"/  \\     /  |"<<endl;
            cout<<"$$  \\   /$$ |  ______   _______   __    __"<<endl;
            cout<<"$$$  \\ /$$$ | /      \\ /       \\ /  |  /  |"<<endl;
            cout<<"$$$$  /$$$$ |/$$$$$$  |$$$$$$$  |$$ |  $$ |"<<endl;
            cout<<"$$ $$ $$/$$ |$$    $$ |$$ |  $$ |$$ |  $$ |"<<endl;
            cout<<"$$ |$$$/ $$ |$$$$$$$$/ $$ |  $$ |$$ \\__$$ |"<<endl;
            cout<<"$$ | $/  $$ |$$       |$$ |  $$ |$$    $$/ "<<endl;
            cout<<"$$/      $$/  $$$$$$$/ $$/   $$/  $$$$$$/  "<<endl;
            cout << "============================================" << endl;
            cout<<endl<<endl<<endl;
            cout << "Виберіть опцію:" << endl;
            cout << "[0]вийти" << endl;
            cout << "[1]додати в реєстр" << endl;
            cout << "[2]забрати з реєстру" << endl;
            cout << "[3]пошук за назвою" << endl;
            cout << "[4]купити n" << endl;
            cout << "[5]знайти найдорожчий товар"<< endl;
            cout << "[6]показати всі товари" << endl;
            cout << "[7]порахувати загальну вартість всіх товарів" << endl;
            cout << "[8]зробити знижку 10% в реєстрі" << endl;
            cout << "[9]порахувати, скільки товарів дешевші за 100 грн" << endl;
            cout << "[10]змінити ціну товара" << endl;
            cout << "============================================" << endl;
            cin >> a;
            switch (a) {
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
            }
        }while (a != 0);
        return 0;
    }