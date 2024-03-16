#include <stdio.h>
#include <windows.h>
#include <pthread.h>

void* first(void *p){
	for(int i=0; i<8; i++){
		Sleep(1000);
		printf("I am from first: %d\n", i);
	}
}

void second(){
	for(int i=0; i<3; i++){
		Sleep(2000);
		printf("I am from second: %d\n", i);
	}
}
int main(){
	pthread_t thread1; 
	pthread_create(&thread1, NULL, first, NULL);
	//pthread_create(&thread2,)
	second();
	pthread_join(thread1, NULL);
	return 0;
}
