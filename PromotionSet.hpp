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
    bool addStoreWithPromotion(CommodityCollection* store, Promotion promotion){
        if (promotionToStoreMapper.contains(promotion)){
            promotionToStoreMapper.at(promotion).push_back(store);
        }else{
            list<CommodityCollection*> l;
            l.push_back(store);
            promotionToStoreMapper.emplace(promotion,l);
            promotions.push_front(promotion);
        }
        return true;
    }

    bool updatePromotionOfStore(Promotion promotion, CommodityCollection* store){
        list<CommodityCollection*>* l1 = &promotionToStoreMapper.at(promotion);
        bool isDelete = false;
        for (auto c : *l1){
            if (*c == *store){
                isDelete = true;
            }
        }
        if ()
    }

    bool addStore(CommodityCollection* store){

    }

    bool deleteStore(CommodityCollection store){

    }
};
#endif