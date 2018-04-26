#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numbers[1000];
int results[10];
pthread_t thread[10];
int startingindex = 0;
int total = 0;
int resultindex = 0;

void * adder(void * arg);

int main()
{
	for (int i = 0; i<1000; i++)
	{
		numbers[i] = i;
	}

	for (int i = 0; i<10; i++)
	{
		pthread_create(&thread[i], NULL, adder, NULL);

	}

	for (int i = 0; i<10; i++)
		pthread_join(thread[i], NULL);

	for (int k = 0; k < 10; k++)
	{
		printf("%s,%d\n", "Sum of thread no : ", k);
		printf("%d", results[k]);
		total += results[k];
	}

	printf("%s,%d", " Total is  : ", total);

	return 0;
}

void * adder(void * arg)
{
	results[resultindex] = 0;

	for (int i = startingindex; i<startingindex + 100; i++)
	{
		results[resultindex] += numbers[i];
	}

	startingindex += 100;
	resultindex += 1;

	return NULL;
}
