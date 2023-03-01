#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
using namespace std;

struct People
{
    int id;
    string name;
    People(const int& id_,const string& name_) : id{id_} , name{name_}{

    }
};

int main(){

     shared_ptr<int> ptr1 = make_shared<int>(10);
     cout << *ptr1 << endl;

     make_shared<People>(123, "Im Happy Just to Dance With You");
     shared_ptr<People> ptr2 = make_shared<People>(123,"xlu");
     cout<< ptr2->id << ":" << ptr2->name <<endl;


    // auto ptr3 = make_shared<People>(123,"xlu");
    // cout<< ptr3 <<endl;

    // auto ptr4(ptr3);
    // cout<< ptr4 <<endl;

    // shared_ptr<People> ptr5(nullptr);
    // ptr5.swap(ptr3);
    // cout<< ptr3 <<endl;
    // cout<< ptr5 <<endl;
    

    shared_ptr<People> ptr6 = make_shared<People>(134, "hahah");
    cout<< ptr6->id << ":" << ptr6->name <<endl;

    auto ptr7 = std::move(ptr6);
    cout<< ptr7->id << ":" << ptr7->name <<endl;

    // auto pointer = make_shared<int>(10);
    // auto pointer2 = pointer; // 引用计数+1
    // auto pointer3 = pointer; // 引用计数+1
    // int *p = pointer.get(); // 这样不会增加引用计数

    // std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
    // std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    // std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

    // pointer2.reset();
    // std::cout << "reset pointer2:" << std::endl;
    // std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
    // std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
    // std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2

    // pointer3.reset();
    // std::cout << "reset pointer3:" << std::endl;
    // std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
    // std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    // std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset


    system("pause");
    return 0;
}