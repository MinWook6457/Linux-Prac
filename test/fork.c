#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int Var = 6;
char Buf[] = "a write to stdout\n";

void main(){
	int var;
	pid_t pid;

	var = 88;
	write(STDOUT_FILENO, Buf, sizeof(Buf)-1);
	printf("Before Fork\n");

	// 
	if((pid = fork())< 0){
		perror("fork");
		exit(1);
	}else if(pid == 0){
		// child process
		Var++;
		var++;
	}else{
		// parent process 
		sleep(2);
	}

	printf("pid = %d, Var = %d, var = %d\n", getpid(), Var, var); // getpid() => return process ID of calling process

}
