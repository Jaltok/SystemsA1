/*****************************************************************
* Jeff Lund
* Systems - Homework A1
* Typing Speed Game


TODO comments
TODO correct sting inputs
TODO typescript
*******************************************************************/

#define _BSD_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//Swaps the strings at i and j in an array
void swap(int i, int j, char key[][10]) {
	char temp[10];
	strcpy(temp, key[i]);
	strcpy(key[i], key[j]);
	strcpy(key[j], temp);
	return;
}

int main(void) {
	
	char key[9][10] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
	//seeding random generator
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);	
	
	int j;
	//create permutation
	for(int i = 8; i > 0; i--) {
		j = rand() % (i+1);
		swap(i, j, key); 
	}

	struct timeval start, end;
	char answer[10];
	printf("Test your typing speed\n\nType the following words:\n");
	gettimeofday(&start, NULL);
	for(int i = 0; i < 9; i++) {
		while(1) {
			printf("Word %d is %s: ", i+1, key[i]);
			scanf("%s", answer);
			if(strcmp(answer, key[i]))
				printf("Incorrect. Try again.\n");
			else
				break;
		}
	}
	
	gettimeofday(&end, NULL);
	struct timeval result;
	timersub(&end, &start, &result);
	
	printf("\nFinished. Your time is:%ld sec %ld usec.\n", result.tv_sec, result.tv_usec);
	
	return 0;
}
