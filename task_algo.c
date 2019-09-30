/*
 ============================================================================
 Name        : linear_search.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#include"algo.h"

int main(void) {
	int position = 0;
	int arr[10]={22,5,12,19,26,36,54,52,87,95};
	position = linearSearch(arr,10,87);
	printf("%d\n",position); // result is 8
	position = BinarySearch(arr,0,10,26);
	printf("%d\n",position); //result is 6
	//bubbleSorting(arr,10);
	//printArray(arr,10);
	//selectionSort(arr,10);
	//printArray(arr,10);
	mergeSort(arr,0,9);
	printArray(arr,10);

	return 0;
}
