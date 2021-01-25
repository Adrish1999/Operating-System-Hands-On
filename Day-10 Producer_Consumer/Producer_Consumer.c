#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define BUFFER_MAX 10

pthread_mutex_t mutex;
sem_t full, empty;
int buffer[BUFFER_MAX];
int count;
pthread_t ptid, ctid;

void *producer(void *);
void *consumer(void *);

void insert_item(int item)
{
        buffer[count++] = item;
}

int remove_item()
{
        return (buffer[count--]);
}

void initialize()
{
        pthread_mutex_init(&mutex,NULL);
        sem_init (&full,1,0);
        sem_init (&empty,1,BUFFER_MAX);
        count = 0;
}

void *producer(void *param)
{
        while(1)
        {
        int item, waittime;
        waittime = rand()%5;
        sleep(waittime);
        item = rand()%10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        printf("Producer produced item %d\n",item);
        insert_item(item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        }
}

void *consumer(void *param)
{
        while(1)
        {
        int item, waittime;
        waittime = rand()%3;
        sleep(waittime);
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = remove_item();
        printf("Consumer consumed %d\n",item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        }
}

int main()
{
        initialize();

        pthread_create(&ptid,NULL,&producer,NULL);
        pthread_create(&ctid,NULL,&consumer,NULL);

        pthread_join(ptid,NULL);
        pthread_join(ctid,NULL);

        return 0;
}

