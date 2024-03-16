#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 3
struct thread_data{
	int thread_id; 
	int sum; 
	char *message;
};
void *print_message(void *p){
	int taskid, sum; char *msg;
	struct thread_data *my_data;
	my_data= (struct thread_data *)p; 
	taskid= my_data-> thread_id;
	sum= my_data->sum;
	msg= my_data->message; 
	printf("Thread ID: %d \t Sum: %d\t Message: %s\n",taskid, sum, msg);
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];
	int sum=0, t;
	char *messages[NUM_THREADS];
	
	struct thread_data st[NUM_THREADS];
	messages[0]= "English: Hello World"; 
	messages[1]= "Spanish: Hello al mundo ";
	messages[2]= "Japanese: Sekai e konnichiwa";
	for(int i=0; i<NUM_THREADS; i++){
		sum= sum+i;
		st[i].thread_id= i;
		st[i].sum= sum;
		st[i].message= messages[i];
		printf("Creating a thread: %d\n", i);
		pthread_create(&threads[i],NULL,print_message,(void *)&st[i]);
	}
	pthread_exit(NULL);
	return 0;
}
