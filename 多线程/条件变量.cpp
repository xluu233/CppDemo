#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
 

//  参考：https://zhuanlan.zhihu.com/p/224054283

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

using namespace std;
 
void worker_thread()
{
    std::cout << "worker_thread start\n";

    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    //子进程的中wait函数对互斥量进行解锁，同时线程进入阻塞或者等待状态。
    cv.wait(lk, []{
        std::cout << "worker_thread wait, isready:" << ready << std::endl;;
        return ready;
    });
 
    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";
 
    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
 
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    //lk.unlock();
    cv.notify_one();
}
 
int main()
{
    std::thread worker(worker_thread);
 
    data = "Example data";
    // send data to the worker thread
    {
        //主线程堵塞在这里，等待子线程的wait()函数释放互斥量。
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    //唤醒子线程
    cv.notify_one();
 
    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{
            cout << "main thread, processed: " << processed << endl;
            return processed;
        });
    }
    std::cout << "Back in main(), data = " << data << '\n';
 
    worker.join();
}