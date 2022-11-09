#ifndef MERCHANDISE
#define MERCHANDISE
#include<string>
using namespace std;

class Merchandise{
public:
    string merchandiseName;
    string sellerName;
    int addTime;
    Merchandise(string sellerName, string merchandiseName, int addTime){
        this->addTime = addTime;
        this->merchandiseName = merchandiseName;
        this->sellerName = sellerName;
    }
};
#endif