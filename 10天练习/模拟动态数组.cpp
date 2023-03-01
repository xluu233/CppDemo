#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class Array
{
private:
    int size;
    T *arr;

public:
    Array();

    void Sort();

    T& operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "resize" << endl;
            // throw "out of array";
            reSizeArr();
        }
        return arr[i];
    };

    void reSizeArr();

    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }

    ~Array()
    {
        cout << "array size:" << size << endl;
        delete[] arr;
    };
};

// 构造函数模板
template <typename T>
Array<T>::Array()
{
    size = 10;
    arr = new T[size]{0};
}

// 构造函数模板特化，不然遍历会有问题
template <>
Array<char*>::Array()
{
    size = 10;
    // 这里初始化需要注意，是指向char*类型的char数组指针。
    arr = new char*[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = "-";
    }
}

template <typename T>
void Array<T>::reSizeArr()
{
    int new_size = size * 2;
    T *new_arr = new T[new_size]{0};
    for (size_t i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    size = new_size;
}

// 冒泡排序
template <typename T>
void Array<T>::Sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
};

// 排序特化
template <>
void Array<char *>::Sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                // char* temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;
                swap(arr[j], arr[i]);
            }
        }
    }
};

int main()
{
    int count = 15;
    Array<int> arr;
    for (size_t i = 0; i < count; i++)
    {
        // 插入随机数
        try
        {
            arr[i] = rand() % 1000;
        }
        catch (char const *error)
        {
            cout << error << endl;
        }
    }

    cout << "-------------------" << endl;
    arr.print();
    cout << "-------------------" << endl;

    // 排序
    arr.Sort();
    arr.print();
    cout << "-------------------" << endl;


    // 特化类型
    Array<char*> arr2;
    arr2[0] = "d";
    arr2[1] = "c";
    arr2[2] = "b";
    arr2[3] = "a";
    arr2[4] = "123";
    arr2.print();
    cout << "-------------------" << endl;
    arr2.Sort();
    cout << "--------- char sort----------" << endl;
    arr2.print();

    return 0;
}
