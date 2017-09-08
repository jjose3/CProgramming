//============================================================================
// Name        : HelloWorld.c
// Author      : Jerrin Jose
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "myfuncs.h"

long long sum = 0;

// Thread function
void* sum_runner(void* arg)
{
	long long *limiter = (long long*) arg;
	long long limit = *limiter;

	for (long long i = 0; i <= limit; i++){
		sum += i;
	}
	
	pthread_exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {

	if(argc < 2){
		printf("Usage: %s <num> \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	long long num = atoll(argv[1]);

	//Thread ID
	pthread_t tid;

	//Create attributes
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, sum_runner, &num);
	
	printf("%lld times two = %d\n", num, TimesTwo(num));
	printf("Factorial of %lld = %d\n", num, Factorial(num));
	
	//Wait until thread is done it's work
	pthread_join(tid, NULL);

	printf("Sum = %lld\n", sum);
	return EXIT_SUCCESS;
}
