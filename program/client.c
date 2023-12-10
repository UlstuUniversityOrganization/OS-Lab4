#include <stdio.h>
#include <windows.h>
#include "threadpool.h"

struct data {
    int a;
    int b;
};

void add(void* param) {
    struct data* temp;
    temp = (struct data*)param;

    printf("I add two values %d and %d result = %d\n", temp->a, temp->b, temp->a + temp->b);
}

int main(void) {
    // create some work to do
    struct data work1;
    work1.a = 1;
    work1.b = 1;

    struct data work2;
    work2.a = 2;
    work2.b = 2;

    struct data work3;
    work3.a = 3;
    work3.b = 3;

    // initialize the thread pool
    pool_init();

    // submit the work to the queue
    pool_submit(&add, &work1);
    pool_submit(&add, &work2);
    pool_submit(&add, &work3);

    pool_submit(&add, &work1);
    pool_submit(&add, &work2);
    pool_submit(&add, &work3);

    pool_submit(&add, &work1);
    pool_submit(&add, &work2);
    pool_submit(&add, &work3);

    pool_submit(&add, &work1);
    pool_submit(&add, &work2);
    pool_submit(&add, &work3);

    // shutdown the thread pool
    pool_shutdown();

    return 0;
}