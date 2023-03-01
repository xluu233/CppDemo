#include "container.h"
#include <cmath>
// #include <string_view>
// #include <functional>

// priority_queue优先队列，queue代表单入单出的结构，类似队列，
// 优先队列不是按照push顺序排序的，是按照权值排序（自定义规则）
// 比如我们可以用优先队列实现排序

// https://blog.csdn.net/zhizhengguan/article/details/107379018

template <typename Q>
void print_queue(Q q, const char *name)
{
    // 注意：按值传递 q，这是因为无法在不清楚队列的情况下遍历 priority_queue 的内容。
    for (std::cout << name << ":\t"; !q.empty(); q.pop())
        std::cout << q.top() << "   ";
    std::cout << '\n';
}

struct pair_cmp
{
    template <typename T, typename U>
    bool operator()(T const &left, U const &right)
    {
        if (left.second < right.second)
            return true;
        return false;
    }
};

int main()
{
    // 优先队列有三个构造参数，一般只用第一个就行。
    priority_queue<int, vector<int>> pq1;
    // priority_queue<int> pq;

    const auto arr = {1, 4, 5, 199, -9, 0, 100};

    for (auto i : arr)
    {
        pq1.push(i);
    }

    // pq1:    199   100   5   4   1   0   -9  已自动排好序(默认最大优先队列)
    print_queue(pq1, "pq1");

    // pq2:    -9   0   1   4   5   100   199  最小优先队列
    priority_queue<int, vector<int>, std::greater<int>> pq2(arr.begin(), arr.end());
    print_queue(pq2, "pq2");

    // 自定义权重,使用 lambda 来比较元素。
    auto cmp = [](int l, int r)
    {
        // 根据绝对值比较
        return abs(l) > abs(r);
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq3(cmp);

    for (auto i : arr)
    {
        pq3.push(i);
    }
    // 0   1   4   5   -9   100   199
    print_queue(pq3, "pq3");

    // 对于比较复杂的类型
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> pq4; // 完成pq的初始化
    pq4.push(make_pair(1,2));
    pq4.push(make_pair(0,3));
    pq4.push(make_pair(-1,4));
    // error 哈哈
    // print_queue(pq4, "pq4");

}