#include "user/user.h"
#include "kernel/types.h"

int main(){
    int p[2];
    char child=7;
    char parent=8;
    pipe(p);
    if (fork() == 0){
       
        read(p[0], &parent ,1);
        printf("%d recieved ping\n",getpid());
        write(p[1], &child, 1); 
        exit(0);
    }

    else if(fork >0){
        write(p[1], &parent, 1);
        wait(0); 
        read(p[0], &child ,1);
        printf("%d recieved pong\n",getpid());
        exit(0);
    }
    return(0);
    
    
}