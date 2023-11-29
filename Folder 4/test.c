#include "types.h"
#include "user.h"
#include "stat.h"

int main(void) {
    int pid;
    pid = fork();

    if (pid == -1) {
        printf(1, "Fork failed\n");
        return -1;
    }

    if (pid == 0) {
        //child process
        for (int i=0; i<5; i++) {
            printf(1, "Child : %d\n", i);
        }
        exit();
    }

    else {
        //parent
        int stime, retime, rutime;
        printf(1, "Parent\n");
        wait2(&stime, &retime, &rutime);
        printf(1, "Child had\nsleep time\t%d\nready time\t%d\nrunningtime\t%d\n", stime, retime, rutime);
        exit();
    }

    return 0;
}