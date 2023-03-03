#include <iostream>
#include <memory>
using namespace std;

struct A;
struct B;

struct A {
    weak_ptr<B> pointer;
    ~A() {
        cout << "A 被销毁" << std::endl;
    }
};
struct B {
    weak_ptr<A> pointer;
    ~B() {
        cout << "B 被销毁" << std::endl;
    }
};


int main() {

    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->pointer = b;
    b->pointer = a;

    cout << "a.use_count()  =  " << a.use_count() << endl;
    cout << "b.use_count()  =  " << b.use_count() << endl;

    cout << a->pointer.expired() << endl;
    cout << b->pointer.expired() << endl;

    return 0;
}