#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <cmath>



using namespace std;


int main(){
    cout << "async test start" << endl;

    int result = 0;
    //async配合lamda表达式
    auto task = async([&result](){
        cout << "thread id: " << this_thread::get_id() << endl;
        for (size_t i = 0; i < 100; i++)
        {
            result += sqrt(i);
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });
    task.wait();

    cout << "result:" << result << endl;
    cout << "async test end" << endl;
    return 0;
}