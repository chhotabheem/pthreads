#include <iostream>
#include <thread>
//using namespace std;

void thread_fn()
{
    std::cout << "message from thread_fn" << std::endl;
}

int main()
{
    std::thread t1(thread_fn);
    if (t1.joinable())
    {
        t1.join();
    }
    return 0;
}
