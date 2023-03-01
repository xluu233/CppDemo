#include <iostream>
#include <thread>
using namespace std;


void function1(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << "function1:" <<this_thread::get_id() <<endl;
}

void function2(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << "function2:" <<this_thread::get_id() <<endl;
}

int main(){

    thread thread1(function1);
    thread thread2(function2);
    cout << "thread1-id:" << thread1.get_id() << "          thread2-id:" << thread2.get_id() << endl;

    swap(thread1,thread2);
    cout << "thread1-id:" << thread1.get_id() << "          thread2-id:" << thread2.get_id() << endl;

    // thread1.swap(thread2);
    // cout << "thread1-id:" << thread1.get_id() << "          thread2-id:" << thread2.get_id() << endl;

    thread1.join();
    thread2.join();
    return 0;
}