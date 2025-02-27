// FindMinimum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <string.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h> 
#include <io.h>
using namespace std; 

int main() {

    int arr[] = { 1,2,3,4,1,2,4,5 };
    int start, end;
    int arrsize = sizeof(arr) / sizeof(int);
    printf("array size: %d\n", arrsize);
    int fd[2];

    if (pipe(fd) == -1) {
        return 1;
    }

    int id = fork();
    if (id == -1) {
        return 2;
    }

    if (id == 0) {
        start = 0;
        end = start + arrsize / 2;
        printf("child loop from 0 to  : %d\n", end);
    }
    else {
        start = arrsize / 2 + 1;
        end = arrsize;
        printf("parent loop from  : %d\n", start);
    }

    int sum = 0;
    int i;
    for (i = start; i < end; i++) {
        sum += arr[i];
    }

    printf("calculated sum: %d\n", sum);

    if (id == 0) {
        printf("child's process id is  %d\n", getpid());
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else {
        printf("parent's process id is  %d\n", getpid());
        close(fd[1]);
        int childSum;
        read(fd[0], &childSum, sizeof(int));
        close(fd[0]);
        int total = sum + childSum;
        printf("Total is : %d\n", total);
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
