#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm with Knuth sequence.
 *
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	/* Generate the Knuth sequence for intervals */
	size_t interval = 1;
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (size_t i = interval; i < size; i++)
		{
			int key = array[i];
			int j = i;

			/* Insertion sort within the interval */
			while (j >= interval && array[j - interval] > key)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = key;
		}

		/* Decrease the interval */
		interval /= 3;
	}
}
