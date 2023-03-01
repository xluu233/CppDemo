#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int i =0;
mutex mt;

void safe_increment()
{
    lock_guard<mutex> lockGuard(mt);
    ++i;
    cout << this_thread::get_id() << ": " << i << endl;
    this_thread::sleep_for(chrono::seconds(3));
}
 

int main(){

    thread thread1(safe_increment);
    thread thread2(safe_increment);

    thread1.join();
    thread2.join();

    return 0;
}