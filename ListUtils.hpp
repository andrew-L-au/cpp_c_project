#ifndef LIST_UTILS
#define LIST_UTILS
#include<list>
using namespace std;
template<typename T>
bool listContain(list<T>& l, T& element){
    for (auto t : l){
        if (t == element){
            return true;
        }
    }
    return false;
}
class ListUtils{
public:
   

};
#endif