#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
long long sqList[1000];
struct StructSqVariabel{
	long long start; 
	long long end; 
};
void *sq(void *sqVars){
	struct structSqVariables *val= (struct structSqVariables)sqVars; 
	long long startLimit= val->start; 
	long long endLimit= val->end;
	for(long long num= startLimit; num<= endLimit; num++){
		sqList[num]= num*num;
	}
	pthread_exit(0);
}
int main(){
	long long compCount= 1000;
	int threadCount= 7; 
	int remainder= compCount%threadCount; 
	int sliceList[threadCount];
	for(int i=0; i<threadCount; i++){
		sliceList[i]= compCount/threadCount;
//		printf("%d\n",sliceList[i]);
	}
	for(int j= 0; j<remainder; j++){
		sliceList[j]= sliceList[j]+1;
	}
	int startList[threadCount];
	int endList[threadCount];
	for(int l=0; l<threadCount; l++){
		if(l==0){
			startList[l]=0;
		}else{
			startList[l]= ;
		}
		endList[l]= startList[l]+sliceList[l]-1;
		
	}
	struct structSqVariables mainStruct[threadCount];
	for(int k=0; k<threadCount; k++){
		mainStruct[k].start= startList[k];
		mainStruct[k].end= endList[k];
	}
	pthread_t threadIds[threadCount];
	for(int m=0; m<threadCount; m++){
		pthread_attr_t attr; 
		pthread_attr_init(&attr);
		pthread_create(&threadIds[m], &attr, sq, &mainStruct[m]);
	}
	for(int n= 0; n< threadCount; n++){
		pthread_join(threadIds[n], NULL);
	}
	for(long long t= 0; t<compCount; t++){
		printf("%lld\n",sqList[t]);
	}
}
