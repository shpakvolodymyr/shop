#include <iostream>
#include <vector>

using namespace std;

struct Good{
    string name;
    int amount;
    double price;
    short id;
};

void addToShop(vector<Good>& goods,Good good){ //def1
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name){
            goods[i].amount += good.amount;
            return;
        }
    }
    goods.push_back(good);
}

void removeFromShop(vector<Good>& goods,Good good){ //def2
    for(int i = 0; i < goods.size(); i++){
        if(goods[i].name == good.name){
            goods.erase(i);
        }
    }
}

int main(){
    vector<Good> goods(0);
    Good good;
    cin >> good.name;
    good.amount = 1;
    good.price = 10;
    addToShop(goods,good);
    Good good2;
    good2.name = "apple";
    good2.amount = 1;
    good2.price = 10;
    addToShop(goods,good2);
    for(auto i : goods){
        cout << i.name << " " << i.amount << " " << i.price << endl;
    }
    return 0;
}