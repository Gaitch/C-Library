#include <stdio.h>
#include "bubblesort.h"


void bubbleSort(int data[], int length)
{
	int temp = 0;
	while (length > 0)
	{
		printA(data, 10);
		for (int i = 0; i < length -1; i++)
		{
			if (data[i] > data[i + 1])
			{
				temp = data[i + 1];
				data[i + 1] = data[i];
				data[i] = temp;
			}
		}
		length--;
	}
}

