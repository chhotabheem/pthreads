#include<iostream>
#include<thread>
#include<condition_variable>
#include<chrono>
#include<mutex>
using namespace std;

condition_variable conv;
mutex mux;
void thread_fn1()
{
unique_lock<mutex> unilock(mux);
    conv. wait(unilock);
    cout<<"signal reached thread1"<<endl;
}

void thread_fn2()
{
    cout<<"inside thread 2"<<endl;
    this_thread::sleep_for(chrono::seconds(3));
    conv.notify_one();
}

int main()
{
    thread t1(thread_fn1);
    thread t2(thread_fn2);
    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();
    return 0;
}
