#include <iostream>
#include <unistd.h>
#include <pthread.h>

void *thread_fn(void *)
{
    std::cout << "inside thread fn" << std::endl;
}

int main()
{
    pthread_t tid;
    pthread_attr_t att;
    pthread_attr_init(&att);
    pthread_attr_setdetachstate(&att, PTHREAD_CREATE_DETACHED);
    pthread_create(&tid, &att, thread_fn, 0);
    sleep(2);
    return 0;
}