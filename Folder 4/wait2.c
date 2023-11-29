#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[])
{

    int retime=0, rutime=0, stime=0;
    int pid;
    if( (pid=fork()) < 0){
        printf(1, "fork failed\n");
        exit();
    }
    else if(pid == 0){
        // child
        long int i;
        for(i=0; i<2147483647 ; i++);
        exit();
    }
    else{
        // parent
        wait2(&retime, &rutime, &stime);
        printf(1, "PID: %d, retime: %d, rutime: %d, stime: %d\n", pid, retime, rutime, stime);
    }

    exit();

}