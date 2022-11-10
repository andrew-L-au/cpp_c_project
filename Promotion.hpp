#ifndef PROMOTION
#define PROMOTION
#include<string>
using namespace std;
static const string PERCENTAGE = "percentage";
static const string QUANTITY = "quantity";
class Promotion{
public: 
    string type;
    int requirement;
    int rate;
    Promotion(string type, int requirement, int rate){
        if (type == "P")this->type = PERCENTAGE;
        else if (type == "Q")this->type = QUANTITY;
        this->requirement = requirement;
        this->rate = rate;
    }
    Promotion(){}
    bool operator==(const Promotion& promotion) const{
        return (this->type == promotion.type) &&
        (this->requirement == promotion.requirement) &&
        (this->rate == promotion.rate);
    }
};
namespace std{
    template <>
    struct hash<Promotion>{
        size_t operator()(const Promotion& p) const{
            return ((hash<string>()(p.type)
                ^ (hash<int>()(p.requirement) << 1)) >> 1)
                ^ (hash<int>()(p.rate) << 1);
        }
    };
}
#endif