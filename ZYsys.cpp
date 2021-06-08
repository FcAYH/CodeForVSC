#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define msleep(x) usleep(x * 1000) //微秒
#define PRODUCT_SPEED 2            //生产速度
#define CONSUM_SPEED 4             //消费速度
#define INIT_NUM 2                 //仓库原有产品数
#define TOTAL_NUM 6                //仓库容量
sem_t p_sem, c_sem, sh_sem;
int num = INIT_NUM;
void product(void)
{
    sleep(CONSUM_SPEED); //producer start run
    printf("The producer is produce\n");
}
int add_to_lib()
{
    num++;       //add the product to the buffer
    msleep(500); //500ms
    return num;
}
void consum()
{
    sleep(PRODUCT_SPEED); //consumer start run
    printf("The consumer is consume\n");
}
int remove_from_lib()
{
    num--; //move the product from the buffer
    msleep(500);
    return num;
}
void *productor(void *arg)
{
    while (1)
    {
        product();
        sem_wait(&p_sem);  //whether the buffer is full
        sem_wait(&sh_sem); //enter the crital area
        add_to_lib();      //add the product to the buffer
        sem_post(&sh_sem); //exit the crital area
        sem_post(&c_sem);  // nd the siginal to consumer
    }
}
void *consumer(void *arg)
{
    while (1)
    {
        sem_wait(&c_sem);  //whether the buffer is empty
        sem_wait(&sh_sem); //enter the crital area
        remove_from_lib(); //move the product from the buffer
        sem_post(&sh_sem); //exit the crital area
        sem_post(&p_sem);  // nd the siganl to producer
        consum();          //consume
    }
}
int main()
{
    pthread_t tid_1, tid_2;                        //create 2 process
    sem_init(&p_sem, 0, TOTAL_NUM - INIT_NUM);     //initial the signal of the num of current product
    sem_init(&c_sem, 0, INIT_NUM);                 //initial the num of the rest volume of buffer
    sem_init(&sh_sem, 0, 1);                       //initial the mutual signal
    pthread_create(&tid_1, NULL, productor, NULL); //create the process of producer
    pthread_create(&tid_2, NULL, consumer, NULL);  //create the process of consumer
    pthread_join(tid_1, NULL);                     //multi process run
    pthread_join(tid_2, NULL);                     //multi process run
    return 0;
}
