#include "user/user.h"
#include "kernel/types.h"

int main(){
    int p[2];
    int c[2];
    char neighbour=0;
    int bwrite;
    int intial;
    
    
    pipe(p);
    // append all the list integers
    for (int i=2; i<=35; i++){
        write(p[1] , &i , sizeof(i));
    }
    // close all unneeded file discriptors
    close(0);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    // take awel number as my intial 2
    read(0, &intial, sizeof(intial));
    printf("prime %d\n", intial);
    //loop until you reeach the zero meaning the last charachter
    while (read (0, &bwrite, sizeof(bwrite)) != 0){ 
        //check divisability
        if ( bwrite % intial != 0){
            //check if there is another neighbour process to check its divisability as well
            if (neighbour == 0){
                pipe(c);
                if (fork()== 0){
                    //print the prime number and close all unneeded files
                    printf("prime %d\n", bwrite);
                    close(0);
                    // dup to read from 0
                    dup (c[0]);
                    close(c[0]);
                    close(c[1]);
                    // set the intial to the new prime for divisability checking as well
                    intial = bwrite;
                    
                }
                else{
                    // close all unneeded processes and 
                    close(1);
                    dup(c[1]);
                    //dup to write in 1
                    close(c[1]);
                    close(c[0]);
                    // set to one as indication of having other neighbours in future
                    neighbour = 1;
                    
                }
            }
            else if (neighbour == 1 ){
                write (1, &bwrite, sizeof(bwrite));
                
            }
        }
        else{
            continue;
        }
    } 
    close(0);
    close(1);
    wait(0);
    exit(0);
}