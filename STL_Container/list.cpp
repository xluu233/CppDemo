#include "container.h"

// list是cpp中的双向链表
// 不支持随机访问，必须通过迭代器
// 相反的forward_list是单向列表

template<typename T>
void printList(list<T>& l){
    for (auto iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout <<  endl;
}

// cpp中提供的合并两个有序链表
void mergeList(list<int>& l1, list<int>& l2){
    cout << "\nmergeList: " << endl;
    list<int> l3;
    l3.merge(l1);
    l3.merge(l2);
    
    // 合并后，l1/l2都为空了
    printList(l1);
    printList(l2);
    printList(l3);
}

// 自定义排序规则
bool mycomp(int i, int j) {
    return i < j;
}

int main(){
    list<int> l1 = {1,30,17,90,0};
    l1.push_back(99);
    l1.push_front(-1);
    printList(l1);  

    cout << endl;

    l1.pop_back();
    //l1.pop_front();
    printList(l1); 

    cout << endl;

    // 移除值为-1的元素
    l1.remove(-1); 
    // 移除值大于50的元素
    l1.remove_if([](int n){
        return n > 50;
    });
    printList(l1); 

    cout << endl;

    // 排序
    l1.sort();
    printList(l1);

    cout << endl;

    list<int> l2 = {-1,4,56,-19,999,20};
    // 自定义排序
    l2.sort(mycomp);
    printList(l2);

    mergeList(l1,l2);
}