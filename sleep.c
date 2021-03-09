#include "user/user.h"
#include "kernel/types.h"



int main(int var,const char *l[]){

    if (var < 2){
        printf("Please enter the number of ticks\n");
    }
    else{
        int ticks = atoi(l[1]);
        sleep(ticks*10);
    }
    exit(0);

}