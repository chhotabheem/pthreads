#include <iostream>
#include <pthread.h>

pthread_mutex_t mutex;

void *thread_fn1(void *)
{
    int n = 99;
    while (n--)
    {
        pthread_mutex_lock(&mutex);
        std::cout << "inside thread_fn1" << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

void *thread_fn2(void *)
{
    int n = 99;
    while (n--)
    {
        pthread_mutex_lock(&mutex);
        std::cout << "inside thread fn2" << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid1;
    pthread_create(&tid1, 0, thread_fn1, NULL);
    pthread_t tid2;
    pthread_create(&tid2, 0, thread_fn2, NULL);
    pthread_join(tid1, 0);
    pthread_join(tid2, 0);
    return 0;
}