#ifndef MERCHANDISE
#define MERCHANDISE
#include<string>
#include"Promotion.hpp"
using namespace std;

class Commodity{
public:
    string merchandiseName;
    string sellerName;
    int addTime;
    bool hasPromotion;
    Promotion promotion;
    Commodity(string sellerName, string merchandiseName, int addTime, bool hasPromotion, Promotion promotion){
        this->addTime = addTime;
        this->merchandiseName = merchandiseName;
        this->sellerName = sellerName;
        this->hasPromotion = hasPromotion;
        this->promotion = promotion;
    }
    Commodity(){}
    bool operator==(const Commodity& commodity) const{
        return (this->merchandiseName == commodity.merchandiseName) &&
        (this->sellerName == commodity.sellerName) &&
        (this->addTime == commodity.addTime) &&
        (this->hasPromotion == commodity.hasPromotion) &&
        (this->promotion == commodity.promotion);
    }
};
#endif