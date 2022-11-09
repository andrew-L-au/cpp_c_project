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
};
#endif