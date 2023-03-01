#include <iostream>


using namespace std;


template <typename T, int default_size>
class Stack
{
private:
    int top;
    //实际size
    int size;
    T *arr;
public:
    Stack(){
        top = -1;
        //避免初始化为0的场景
        size = default_size <= 0 ? 1 : default_size;
        arr = new T[size];
    }

    bool isFull(){
        if (top >= size-1)
            return true;
        else 
            return false;
    }

    bool isEmpty(){
        if (top < 0)
            return true;
        else
            return false;
    }

    void push(T& t){
        if (isFull())
        {
            // 自动扩容
            reSizeStack();
        }

        arr[++top] = t;
        cout << "push:  " << t << endl;
    }


    /**
    * 数组扩容 
    */
    void reSizeStack(){
        int new_size = size*2;
        T *new_arr = new T[new_size];

        for (size_t i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }

        //删除原数组
        delete[] arr;
        arr = new_arr;
        size = new_size;
    }

    const T& peek(){
        if (isEmpty())
        {
            throw "stack is empty";
        }
        else
        {
            return arr[top];
        }
    }


    T& pop(){
        if (isEmpty())
        {
            throw "stack is empty";
        }
        else
        {
            return arr[top--];
        }
    }


    ~Stack(){
        cout << "deleted stack, size:" << size << endl;
        delete[] arr;
    }
};


int main(){

    int size = 20;

    Stack<int,0> stack;


    for (int i = 0; i < size; i++)
    {
        int ele = i*i;
        try
        {
            stack.push(i);
        }
        catch(char const* e)
        {
            cout << e << endl;
        }
    }
    

    cout << "peek:  " << stack.peek() << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "pop:  " << stack.pop() << endl;
    }
    
    return 0;
}