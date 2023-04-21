#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array of ints to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
    unsigned int i, j;
    int tmp;
    int swapped;

    if (size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        swapped = 0; // Initialize swapped flag to 0
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                print_array(array, size);
                swapped = 1; // Set swapped flag to 1 if elements are swapped
            }
        }

        if (swapped == 0)
            break; // If no elements are swapped in the inner loop, the array is already sorted
    }
}

