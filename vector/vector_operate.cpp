//
// Created by xlu on 2021/12/10.
//
#include <numeric>
#include <array>
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

/*测试数组求和*/
void testArraySum() {

    vector<int> arr = {1, 2, 3};
    cout << accumulate(arr.begin(), arr.end(), 0) << endl;

    int arr2[] = {1, 3, 5};
    cout << accumulate(arr2, arr2 + 3, 0) << endl;

    array<int, 5> arr3{1, 2, 3};
    cout << accumulate(arr3.begin(), arr3.end(), 0) << endl;
}

vector<int> getArray() {
    vector<int> arr = {-10, -3, 1, 0, -100, 1920, 1080, 1, 2, 3, 0, 567};
    return arr;
}


bool cmp1(int &i, int &j) {
    return i < j;
}

bool cmp2(int &i, int &j) {
    return i > j;
}

bool cmp3(int i, int j) {
    return abs(i) < abs(j);
}

static bool cmp4(int &i, int &j) {
    return abs(i) > abs(j);
}

/*特殊的比较写法：*/

struct myclass {
    bool operator()(int i, int j) {
        return (i < j);
    }
} myobject;

/*比较类元素，重写operator方法*/
class myclass2 {
public:
    bool operator()(int &a, int &b) {
        return abs(a) > abs(b);
    };
};

void testArraySort() {

    array<int, 20> test = {-10, -3, 1, -110, 1920, 1080, 2, 3, 0, 567, -10, -110};
    vector<int> arr(test.begin(), test.begin() + 11);

    sort(arr.begin(), arr.end(), [](int &a, int &b) {
        return a >= b ? true : false;
    });

    //-110    -10    -10    -3    0    1    2    3    567    1080    1920
    //-110    -10    -10    -3    0    1    2    3    567    1080    1920
    sort(arr.begin(), arr.end());
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;

    //    升序
    sort(arr.begin(), arr.end());
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;

    //    升序
    sort(arr.begin(), arr.end(), cmp1);
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;


    //  降序
    sort(arr.begin(), arr.end(), cmp2);
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;

    sort(arr.begin(), arr.end(), cmp3);
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;

    sort(arr.begin(), arr.end(), cmp4);
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;

    sort(arr.begin(), arr.end(), myobject);
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;

    sort(arr.begin(), arr.end(), myclass2());
    for (auto &item: arr) {
        cout << item << "    ";
    }
    cout << endl;


//    创建数组：
    vector<int> vc1;
    vector<int> vc2(100);
    vector<int> vc3(100,0);
    vector<int> vc4 = {1,3,45,645,-1,5345};

//    数组复制
    vector<int> vc5(vc4.begin(),  vc4.end());

//  增加元素
    vc5.push_back(100);
    vc5.insert(vc5.begin()+2,1024);
//    删除元素
    vc5.pop_back();
//    遍历元素


}


int main(){
    testArraySort();
    cout << "---------------" << endl;
    testArraySum();
}