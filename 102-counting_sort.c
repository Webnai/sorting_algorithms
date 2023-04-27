#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int *count, *sorted, max, i;

    if (array == NULL || size < 2)
        return;

    sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
        return;

    max = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
    {
        free(sorted);
        return;
    }

    for (i = 0; i < (max + 1); i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    printf("Counting array:");
    print_array(count, max + 1);

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted[i];

    free(count);
    free(sorted);
}
