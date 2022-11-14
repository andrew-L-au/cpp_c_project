#ifndef PROMOTION_SET
#define PROMOTION_SET
#include"Promotion.hpp"
#include"CommodityCollection.hpp"
#include<list>
#include<unordered_map>
#include"ListUtils.hpp"
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
        bool promotionListContainStore = listContain<CommodityCollection*>(*l1, store);
        if (promotionListContainStore){
            list<Promotion> storePromotions = store->promotionList;
            bool containPromotion = listContain<Promotion>(store->promotionList, promotion);
            if (!containPromotion){
                l1->remove(store);
                return true;
            }else {
                return false;
            }
        }else {
            bool storeContainPromotion = listContain<Promotion>(store->promotionList, promotion);
            if (storeContainPromotion){
                l1->push_back(store);
                return true;
            }else {
                return false;
            }
        }
    }

    bool deleteStore(CommodityCollection* store){
        return false;
    }
};
#endif