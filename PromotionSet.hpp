#ifndef PROMOTION_SET
#define PROMOTION_SET
#include"Promotion.hpp"
#include"CommodityCollection.hpp"
#include<list>
#include<unordered_map>
using namespace std;
class PromotionSet{
private:
    list<Promotion> promotions;
    unordered_map<Promotion,list<CommodityCollection*>> promotionToStoreMapper;
public:
    list<CommodityCollection*>* getStores(Promotion promotion){
        if (promotionToStoreMapper.contains(promotion)){
            return new list<CommodityCollection*>(promotionToStoreMapper.at(promotion));
        }else{
            return nullptr;
        } 
    }
    bool updateStore(CommodityCollection store){
        if (store.hasPromotion()){

        }
    }

    bool addStore(CommodityCollection store){

    }

    bool deleteStore(CommodityCollection store){

    }
};
#endif