#include <stdio.h>
#include <pthread.h>

void PrintMsg(char *msg){
	printf("%s",msg);

	pthread_exit(NULL);
}

void main(){
	pthread_t tid1, tid2;
	char *msg1 = "Hello, ";
	char *msg2 = "Wordl!\n";

	if(pthread_create(&tid1, NULL, (void *)PrintMsg, (void *)msg1) < 0){
		perror("pthread_create");
		exit(1);
	}
        if(pthread_create(&tid2, NULL, (void *)PrintMsg, (void *)msg2) < 0){
                perror("pthread_create");
                exit(1);
        }

	printf("Threads created : tid = %lu , %lu \n",tid1,tid2);

	if(pthread_join(tid1,NULL) < 0){
		perror("pthread_join");
		exit(1);
	}

        if(pthread_join(tid2,NULL) < 0){
                perror("pthread_join");
                exit(1);
        }

	printf("Threads terminated : tid = %lu , %lu \n",tid1,tid2);
}
