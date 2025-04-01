#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

// Define a mutex variable
pthread_mutex_t mutex;
// Shared variable
int shared_data = 0;


// Thread function writing data 10 times
void* Thread_1(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mutex);
        shared_data++;
        cout << "Written Thread:" << shared_data << endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

// Thread function reading data 10 times
void* Thread_2(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mutex);
        cout << "Read Thread:" << shared_data << endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&t1, NULL, Thread_1, NULL);
    pthread_create(&t2, NULL, Thread_2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}