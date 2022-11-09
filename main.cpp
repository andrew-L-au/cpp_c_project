#include<iostream>
#include<string>
#include<list>
#include"Store.hpp"
#include"Commodity.hpp"
#include"initialCommodity.hpp"
using namespace std;
list<Store> storeList;
int main(){
    for (int time = 0; ;++time){
        string addOrDelete;
        bool isAdd;
        cout << "Add(A) Or Delete(D) Commodity?:" << endl;
        cin >> addOrDelete;
        isAdd = addOrDelete == "A" ? true : false;
        if (isAdd){
            Commodity commodity;
            initialAddCommodity(&commodity, time);
            bool isNewStore = true;
            Store oldStore;
            for (auto i : storeList){
                if (i.storeName == commodity.sellerName){
                    isNewStore = false;
                    oldStore = i;
                }
            }
            if (isNewStore){
                Store newStore(commodity.sellerName);
                newStore.addCommodity(commodity);
                storeList.push_front(newStore);
            }else {
                storeList.remove(oldStore);
            }
        }else{

        }
        
    }
    return 1;
}