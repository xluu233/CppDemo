#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>

using namespace std;

template <typename S>
void printSet(S& set)
{
    cout << "adress:" << &set << "\t";
    for (auto iter = set.begin(); iter != set.end(); iter++)
    {
        cout << *iter << " - ";
    }
    cout << "\n" << endl;
}

int main()
{
    std::unordered_set<int> s = {1, 1, 2, 3, 4};
    std::unordered_set<int> s2(s.begin(), s.end());
    printSet(s);
    printSet(s2);

    cout << s.count(1) << endl;

    auto res = s.find(5);
    if (res != s.end())
    {
        cout << "found:" << *res << endl;
    }else{
        cout << "not found" << endl;
    }
    cout  << endl;

    // c++20才支持contains方法！！！
    // for(int x: {2, 5}) {
    //     if(s.contains(x)) {
    //         std::cout << x << ": Found\n";
    //     } else {
    //         std::cout << x << ": Not found\n";
    //     }
    // }

    return 0;
}
