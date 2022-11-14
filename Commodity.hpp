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
    Promotion* promotion;
    Commodity(string sellerName, string merchandiseName, int addTime, Promotion* promotion){
        this->addTime = addTime;
        this->merchandiseName = merchandiseName;
        this->sellerName = sellerName;
        this->hasPromotion = promotion == nullptr ? false : true;
        this->promotion = promotion;
    }
    Commodity(){}
    bool operator==(const Commodity& commodity) const{
        return (this->merchandiseName == commodity.merchandiseName) &&
        (this->sellerName == commodity.sellerName);
    }
};
#endif

namespace std{

}