#include <pthread.h>
#include <stdio.h>

using namespace std;

//The thread
void* thread1_func(void* data) {
    printf("This is thread 1!\n");
}

void* thread2_func(void* data) {
    printf("This is thread 2 talking!\n");
}

void* thread3_func(void* data) {
    printf("Hello! This is thread 3.\n");
}

int main ()
{
    pthread_t id1, id2, id3;           //thread identifiers
    pthread_attr_t attr1, attr2, attr3;  //set of thread attributes
    char *tnames[3] = { "Thread 1", "Thread 2", "Thread 3" }; //names of threads
    //get the default attributes
    pthread_attr_init (&attr1);
    pthread_attr_init (&attr2);
    pthread_attr_init(&attr3);

    //create the threads
    pthread_create (&id1, &attr1, thread1_func, tnames[0]);
    pthread_create (&id2, &attr2, thread2_func, tnames[1]);
    pthread_create (&id3, &attr3, thread3_func, tnames[2]);

    //wait for the threads to exit
    pthread_join (id1, NULL);
    pthread_join (id2, NULL);
    pthread_join(id3, NULL);
    return 0;
}
