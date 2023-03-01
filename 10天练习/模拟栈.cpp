#include <iostream>


using namespace std;


template <typename T, int max_size>
class Stack
{
private:
    int top;
    T *arr;
public:
    Stack(){
        top = -1;
        arr = new T[max_size];
    }

    bool isFull(){
        if (top >= max_size-1)
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
            throw "stack full";
        }
        else
        {
            arr[++top] = t;
            cout << "push:  " << t << endl;
        }
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
        delete[] arr;
        cout << "deleted stack" << endl;
    }
};


int main(){

    int size = 11;

    Stack<int,10> stack;


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
    
    //error
    //stack.peek() = 0;

    cout << "peek:  " << stack.peek() << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "pop:  " << stack.pop() << endl;
    }
    
    
    return 0;
}