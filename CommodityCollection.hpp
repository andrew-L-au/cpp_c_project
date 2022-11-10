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
    list<Promotion> promotionList;
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
                promotionList.push_back(commodity.promotion);
                ret.hasOneNewPromotion = true;
            }
        }
        commodityList.push_front(commodity);
        changeStoreCondition(ADD);
        return ret;
    }
    ChangeCondition deleteCommodity(Commodity commodity){
        ChangeCondition ret(false,false);
        int pre = commodityList.size();
        commodityList.remove(commodity);
        if (pre == commodityList.size()){
            return ret;
        } 
        if (commodity.hasPromotion){
            promotionCounter.at(commodity.promotion) -= 1;            
        }
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