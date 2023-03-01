#include <iostream>
using namespace std;


class Base
{
    private:
        int i = 0;
    public:
        Base(){

        };
        virtual ~Base(){
            cout<<"deleted Base"<<endl;
        };
        virtual void fun1() = 0;
        virtual void fun2(){
            cout <<"Base::fun2()"<<endl;
        };

};

class A:virtual public Base
{
    private:
        int j = 0;
    public:
        A():Base(){
            
        };
        ~A(){
            cout<<"deleted A"<<endl;
        };
        void fun1(){
            cout<<"A::fun1()"<<endl;
        }
        // Base::fun2的重载函数
        // void fun2(){
        //     cout<<"A::fun2()"<<endl;
        // };
        virtual void fun2(){
            cout<<"A::fun2()"<<endl;
        };
};



int main(){

    Base *base = new A();
    base->fun1();
    base->fun2();

    delete base;
    return 0;
}