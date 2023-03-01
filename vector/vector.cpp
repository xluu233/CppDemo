
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {0,1,2,3,4,5,6,7,8,9};

int main(){

    // 创建数组：
    vector<int> vc1;
    vector<int> vc2(100);
    vector<int> vc3(arr.begin(),arr.end());

    vc3.pop_back();
    vc3.push_back(1024);

    for (size_t i = 0; i < vc3.size(); i++)
    {
        cout<<vc3[i]<< "  " ;
    }
    cout << endl;

    // 首元素
    cout<< vc3.front() << endl;
    // 尾元素
    cout<< vc3.back() << endl;
    // 判断空
    cout<< vc3.empty() << endl;
    

    //交互
    std::swap(vc3,vc2);
    for (size_t i = 0; i < vc2.size(); i++)
    {
        cout<<vc2[i]<< "  " ;
    }
    cout << endl;

    // 设置前n个元素的值
    vc3.assign(5,1024);
    for (size_t i = 0; i < vc3.size(); i++)
    {
        cout<<vc3[i]<< "  " ;
    }
    cout << endl;

    cout << "------------" << endl;



    system("pause");
    return 0;
}