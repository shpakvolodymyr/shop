#include <iostream>
#include <vector>

using namespace std;

struct Good{
    string name;
    int amount;
    double price;
    short id;
};

void def1(vector<Good>& goods,Good good){ //def1
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name){
            goods[i].amount += good.amount;
            return;
        }
    }
    goods.push_back(good);
}

void def2(vector<Good>& goods,Good good){ //def2
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name){
            goods.erase(goods.begin() + i);
            return;
        }
    }
    cout << "\ngood not found\n";
}

void def3(vector<Good> goods,Good good){
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name) {
            cout << "\nName: " << goods[i].name << "\nAmount: " << goods[i].amount << "\nPrice: " << goods[i].price << endl;
            return;
        }
    }
    cout << "\nGood not found\n";
}

void def4(vector<Good>& goods,string name, int amount){
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == name){
            if(goods[i].amount >= amount){
                goods[i].amount -= amount;
                if(goods[i].amount == 0) goods.erase(goods.begin() + i);
                return;
            }
            else {
                cout << "\nThere are not enough good";
                return;
            }
        }
    }
    cout << "\nGood not found";
}

void def5(vector<Good>& goods,Good good){
    Good mostExpensive;
    mostExpensive.price = 0;
    for(auto const &element: goods){
        if (element.price >= mostExpensive.price){
            mostExpensive = element;
        }
    }
    cout << mostExpensive.price;
}

void def6(vector<Good>& goods,Good good){ //def6
    for(int i = 0; i < goods.size(); i++){
        cout << goods[i].name<<" ";
        }
}

void def8(vector<Good>& goods,Good good){ //def8
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name){
            goods[i].price *= 0.9;
            return;
        }
    }
}

void def10(vector<Good>& goods,Good good) {
    //def10
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name){
            cin >> goods[i].price;
            return;
        }
    }
}

int main(){
    int a;
    do {
        cout << "Виберіть опцію:" << endl;
        cout << "[0]вийти" << endl;
        cout << "[1]додати в реєстр" << endl;
        cout << "[2]забрати з реєстру" << endl;
        cout << "[3]пошук за назвою" << endl;
        cout << "[4]зменшити покупку на 1" << endl;
        cout << "[5]знайти найдорожчий товар"<< endl;
        cout << "[6]показати всі товари" << endl;
        cout << "[7]порахувати загальну вартість всіх товарів" << endl;
        cout << "[8]зробити знижку 10% в реєстрі" << endl;
        cout << "[9]порахувати, скільки товарів дешевші за 100 грн" << endl;
        cout << "[10]змінити ціну товара" << endl;
        cin >> a;
        switch (a) {
            case 1:
                def1();
                break;
            case 2:
                def2();
                break;
            case 3:
                def3();
                break;
            case 4:
                def4();
                break;
            case 5:
                def5();
                break;
            case 6:
                def6();
                break;
            case 7:
                def7();
                break;
            case 8:
                def8();
                break;
            case 9:
                def9();
                break;
            case 10:
                def10();
                break;
        }
    }
    while (a != 0);

    return 0;
}