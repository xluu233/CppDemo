#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>


using namespace std;

void function1(int i){
    cout << this_thread::get_id() << endl;
}

int main(){

    thread thread1(function1,12);

    thread1.join();
    
    return 0;
}