#include<stdio.h>
#include<unistd.h>
int main()
{
	pidt childpid = fork();
	if(childpid == -1){
		perror("fork failed");
		return 1;
	}
	if(childpid == 0) {
		printf("child pid: %d\n",getpid());
		printf("parent pid: %d\n",getpid());
	}
	else {
		printf("parent pid: %d\n",getpid());
		printf("child pid: %d\n",childpid);
	}
	return 0;
}

