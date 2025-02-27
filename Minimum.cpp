#include <iostream> 
#include <string.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h> 
using namespace std; 

int mini(int array[], int start, int end){
    int minimum = array[start];
for (int i = start; i < end; ++i) {
    if (array[i] < minimum)
    minimum = array[i];
    }   
    return minimum;
}

int main() { 
srand(time(0));
 int arr [20];
 int arrsize=sizeof(arr)/sizeof(arr[0]);
 
 for (int i = 0; i < arrsize; ++i) {
        arr[i] = (rand() % 100) + 1;
        printf("%d ", arr[i]);
        if (i == (arrsize - 1)) 
        cout << endl;
    }
 
 int fd[2];

 if  (pipe(fd)==-1) {
     return 1;
 }

 int id=fork();//
 
 if (id==-1) {
     return 2;
 }

 if (id==0) { //child proccess
    close(fd[0]);
    int child_min = mini(arr, arrsize/2, arrsize);
    write(fd[1], &child_min, sizeof(child_min));
    close(fd[1]);
    printf("Child's process id is  %d\n", getpid());
    cout << "Child minimum: " << child_min << endl;
    exit(0);
 }
 else { //parent proccess
    close(fd[1]);
    int parent_min = mini(arr, 0, arrsize/2);
    int child_min;
    read(fd[0], &child_min, sizeof(child_min));
    close(fd[0]);
    printf("Parent's process id is  %d\n",getpid());
    cout << "Parent minimum: " << parent_min << endl;
    waitpid(id, NULL, 0);
    
    int final_min = min(parent_min, child_min);
    cout << "The final minimum is " << final_min;
 }

return 0;
}