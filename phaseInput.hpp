#ifndef PHASE_INPUT
#define PHASE_INPUT
#include<string>
using namespace std;
bool phaseInput(string input, string* ret){
    if (input.find(' ') == string::npos){
        return false;
    }
    if (input.find(' ') != input.find_last_of(' ')){
        return false;
    }
    int position = input.find(' ');
    ret[0] = input.substr(0, position);
    ret[1] = input.substr(position + 1, input.size() - position - 1);
    return ret;
}
#endif