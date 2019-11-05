#include <iostream>
#include <pthread.h>

void *threadfn1(void *)
{
    std::cout << "inside threadfn1" << std::endl;
}

void *threadfn2(void *)
{
    std::cout << "inside threadfn2" << std::endl;
}

int main()
{
    pthread_t pid1;
    pthread_create(&pid1, 0, &threadfn1, NULL);
    pthread_join(pid1, 0);
    pthread_t pid2;
    pthread_create(&pid2, 0, &threadfn2, NULL);
    pthread_join(pid2, 0);
    return 0;
}