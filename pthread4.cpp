#include <iostream>
#include <pthread.h>
#include <semaphore.h>

sem_t mysem;

void *thread_fn1(void *)
{
    sem_wait(&mysem);
    std::cout << "came out of waiting time" << std::endl;
}

void *thread_fn2(void *)
{
    std::cout << "enter something" << std::endl;
    int k;
    std::cin >> k;
    sem_post(&mysem);
}

int main()
{
    sem_init(&mysem, 0, 0);
    pthread_t tid1, tid2;
    pthread_create(&tid1, 0, thread_fn1, 0);
    pthread_create(&tid2, 0, thread_fn2, 0);
    pthread_join(tid1, 0);
    pthread_join(tid2, 0);
    return 0;
}