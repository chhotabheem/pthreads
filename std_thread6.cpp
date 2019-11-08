#include<iostream>
#include<thread>
#include<future>
using namespace std;

void thread_fn(promise<string> *prom)
{
    string s("message from thread fn");
    prom->set_value(s);
}

int main()
{
    promise<string> prom;
    future<string> ft = prom.get_future();
    thread t1(thread_fn, &prom);
    string s = ft.get();
    cout<<s<<endl;
    if(t1.joinable())
    {
        t1.join();
    }
    return 0;
}
