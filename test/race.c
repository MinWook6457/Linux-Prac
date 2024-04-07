#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void CharAtaTime(char *str){
	char *ptr;
	int c;

	setbuf(stdout,NULL);
	for(ptr = str ; c = *ptr++; ){
		for(int i = 0 ; i < 999999; i++);
			putc(c,stdout);
	}
}


void main(){
	pid_t pid;

	if((pid = fork())<0){
		perror("fork");
		exit(1);
	}else if(pid == 0){
		CharAtaTime("output from child \n");
	}else{
		CharAtaTime("output from parent\n");
	}
}
