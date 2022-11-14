#ifndef INITIAL_DELETE_COMMODITY
#define INITIAL_DELETE_COMMODITY
#include<iostream>
#include<string>
#include"Commodity.hpp"
#include"Promotion.hpp"
using namespace std;
bool initialDeleteCommodity(Commodity* commodity){
    cout << "enter commodity and its seller(split by space,put store's name first):" << endl;
    string storeName;
    string wareName;
    commodity = new Commodity(storeName,wareName,0,nullptr);
    return true;
}
#endif