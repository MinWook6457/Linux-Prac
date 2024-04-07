#include <stdio.h>

void main(int argc, char *argv[], char *envp[]){
	char **p;
	extern char **environ;

	printf("List command-line argument\n");

	for(int i = 0 ; i < argc ; i++){
		printf("%s\n",argv[i]);
	}

	printf("\n");

	printf("List environment variables from environ variable\n");

	for(p = environ ; *p != NULL ; p++){
		printf("%s\n",*p);
	}

	printf("\n");

	printf("List enviroment variables from envp variable\n");

	for(p = envp ; *p != NULL ; p++){
		printf("%s\n",*p);
	}
}
