#include<iostream>
#include<string>
#include<list>
#include"CommodityCollection.hpp"
#include"Commodity.hpp"
#include"initialCommodity.hpp"
#include"PromotionSet.hpp"
using namespace std;
list<CommodityCollection*> storeList;
PromotionSet promotionSet;
bool inputIsFirst(string output,string first){
    string input;
    cout << output << endl;
    cin >> input;
    return input == first ? true : false;
}

int main(){
    for (int time = 0; ;++time){
        bool isShowCart = inputIsFirst("Show the shopping cart? Y or N:","Y"); 
        if (isShowCart){
            continue;
        }
        bool isAdd = inputIsFirst("Add(A) Or Delete(D) Commodity?:","A");
        if (isAdd){
            Commodity commodity;
            initialAddCommodity(&commodity, time);
            bool isNewStore = true;
            CommodityCollection* oldStore;
            for (auto i : storeList){
                if (i->storeName == commodity.sellerName){
                    isNewStore = false;
                    oldStore = i;
                }
            }
            if (isNewStore){
                CommodityCollection* newStore = new CommodityCollection(commodity.sellerName);
                newStore->addCommodity(commodity);
                storeList.push_front(newStore);
                if (commodity.hasPromotion){
                    promotionSet.addStoreWithPromotion(storeList.front(), *commodity.promotion);
                }
            }else {
                storeList.remove(oldStore);
                storeList.remove(oldStore);
                oldStore->addCommodity(commodity);
                storeList.push_front(oldStore);
                promotionSet.updatePromotionOfStore(, oldStore);
            }
        }else{

        }       
    }
    return 1;
}