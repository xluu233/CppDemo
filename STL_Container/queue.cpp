#include "container.h"

// queue代表队列，FIFO （先进先出），相反的是stack

void printQueue(queue<int>& qe){
    // qe.pop()的值是qe.front()
    while (!qe.empty())
    {
        cout << qe.front() << " - ";
        qe.pop();
    }
    cout << endl;
}


int main(){

    queue<int> qe;
    for (size_t i = 0; i < 10; i++)
    {
        qe.push(i);
    }

    cout << qe.back() << endl;
    cout << qe.front() << endl;

    // 删除首个元素
    qe.pop();

    cout << qe.back() << endl;
    cout << qe.front() << endl;

    printQueue(qe);

    
}