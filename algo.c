/*
 * algo.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include"algo.h"
/*time analysis:
 * 2n +n+1+1 = 3n+2
 * time complexity:
 * O(n)
 */
int linearSearch(int arr[],int size,int element)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(element == arr[i])
		{
			/*return if element is found*/
			return i;
		}
	}
	/*return if element is not found*/
	return -1;
}

/*time analysis:
 * log(n)+1+2+1
 * time complexity:
 * O(log(n))
 */
int BinarySearch(int arr[], int low, int high, int element)
{
	while (low <= high) {
		int mid = low + (high - low) / 2;

		// check the middle element of the array
		if (arr[mid] == element)
			return mid;

		// If element greater, ignore left half
		if (arr[mid] < element)
			low = mid + 1;

		// If element is smaller, ignore right half
		else
			high = mid - 1;
	}

	/*return if element is not found*/
	return -1;
}
/* function to print array */
void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
/* function to swap two numbers */
void swap_func(int* num1,int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
/*time analysis:
 * 2n * (n-1) +1+1
 * time complexity:
 * in worst case:
 * O(n^2)
 */
void bubbleSorting(int arr[],int size)
{
	int i,j;

	for(i=0;i<size;i++)
	{
		unsigned char flag = 0;
		for(j=0;j<size-1;j++)
		{
			if(arr[j+1] < arr[j])
			{
				flag = 1;
				swap_func(&arr[j+1],&arr[j]);
			}
		}
		/*if condition not entered then flag = 0 indicating that the array is already sorted*/
		if(flag == 0)
			return;
	}
}
/*time analysis:
 * 2(n-1) * (n-1) +1+1+1
 * time complexity:
 * O(n^2)
 */
void selectionSort(int arr[],int size)
{
	int i,j,min,temp;
	for(i=0;i<size-1;i++)
	{
		min = i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		/*swap two numbers*/
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}
/*time analysis:
 * n/2 + n/2 + n + n/2 + n/2
 * time complexity:
 * O(n)
 */
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	/* create left and right arrays */
	int L[n1], R[n2];

	/* fill left and right arrays */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the left and right arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
/*time analysis:
 * log(n) * n
 * time complexity:
 * n log(n)
 */
void mergeSort(int arr[], int low, int high)
{
   if (low < high)
   {
      int mid = low +(high-low)/2;
      mergeSort(arr, low, mid);
      mergeSort(arr, mid+1, high);
      merge(arr, low, mid, high);
   }
}
