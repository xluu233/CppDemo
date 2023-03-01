#include <iostream>
#include <mutex>

using namespace std;

class singleton
{
private:
    static singleton *p;
    static mutex lock;
public:
    singleton(){

    };
    static singleton* getInstance();

    // 定义一个垃圾回收类
    class Garbige
    {
        public:
            ~Garbige(){
                if (singleton::p != nullptr)
                {
                    delete p;
                } 
            }
    };
    
    static Garbige grabige;
    
};

singleton* singleton::p = nullptr;
mutex singleton::lock;
singleton::Garbige garbige;

// 双重检查式加锁
singleton* singleton::getInstance(){
    if (p == nullptr)
    {
        lock_guard<mutex> guard(lock);
        if (p == nullptr)
        {
            p = new singleton();
        }
    }
    return p;
}

int main(){

    cout << singleton::getInstance() << endl;
    cout << singleton::getInstance() << endl;
    cout << singleton::getInstance() << endl;

}