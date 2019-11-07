#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mux;
void thread_fn1()
{
    for(int i=0; i<100; ++i)
    {
        mux.lock();
        cout<<"message from thread1"<<endl;
        mux.unlock();

    }
}

void thread_fn2()
{
    for(int i=0; i<100; ++i)
    {
        mux.lock();
        cout<<"message from thread2"<<endl;
        mux.unlock();
    }
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
