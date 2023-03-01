#include "container.h"


void printFL(forward_list<int>& fl){
    for (auto iter = fl.begin(); iter != fl.end(); iter++)
    {
        cout << *iter << "  ";
    }
    cout << endl;
}

int main(){

    forward_list<int> fl;
    fl.push_front(-1);
    fl.push_front(-1);

    for (size_t i = 0; i < 10; i++)
    {
        fl.push_front(i);
    }
    
    printFL(fl);

    fl.pop_front();
    fl.unique();
    fl.remove(-1);

    printFL(fl);
}