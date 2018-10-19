
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int array[1000];
int chunk_size=100;
void *Addition( void *arg)
{
    int initial=(int)arg; //type casting of recieved argument into integer
    int final=initial+chunk_size;
    int sum=0;
    for (int i=initial ; i<final ; i++)
    {
        sum=sum+array[i];
    }
    return ((void*)sum);
}
int main()
{
    int status_s1,status_s2,status_s3,status_s4,status_s5,status_s6,status_s7,status_s8,status_s9,status_s10;
    pthread_t thread_t1, thread_t2,thread_t3,thread_t4,thread_t5,thread_t6,thread_t7,thread_t8,thread_t9,thread_t10;
    for (int i=0; i<1000; i++)
    {
        array[i]=i; //initializing array with number starting from 1
    }
    
    pthread_create(&thread_t1,NULL,Addition,(void*)(0 * chunk_size));
    pthread_create(&thread_t2,NULL,Addition,(void*)(1 * chunk_size));
    pthread_create(&thread_t3,NULL,Addition,(void*)(2 * chunk_size));
    pthread_create(&thread_t4,NULL,Addition,(void*)(3 * chunk_size));
    pthread_create(&thread_t5,NULL,Addition,(void*)(4 * chunk_size));
    pthread_create(&thread_t6,NULL,Addition,(void*)(5 * chunk_size));
    pthread_create(&thread_t7,NULL,Addition,(void*)(6 * chunk_size));
    pthread_create(&thread_t8,NULL,Addition,(void*)(7 * chunk_size));
    pthread_create(&thread_t9,NULL,Addition,(void*)(8 * chunk_size));
    pthread_create(&thread_t10,NULL,Addition,(void*)(9 * chunk_size));
    
    pthread_join(thread_t1, (void**) & status_s1);
    pthread_join(thread_t2, (void**) & status_s2);
    pthread_join(thread_t3, (void**) & status_s3);
    pthread_join(thread_t4, (void**) & status_s4);
    pthread_join(thread_t5, (void**) & status_s5);
    pthread_join(thread_t6, (void**) & status_s6);
    pthread_join(thread_t7, (void**) & status_s7);
    pthread_join(thread_t8, (void**) & status_s8);
    pthread_join(thread_t9, (void**) & status_s9);
    pthread_join(thread_t10, (void**) & status_s10);
    
    int sum= status_s1+status_s2+status_s3+status_s4+status_s5+status_s6+status_s7+status_s8+status_s9+status_s10;
    printf("TotalSum : %d\n", sum);

    return 0;
}


