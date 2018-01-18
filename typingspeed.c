/*****************************************************************
* Jeff Lund
* Systems - Homework A1
* Typing Speed Game
*******************************************************************/

#define _BSD_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define MAX_WORD_LENGTH 6
#define TOTAL_WORDS 9
//Swaps the strings at i and j in an array
void swap(int i, int j, char key[][MAX_WORD_LENGTH]) {
	char temp[MAX_WORD_LENGTH];
	strcpy(temp, key[i]);
	strcpy(key[i], key[j]);
	strcpy(key[j], temp);
	return;
}

int main(void) {
	
	char key[TOTAL_WORDS][MAX_WORD_LENGTH] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
	//seeding random generator
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);	
	
	int j;
	//create permutation
	for(int i = TOTAL_WORDS -1; i > 0; i--) {
		j = rand() % (i+1);
		swap(i, j, key); 
	}

	struct timeval start, end;
	char answer[11];
	printf("Test your typing speed\n\nType the following words:\n");
	gettimeofday(&start, NULL); //starting time
	for(int i = 0; i < TOTAL_WORDS; i++) {
		while(1) {
			printf("Word %d is %s: ", i+1, key[i]);
			scanf("%10s", answer);
			if(strncmp(answer, key[i], MAX_WORD_LENGTH))
				printf("Incorrect. Try again.\n");
			else
				break;
		}
	}
	
	gettimeofday(&end, NULL); //ending time
	struct timeval result;
	timersub(&end, &start, &result); //total time taken
	
	printf("\nFinished. Your time is: %ld sec %ld usec.\n", result.tv_sec, result.tv_usec);
	
	return 0;
}
