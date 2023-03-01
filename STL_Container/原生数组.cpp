#include "container.h"


template<typename T>
void printArr(T* arr,int size){
    cout << "address : " << arr << " | ";

    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " - ";
    }
    cout << endl;
}

// 测试数组作为参数，返回数组
template<typename T>
T test(T arr, int size){
    cout << "test" << endl;
    return arr;
}

// int类型特化
template<>
int* test(int* arr, int size){
    cout << "int test" << endl;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] *= 2;
    }
    return arr;
}

int main(){

    //生成的是随机值
    int *arr = new int[10];
    printArr(arr,10);

    cout << endl;

    const char *arr2[3] = {"abc","123",""};
    printArr(arr2,3);
    test(arr2,3);
    printArr(arr2,3);


    cout << endl;

    // 这里是将abc分为三个char值
    char arr3[] = "abc";
    printArr(arr3,3);

    cout << endl;

    int arr4[10] = {0,1,2,4};
    printArr(arr4,10);
    test(arr4,10);
    printArr(arr4,10);
    
    return 0;
}


