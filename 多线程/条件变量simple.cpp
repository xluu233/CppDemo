#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std;

std::mutex m;
std::condition_variable cv;

vector<int> arr;
const int max_size = 10;
static int n = 0;


void product(int i){
    while (true)
    {
        //this_thread::sleep_for(chrono::microseconds(100));
        unique_lock<mutex> lock(m);
        cv.wait(lock,[](){
            return arr.size() < max_size;
        });
        n++;
        arr.push_back(n);
        cout << "product thread:" << i << "   n:"  << n <<endl;
        cv.notify_all();
        //auto unlock
    }

}

void consumer(int i){
    while (true)
    {
        //this_thread::sleep_for(chrono::microseconds(200));
        unique_lock<mutex> lock(m);
        cv.wait(lock,[]{
            return !arr.empty();
        });
        int v = arr.back();
        arr.pop_back();
        n--;
        cout << "\t consumer thread:" << i << "   n:"  << v <<endl;
        cv.notify_all();
    }
    
}

int main(){

    auto thread1 = thread(product, 0);
    auto thread2 = thread(consumer, 1);

    thread1.join();
    thread2.join();
    // int count = 3;
    // for (size_t i = 0; i < count; i++)
    // {
    //     thread(product, i).join();
    // }

    // for (size_t i = 0; i < count; i++)
    // {
    //     thread(consumer, i).join();
    // }
    
}