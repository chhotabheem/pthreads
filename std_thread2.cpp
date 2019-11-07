#include<iostream>
#include<thread>
#include<string>
using namespace std;

void thread_fn(string str)
{
    cout<<"main function says hello "<<str<<endl;
}

int main()
{
    thread t1(thread_fn, "new bee");
    if(t1.joinable())
    {
        t1.join();
    }
}
