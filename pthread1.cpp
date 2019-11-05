#include <iostream>
#include <pthread.h>

void *thread_fn(void *)
{
    std::cout << "this is from thread_fn" << std::endl;
}

int main()
{
    pthread_t threadid;
    pthread_create(&threadid, 0, &thread_fn, NULL);
    pthread_join(threadid, NULL);
    return 0;
}