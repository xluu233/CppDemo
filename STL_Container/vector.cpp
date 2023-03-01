#include "container.h"


template<typename T>
void printVector(vector<T>& v){
    cout << &v << endl;
    for (auto i:v)
    {
        cout << i << " - ";
    }
    cout << endl;
}


int main(){

    vector<string> v1 = {"tets","hhah"};
    v1.push_back("123");
    //cout << &v1 << endl;

    printVector(v1);

    v1.pop_back();
    printVector(v1);


}