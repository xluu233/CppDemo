#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


std::timed_mutex mt;
std::timed_mutex mt2;

void test();
void test2();

void test(){
    if(mt.try_lock_for(chrono::seconds(2))){
        cout<<"thread:"<<this_thread::get_id()<<endl;
        mt.unlock();
    }else{
        test2();
    }

}

void test2(){
    mt2.lock();
    cout<<this_thread::get_id()<<endl;
    mt2.unlock();
}


int main(){

    thread tids[10];
    for (size_t i = 0; i < 10; i++)
    {
        tids[i] = thread(test);
    }
    
    for (auto& tid : tids)
    {
        tid.join();
    }
    
    
    return 0;
}