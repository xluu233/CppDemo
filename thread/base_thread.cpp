#include <iostream>
#include <thread>

using namespace std;

#define THREAD_NUMS 5

void say_hello(int i){
    // 线程睡眠
    this_thread::sleep_for(chrono::seconds(i));

//    if (this_thread::get_id() == 2)
//    {
//        this_thread::request_stop();
//    }

    // 获取线程id
    cout << "hello thread:"<< this_thread::get_id() << endl;
}

int main(){

    // 用来保存线程的数组
    thread tids[THREAD_NUMS];

    // 创建线程
    for (size_t i = 0; i < THREAD_NUMS; i++)
    {
        tids[i] = thread(say_hello,i);
    }
    

    // 等待所有线程执行完成
    for(auto &th : tids){
        th.join();
    }

    system("pause");
    return 0;
}