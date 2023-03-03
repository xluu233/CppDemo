#include <iostream>
#include <memory>


using namespace std;


int main(){

    // 不同的初始化方式
    shared_ptr<int> p1(new int(123));
    shared_ptr<int> p2(nullptr);
    shared_ptr<int> p3(new int[10]{0});
    shared_ptr<int> p4 = make_shared<int>(12);
    shared_ptr<int> p5(p4);
    shared_ptr<int> p6(std::move(p5));


    //error
    cout << "p1:" << p1 << endl;
    //引用计数-1，p1为空指针
    p1.reset();
    if (p1)
    {
        cout << "p1 is not null" << endl;
    }else{
        cout << "p1 is null" << endl;
    }

    if (p2)
    {
        cout << "p2 is not null" << endl;
    }else{
        cout << "p2 is null" << endl;
    }
    
    
    cout << "p3:" << *p3 << endl;
    cout << "p4:" << *p4 << endl;
    // error ??
    cout << "p5:" << *p5 << endl;
    cout << "p6:" << *p6 << endl;

    return 0;
}