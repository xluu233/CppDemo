#include "container.h"
#include <unordered_map>

// cpp版本的HashMap,用来存储键值对，也是根据hash值计算存储位置

template<typename M>
void printMap(M& map){
    for (const auto& kv: map)
    {
        cout << kv.first << " : " << kv.second << endl;
    }
    cout << endl;
}

int main(){

    unordered_map<int,string> map1 = {
        {1,"123"},
        {2,"haha"},
        {0,"adasd"},
    };

    printMap(map1);

    // 插入
    map1.insert({1,"000"});
    map1.insert(make_pair(4,"test"));
    printMap(map1); 

    // 查找
    auto res = map1.find(1);
    if (res != map1.end())
    {
        cout << res->first << " : " << res->second << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    

    // 根据hash值快速查询已存在的值
    int x = 2;
    // ??为什么这里编译不过
    // c++20才支持contains方法！！！
    // if (map1.contains(x))
    // {
    //     auto res = map1.find(x);
    //     cout << res->first << " : " << res->second << endl;
    // }
    // else
    // {
    //     cout << "not this value" << endl;
    // }
    
    
    return 0;
}