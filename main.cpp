#include<iostream>
#include<string>
#include"Merchandise.hpp"
#include"phaseInput.hpp"
using namespace std;

int main(){
    int time = 0;
    while(true){
        cout << "enter commodity and its seller(split by space,put store's name first):" << endl;
        string input;
        cin >> input;
        string* str = phaseInput(input);
        string storeName = str[0];
        string wareName = str[1];
        cout << "if it has promotion,enter \"Y\" else enter \"N\"" <<endl;
        string hasPromotion;
        cin >> hasPromotion;
        if (hasPromotion == "Y") {
            cout << "type in Promotion kind: percentage(P) or quantity(Q):"
            string type;
            cin >> type;
            cout << "type in Promotion rate:first required amount than discount rate(without \"%\") or quantity:"
            int requirement;
            int rate;
            cin >> requirement >> rate;
            if (type == "P")
        }
        Merchandise m(storeName, wareName ,time);
        ++time;
    }
    return 1;
}