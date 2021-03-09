#include "user/user.h"
#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/stat.h"


int main(int argc, char *argv[]){
    char buf[128]; 
    char *p = buf;
    int argv_len = argc - 1;
    char *gbuf[MAXARG];
    
    for (int i=1; i < argc; i++){
        gbuf[i-1] = argv[i];
    }
    gbuf[argv_len++]=p;
    while (read(0, p, 1)){
        if (*p == '\n'){
            *p=0;
            gbuf[argv_len++] = p+1;
        }
        p++;
    }
    if(fork()==0){
        exec(gbuf[0], gbuf);
        exit(0);
    }
    else{
        wait(0);
    }
    exit(0);
}