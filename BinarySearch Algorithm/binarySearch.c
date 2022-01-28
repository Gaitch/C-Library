#include <stdio.h>
#include <math.h>
#include "binarySearch.h"

/**
* Function: binarySearch
* ----------------------
*
* Implementation of the binary search algorithm to search for 
* a value in an array
*
* data(array):		array of values
* length(integer):	length of the array
* input(integer:	value that is searched for
*
* return(int):		index of searched value
*/
int binarySearch(int data[], int length, int input)
{
	int index = length / 2;			// start in the middle of array
	int previousIndex = length;		// start with the highest index of array
	int maxI = log2(length)+1;		// max number of iterations needed

	for (int i = 0; i <= maxI; i++)
	{
		if (input == data[index])
		{
			printf("Input found at Index %d after %d iterations\n", index, i);
			return index;
		}
		if (input < data[index])
		{
			previousIndex = index;
			index = index / 2;
		}
		else
		{
			index = (index + previousIndex) / 2;
		}
	}
		
	printf("RIP - VALUE EXISTS BUT COULD NOT FIND IT\n");
	return -1;
}