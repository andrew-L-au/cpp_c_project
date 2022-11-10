#ifndef STORE
#define STORE
#include<list>
#include<unordered_map>
#include"Promotion.hpp"
#include"Commodity.hpp"
using namespace std;
string DELETE = "delete";
string ADD = "add";
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
    list<Commodity> commodityList;
    unordered_map<Promotion,int,hash<Promotion>> promotionCounter;
    StoreCondition storeCondition;
public:
    string storeName;
    CommodityCollection(string storeName){
        this->storeName = storeName;
        this->storeCondition.isEmpty = true;
    }
    CommodityCollection(){}
    ChangeCondition addCommodity(Commodity commodity){
        ChangeCondition ret(false,false); 
        if (commodity.hasPromotion){
            if (promotionCounter.contains(commodity.promotion)){
                promotionCounter.at(commodity.promotion) += 1;
            }else {
                promotionCounter.emplace(commodity.promotion,1);
                ret.hasOneNewPromotion = true;
            }
        }
        commodityList.push_front(commodity);
        changeStoreCondition(ADD);
        return ret;
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