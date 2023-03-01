#include<iostream>
#include <string>

using namespace std;


// 正常的模板函数
template <class T>
T& compareMax(T& t1, T& t2){
    return t1 > t2 ? t1 : t2;
}


template <>
string& compareMax<string>(string& s1, string & s2){
    cout << "string compare" << endl;
    return s1.length() > s2.length() ? s1 : s2;
}

int main(){

    int t1 = 100;
    int t2 = 200;
    cout << compareMax(t1,t2) << endl;

    string s1 = "abc----------------";
    string s2 = "abcd";
    cout << compareMax(s1,s2) << endl;


}
