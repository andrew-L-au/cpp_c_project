#include<iostream>
#include<string>
#include"Commodity.hpp"
#include"initialCommodity.hpp"
using namespace std;

int main(){
    int time = 0;
    while(true){
        Commodity commodity;
        initialCommodity(&commodity, time);
        ++time;
    }
    return 1;
}