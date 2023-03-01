#include <iostream>
using namespace std;

struct W
{   
    int i,j;
    W(int& a, int& b) {
        i= a;
        j= b;
    }
};
struct X
{
X(const int&, int&) {}
};
struct Y
{
Y(int&, const int&) {}
};
struct Z
{
Z(const int&, const int&) {}
};

template <typename T, typename A1, typename A2>
T* factory(A1& a1, A2& a2)
{
return new T(a1, a2);
}

// template <typename T, typename A1, typename A2>
// T* factory(A1&& a1, A2&& a2)
// {
// return new T(std::forward<A1>(a1), std::forward<A2>(a2));
// }


int main(){

    int a = 4, b = 5;
    W* pw = factory<W>(a, b);
    cout << pw->i << endl;
    cout << pw->j << endl;

    a = 123;
    cout << pw->i << endl;

    system("pause");
    return 0;
}