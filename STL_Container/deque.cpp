#include "container.h"


// https://zh.cppreference.com/w/cpp/container/deque
// deque是双端数组(双端队列)，可以在两端对数组进行增删操作，

// vector和deque的区别
// deque是分段连续线性空间，随时可以增加一段新的空间；
// 不像vector那样，vector当内存不够时，需重新分配/复制数据/释放原始空间；
// vector对于头部的插入删除效率低，数据量越大，效率越低
// deque相对而言，对头部的插入删除速度回比vector快
// vector访问元素时的速度会比deque快,这和两者内部实现有关


void printDeque(const deque<int>& dq){
    for (auto iter = dq.begin(); iter != dq.end(); iter++)
    {
        cout << *iter << " - ";
    }
    cout << endl;
}


int main(){
    deque<int> dq;

    // 0 - 1 - 2 - 3 - 4 
    for (size_t i = 0; i < 5; i++)
    {
        dq.push_back(i);
    }
    printDeque(dq);

    // 96 - 97 - 98 - 99 - 0 - 1 - 2 - 3 - 4
    for (size_t i = 99; i > 95; i--)
    {
        dq.push_front(i);
    }
    printDeque(dq);
    
    // 97 - 98 - 99 - 0 - 1 - 2 - 3
    dq.pop_back();
    dq.pop_front();
    printDeque(dq);

}
