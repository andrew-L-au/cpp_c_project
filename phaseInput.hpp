#ifndef PHASE_INPUT
#define PHASE_INPUT
#include<string>
using namespace std;
string* phaseInput(string input){
    if (input.find(' ') == string::npos){
        return nullptr;
    }
    string* ret = new string[2];
    int position = input.find(' ');
    ret[0] = input.substr(0, position);
    ret[1] = input.substr(position + 1, input.size() - position - 1);
    return ret;
}
#endif