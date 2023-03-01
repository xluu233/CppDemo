#include <iostream>
#include <stdexcept>
#include <exception>


using namespace std;

void fun(){
    cout<<"fun"<<endl;
    throw invalid_argument("hahah");
}

class customException : exception
{
private:
    
public:
    customException(string str,int id);
    ~customException();
};

customException::customException(string str,int id)
{
    cout<<"id:"<<id<<"----"<<"string:"<<str<<endl;
}

customException::~customException()
{

}


int main(){

    try
    {
        throw customException("haha",123);

        //const customException& e
    }
    catch(...)
    {
        cout << "??" <<endl;
    }
    
    cout<<"end"<<endl;
    return 0;
}