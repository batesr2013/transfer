#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int M = 3;
int enter(sem_t* s){
	int k;
	sem_wait(s);//couldn't get POSIX Semaphores to work always put up an error like it wasn't accessing the library that is clearly there at the top.
	if(s < M){//test
		printf("failed");
	}
	else{
		printf("sem = %d\n", k);//output
	}
	return k;
}

void leave(sem_t* s){
	sem_post(s);
}

void doCriticalWork(int k){
	printf("M = %d, thread = %d \n", M, k);//output
}

void doWork(sem_t* s){
	int k;
	while(1){
		k = enter(s);
		doCriticalWork(k);
		leave(s);
	}
}

int main(){
	pthread_t arrayThread[10];
	sem_t s;
	int count;

	return 0;
}
