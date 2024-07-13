#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
 
int main() {
    int fd1, fd2, n=1;
    char buf;
    fd1 = open("f1.txt", O_RDONLY);
    fd2 = open("f2.txt", O_WRONLY|O_CREAT, S_IWUSR|S_IRUSR);
    if((fd1 == -1) || (fd2 == -1)) {
        printf("error");
    }
    else {
        while((n = read(fd1, &buf, 1)) > 0) {
            write(fd2, &buf, 1);
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}   