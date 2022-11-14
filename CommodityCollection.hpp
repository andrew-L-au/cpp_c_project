#ifndef STORE
#define STORE
#include<list>
#include<unordered_map>
#include"Promotion.hpp"
#include"Commodity.hpp"
using namespace std;
string DELETE = "delete";
string ADD = "add";

template <>
struct hash<Commodity>{
    size_t operator()(const Commodity& c) const{
        return ((hash<string>()(c.sellerName)
            ^ (hash<string>()(c.merchandiseName) << 1)) >> 1);
    }
};

class ChangeCondition{
public:
    bool hasOneNewPromotion;
    bool lossOnePromotion;
    ChangeCondition(bool hasOneNewPromotion, bool lossOnePromotion){
        this->hasOneNewPromotion = hasOneNewPromotion;
        this->lossOnePromotion = lossOnePromotion;
    }
    ChangeCondition(){}
};

class StoreCondition{
public:
    bool isEmpty;
    StoreCondition(){}
};

class CommodityCollection{
private:
    unordered_map<Promotion,int,hash<Promotion>> promotionCounter;
    unordered_map<Commodity,int,hash<Commodity>> commodityCounter;
    StoreCondition storeCondition;
public:
    list<Commodity> commodityList;
    list<Promotion> promotionList;
    string storeName;
    CommodityCollection(string storeName){
        this->storeName = storeName;
        this->storeCondition.isEmpty = true;
    }
    CommodityCollection(){}
    ChangeCondition addCommodity(Commodity commodity){
        if (commodityCounter.contains(commodity)){
            commodityCounter.at(commodity)++;
            return ChangeCondition(false,false);
        }
        ChangeCondition ret(false,false); 
        if (commodity.hasPromotion){
            if (promotionCounter.contains(*commodity.promotion)){
                promotionCounter.at(*commodity.promotion) += 1;
            }else {
                promotionCounter.emplace(*commodity.promotion,1);
                promotionList.push_front(*commodity.promotion);
                ret.hasOneNewPromotion = true;
            }
        }
        commodityList.push_front(commodity);
        commodityCounter.emplace(commodity,1);
        changeStoreCondition(ADD);
        return ret;
    }
    Commodity getCommodity(string name){
        for (Commodity c : commodityList){
            if (c.sellerName == name){
                return c;
            }
        }
        return Commodity();
    }
    ChangeCondition deleteCommodity(Commodity commodity){
        if (commodityCounter.contains(commodity) && commodityCounter.at(commodity) >= 2){
            commodityCounter.at(commodity)--;
            return ChangeCondition(false,false);
        }
        ChangeCondition ret(false,false);
        commodityList.remove(commodity);
        if (commodity.hasPromotion){
            promotionCounter.at(*commodity.promotion) -= 1;
            if (promotionCounter.at(*commodity.promotion) == 0){
                promotionCounter.erase(*commodity.promotion);
                promotionList.remove(*commodity.promotion);
            }          
        }
        commodityCounter.erase(commodity);
        changeStoreCondition(DELETE);
        return ret;
    }
    bool hasPromotion(){
        return promotionList.size() != 0;
    }
    bool containPromotion(Promotion promotion){
        return promotionCounter.contains(promotion);
    }
    void changeStoreCondition(string info){
        if(info == DELETE){
            if (commodityList.size() == 0){
                storeCondition.isEmpty = true;
            }
        }
        if (info == ADD){
            storeCondition.isEmpty = false;
        }
    }
    bool operator==(const CommodityCollection& store)const{
        return this->storeName == store.storeName;
    } 
};
namespace std{
    template <>
    struct hash<CommodityCollection>{
        size_t operator()(const CommodityCollection& c) const{
            return hash<string>()(c.storeName);
        }
    };
}

#endif