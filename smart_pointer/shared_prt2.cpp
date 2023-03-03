#include "smart_prt.h"


int main(){
    
    // 同一普通指针不能同时为多个 shared_ptr 对象赋值，否则会导致程序发生异常
    int* ptr = new int(123);
    shared_ptr<int> p1(ptr);
    //shared_ptr<int> p2(ptr);//错误
    // 移动
    shared_ptr<int> p2 = move(p1);
    // 交换
    swap(p1,p2);

    cout << *p1.get() << endl;

    // 不增加引用计数
    int *p = p1.get();
    cout << p1.use_count() << endl;
    // 引用计数-1
    p1.reset();
    cout << p1.use_count() << endl;

}