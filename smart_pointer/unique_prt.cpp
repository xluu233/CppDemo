#include "smart_prt.h"

struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) {
    std::cout << "f(const Foo&)" << std::endl;
}

// 是一种独占的智能指针，它禁止其他智能指针与其共享同一个对象，从而保证代码的安全：

int main(){

    // error C++11 没有提供 std::make_unique，C++14才有，
    // 至于为什么没有提供，C++ 标准委员会主席 Herb Sutter 在他的博客中提到原因是因为『被他们忘记了』。
    // unique_ptr<Foo> p1 = make_unique<Foo>(Foo());

    // 以下两种都可行
    // unique_ptr<Foo> p1(new Foo());
    unique_ptr<Foo> p1(make_unique<Foo>());

    if (p1) //p1不为空
    {
        p1->foo();

        unique_ptr<Foo> p2 = move(p1);
        // p2 不空, 输出
        f(*p2);
        // p2 不空, 输出
        if(p2) p2->foo();
        // p1 为空, 无输出
        if(p1) p1->foo();
        p1 = std::move(p2);
        // p2 为空, 无输出
        if(p2) p2->foo();
        std::cout << "p2 被销毁" << std::endl;
    }
    
    f(*p1);

}