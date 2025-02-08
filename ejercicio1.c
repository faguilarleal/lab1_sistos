#include <stdio.h>
#include <unistd.h>

int main(){

    
    int f = fork();
    printf("PID: %d\n", getpid());

    if (f == 0) {
        // Proceso hijo
        execl("ejercicio1.exe", (char*)NULL);
    } else {
        // Proceso padre
        printf("PID: %d\n", getpid());
        execl("ejercicio1.exe", (char*)NULL);
    }

    return 0;
}