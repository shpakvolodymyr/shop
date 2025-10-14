#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct Good{
    string name;
    int amount;
    double price;
};


void def1(vector<Good>& goods) {
    Good temp;
    cout << "Введіть назву товару: ";
    cin >> temp.name;
    while (true) {
        cout << "Введіть кількість товару: ";
        cin >> temp.amount;
        while (temp.amount < 0) {
            cout << "Ціна повинна бути додатньою " << endl;
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
        cin >> name;

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
        string name;
        std::cout << "Введіть назву товару щоб дізнатися його параметри: ";
        std::cin >> name;
        for(int i = 0; i < goods.size(); i++){
            if(goods[i].name == name) {
                cout << "\nКількість: " << goods[i].amount << "\nЦіна: " << goods[i].price << endl;
            }
        }
    }

    void def4(vector<Good>&goods){
        bool choice;
        cout << "Виберіть дію\n[0]Купити товар\n[1]Завезти товар\n";
        cin >> choice;
        if(choice == 0){
            cout << "Enter name of good to buy: ";
            string name;
            std::cin >> name;
            cout << "Enter amount of good to buy: ";
            int purchase_amount;
            std::cin >> purchase_amount;
            for (int i = 0; i < goods.size(); i++) {
                if(goods[i].name == name) {
                    goods[i].amount -= purchase_amount;
                }
            }
        }
        if(choice == 1){
            cout << "Введіть назву товару який треба завести: ";
            string name;
            int amount;
            std::cin >> name;
            cout << "\nВведіть скільки товару завезли: ";
            cin >> amount;
            for (int i = 0; i < goods.size(); i++) {
                if(goods[i].name == name) {
                    goods[i].amount += amount;
                }
            }
        }
    }

    void def5(vector<Good>& goods){
        int most_expensive = 0;
        string most_expensive_name;
        for(int i = 0; i < goods.size(); i++) {
            if (goods[i].price > most_expensive) {
                most_expensive = goods[i].price;
                most_expensive_name = goods[i].name;
            }
        }
        cout << most_expensive_name << "; ціна: " << most_expensive << endl;
    }
    void def6(vector<Good>& goods){
        for(int i = 0; i < goods.size(); i++){
            cout << "Всі товари: " << endl;
            cout << goods[i].name << endl;
        }
    }

    void def7(vector<Good>& goods){
        int S = 0;
        for (int i = 0; i < goods.size(); i++) {
            S += goods[i].price * goods[i].amount;
        }
        cout << "Ціна всіх товарів: " << S << endl;
    }

    void def8(vector<Good>& goods){
        string name;
        cin >> name;
        for(int i = 0; i < goods.size(); i++){
            if(goods[i].name == name & (goods[i].price > 1000)){
                goods[i].price *= 0.9;
                cout << "Знижку було зроблено для товару " << name << ". Ціна після знижки: " << goods[i].price << endl;
            }
        }
    }

    void def9(vector<Good>& goods){
        int goods_cheaper_than_100 = 0;
        for (int i = 0; i < goods.size(); i++) {
            if (goods[i].price < 100)
                goods_cheaper_than_100 += 1;
            cout << "Товар дешевший за 100: " << goods[i].name << endl;
        }
        if (goods_cheaper_than_100 == 0)
            std::cout << "Товарів дешевших за 100 грн немає " << endl;
        else
            std::cout << "Товарів дешевших за 100: " << goods_cheaper_than_100 << endl;
    }

    void def10(vector<Good>& goods) {
        string name;
        cout << "Введіть назву товару ціну якого потрібно змінити: ";
        cin >> name;
        for(int i = 0; i < goods.size(); i++){
            if(goods[i].name == name){
                cin >> goods[i].price;
                cout << "Ціну товару " << name << " було змінено на " << goods[i].price << endl;
            }
        }
    }

    int main(){
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
        std::vector<Good> goods;
        int a;
        do {
        cout<<" __       __"<<endl;                               
        cout<<"/  \\     /  |"<<endl;                              
        cout<<"$$  \\   /$$ |  ______   _______   __    __"<<endl;
        cout<<"$$$  \\ /$$$ | /      \\ /       \\ /  |  /  |"<<endl;
        cout<<"$$$$  /$$$$ |/$$$$$$  |$$$$$$$  |$$ |  $$ |"<<endl;
        cout<<"$$ $$ $$/$$ |$$    $$ |$$ |  $$ |$$ |  $$ |"<<endl;
        cout<<"$$ |$$$/ $$ |$$$$$$$$/ $$ |  $$ |$$ \\__$$ |"<<endl;
        cout<<"$$ | $/  $$ |$$       |$$ |  $$ |$$    $$/ "<<endl;
        cout<<"$$/      $$/  $$$$$$$/ $$/   $$/  $$$$$$/  "<<endl;
        cout<<endl<<endl<<endl;
            cout << "Виберіть опцію:" << endl;
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
            cout << "[0]вийти" << endl;
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