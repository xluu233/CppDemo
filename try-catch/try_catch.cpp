#include <iostream>

using namespace std;

// 一个普通的函数，可以抛出任何异常
void fun(){
    char i = 'A';
    throw &i;
}

// 在函数后面加上throw()：不可以抛出任何异常
void fun1() noexcept{

}

// 在throw()中加上数据类型，表示只能抛出()中限定的数据类型
void fun2(int n) throw(int,char){
    throw n;
}

int main(){

    try
    {
        cout<<"start throw"<<endl;
        fun();
        fun1();
        fun2(123);
    }    
    catch(int i){
        cout<<i<<endl;
    }
    catch(const char *str){
        cout<<*str<<endl;
    }

    return 0;
}