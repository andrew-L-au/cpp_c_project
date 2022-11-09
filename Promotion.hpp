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
};
#endif