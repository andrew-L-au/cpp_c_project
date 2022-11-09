#ifndef STORE
#define STORE
#include<list>
#include<unordered_map>
#include"Promotion.hpp"
#include"Commodity.hpp"
using namespace std;
class Store{
private:
    list<Commodity> commodityList;
    unordered_map<Promotion,int,hash<Promotion>> promotionCounter;
public:
    string storeName;
    Store(string storeName){
        this->storeName = storeName;
    }
    Store(){}
    void addCommodity(Commodity commodity){
        if (commodity.hasPromotion){
            if (promotionCounter.contains(commodity.promotion)){
                promotionCounter.at(commodity.promotion) += 1;
            }else {
                promotionCounter.emplace(commodity.promotion,1);
            }
        }
        commodityList.push_front(commodity);
    }
    bool operator==(const Store& store)const{
        return this->storeName == store.storeName;
    } 
};
#endif