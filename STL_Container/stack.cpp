#include "container.h"

// stack代表栈，FILO（先进后出），相反的是queue队列FIFO （先进先出）

void popStack(stack<int>& st){
    while (!st.empty())
    {
        cout << st.top() << " - ";
        st.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;
    for (size_t i = 0; i < 5; i++)
    {
        st.push(i);
    }
    st.push(999);
    
    cout << st.top() << endl;
    // 删除栈顶元素，没有返回值
    st.pop();

    popStack(st);
    

}

