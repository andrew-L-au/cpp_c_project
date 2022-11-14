#include<iostream>
#include<string>
#include<list>
#include<vector>
#include"CommodityCollection.hpp"
#include"Commodity.hpp"
#include"initialAddCommodity.hpp"
#include"initalDeleteCommodity.hpp"
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
            vector<Commodity*> output;
            unordered_map<CommodityCollection,bool> isPrinted;
            for (CommodityCollection* c : storeList){
                isPrinted.emplace(*c,false);
            }
            for (CommodityCollection* c : storeList){
                if (isPrinted.at(*c)){
                    continue;
                }

            }
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
                oldStore->addCommodity(commodity);
                storeList.push_front(oldStore);
                if (commodity.promotion != nullptr){
                    promotionSet.updatePromotionOfStore(*commodity.promotion, oldStore);
                }
            }
        }else{
            Commodity* commodity;
            CommodityCollection* store;
            initialDeleteCommodity(commodity);
            for (CommodityCollection* s : storeList){
                if (s->storeName == commodity->sellerName){
                    store = s;
                }
            }
            *commodity = store->getCommodity(commodity->sellerName);
            store->deleteCommodity(*commodity);
            if (commodity->promotion != nullptr){
                promotionSet.updatePromotionOfStore(*(commodity->promotion), store);
            }
        }       
    }
    return 1;
}