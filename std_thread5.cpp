#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
#include<string>
using namespace std;
mutex mux;
condition_variable conv;
void thread_fn(std::string& str)
{
    this_thread::sleep_for(chrono::seconds(3));
    mux.lock();
    str = "message from thread function";
    mux.unlock();
    conv.notify_one();
}

int main()
{
    string s;
    thread t1(thread_fn, ref(s));
    unique_lock<mutex> unilock(mux);
    conv.wait(unilock);
    cout<<s<<endl;
    if(t1.joinable())
    {
        t1.join();
    }
    return 0;
}
