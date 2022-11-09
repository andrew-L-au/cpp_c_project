#ifndef INITIAL_COMMODITY
#define INITIAL_COMMODITY
#include<iostream>
#include<string>
#include"Commodity.hpp"
#include"Promotion.hpp"
using namespace std;
bool initialAddCommodity(Commodity* newCommodity,int addTime){
    cout << "enter commodity and its seller(split by space,put store's name first):" << endl;
    string storeName;
    string wareName;
    cin >> storeName >> wareName;
    cout << "if it has promotion,enter \"Y\" else enter \"N\"" <<endl;
    string yesOrNo;
    cin >> yesOrNo;
    if (yesOrNo != "Y" && yesOrNo != "N")return false;
    bool hasPromotion = yesOrNo == string("Y") ? true : false;
    Promotion* promotion = nullptr;
    if (hasPromotion) {
        cout << "type in Promotion kind: percentage(P) or quantity(Q):" << endl;
        string type;
        cin >> type;
        if (type != "P" && type != "Q")return false;
        cout << "type in Promotion info:first required amount than discount rate(without \"%\") or quantity:" << endl;
        int requirement;
        int rate;
        cin >> requirement >> rate;
        promotion = new Promotion(type, requirement, rate);
    }
    *newCommodity = Commodity(storeName, wareName, addTime, hasPromotion, *promotion);
    return true;
}
#endif