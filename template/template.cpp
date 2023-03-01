#include <iostream>
using namespace std;

// 实现升序排列的模板函数
template<typename T>
void sort(T *t,int size){
    for (size_t i = 0; i < size; i++)
    {
        int p = i;
        for (size_t j = i; j < size; j++)
        {
            if(t[p] > t[j]){
                p = j;
            }
        }
        T temp = t[i];
        t[i] = t[p];
        t[p] = temp;
    }
}

// 对于char类型按照降序
template<> void sort<char>(char *t,int size){
    for (size_t i = 0; i < size; i++)
    {
        int p = i;
        for (size_t j = i; j < size; j++)
        {
            if(t[p] < t[j]){
                p = j;
            }
        }
        char temp = t[i];
        t[i] = t[p];
        t[p] = temp;
    }
}

template<class T>
void show(T t,int size){
    for (size_t i = 0; i < size; i++)
    {
        cout<<t[i]<<endl;
    }
}

// 模板类
template<class T,int max_size>
class List{
    private:
        T list[max_size];
    public:
        List(){
            //初始化全部为0
            for (size_t i = 0; i < max_size; i++)
            {
                list[i] = 0;
            }
        };
        T& operator[](int n){
            if (n<0 || n>=max_size)
            {
                throw("index error");
            }
            return list[n];
        };
        ~List(){
            cout<<"deleted list"<<endl;
        };
};




int main(){

    // int a[] = {12,3,56,456,1,-1,-10,0,9,1231234};
    // char b[] = {'a','A','v','d','t','y','u','p','E','W'};
    // sort(a,10);
    // show(a,10);
    // sort(b,10);
    // show(b,10);

    List<int,10> list1;
    for (size_t i = 0; i < 5; i++)
    {
        list1[i] = i+100;
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout<< list1[i] <<endl;
    }


    system("pause");
    return 0;
}