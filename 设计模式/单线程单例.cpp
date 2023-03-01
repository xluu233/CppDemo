#include <iostream>
using namespace std;

class singleton
{
private:
    static singleton *p;
public:
    singleton(){

    };
    static singleton* getInstance();
};

singleton* singleton::p = nullptr;

singleton* singleton::getInstance(){
    if (p == nullptr)
    {
        p = new singleton();
    }
    return p;
}

int main(){

    cout << singleton::getInstance() << endl;
    cout << singleton::getInstance() << endl;
    cout << singleton::getInstance() << endl;

}