#include <iostream>
#include "container.h"


template<typename T>
void printArr(T& arr){
    for(auto i : arr){
        cout << i << " - ";
    }
    cout << endl;
}

int main(){
    array<int,10> arr;
    printArr(arr);
    
    arr = {0,1,2,3};
    printArr(arr);

    array<char,5> arr2 = {'1','2','a','b','r'};
    printArr(arr2);

    array<const char*,5> arr3 = {"123","abc","\0","哈哈","@@##**()__++"};
    printArr(arr3);

    // array<const char*,5> arr4;
    // std::swap(arr3,arr4);
    // printArr(arr3);
    // printArr(arr4);

}