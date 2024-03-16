#include <stdio.h>
#include <Windows.h>
#include <pthread.h>
void *threadOne(void *p){
	int i, c;
	int nstart=1, nfinish= 100;

	for(i=nstart; i<=nfinish; i++){
		for(c=2; c<= i-1; c++){
			if(i%c==0){
				break;
			}
		}
		if(c==i){
			printf("Thread One: %d\n", i);
		}
	}	
}
void *threadTwo(void *p){
	int i, c;
	int nstart=100, nfinish= 200;
	printf("Prime numbers between %d and %d are: \n",
	nstart, nfinish);
	for(i=nstart; i<=nfinish; i++){
		for(c=2; c<= i-1; c++){
			if(i%c==0){
				break;
			}
		}
		if(c==i){
			printf("Thread Two: %d\n", i);
		}
	}
}
int main(){
	
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, threadOne, NULL);
	pthread_create(&thread2, NULL, threadTwo, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;  

}
