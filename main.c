#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <signal.h>
#include <unistd.h>
#include <sys/shm.h>

#define SHMKEY 5

int shmid, pid;

void create(){
    shmid = shmget(SHMKEY, 40, IPC_CREAT);
    
    shmctl(shmid,IPC_RMID,0);
    kill(pid, SIGTERM);
    exit(0);
}

int main() {
    pid = fork();
    
    if(pid > 0){
        signal(SIGUSR1, create);
        
        for(;;);
    }else{
        kill(pid, SIGUSR1);
        for(;;);
    }
    
}
