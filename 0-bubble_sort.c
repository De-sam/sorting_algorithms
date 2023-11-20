#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - This function sorts an array of numbers using bubble sort
 * in acsending order
 * @array: The unsorted array
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
