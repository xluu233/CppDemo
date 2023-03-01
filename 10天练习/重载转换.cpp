#include <iostream>

using namespace std;

class Circle
{
private:
    //半径
    double radius;
    const double e = 3.14156;
public:
    Circle(double r){
        if (r > 0)
        {
            this->radius = r;
        }
        else
        {
            throw "radius must >= 0";
        }
    }

    // 直径
    operator int(){
        return (int) radius*2;
    }

    // 周长
    operator double(){
        return (double) 2*e*radius;
    }

    // 面积
    operator float(){
        return (float) e*radius*radius;
    }
};


int main(){

    Circle circle(10);

    cout << (int)circle << endl;
    cout << (double)circle << endl;
    cout << (float)circle << endl;

}


