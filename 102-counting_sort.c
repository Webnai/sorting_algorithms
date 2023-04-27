#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    int *count, *sorted;
    int max, i;

    if (!array || size < 2)
        return;

    sorted = malloc(sizeof(int) * size);
    if (!sorted)
        return;

    max = get_max(array, size);
    count = calloc(max + 1, sizeof(int));
    if (!count)
    {
        free(sorted);
        return;
    }

    for (i = 0; i < size; i++)
        count[array[i]]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    print_array(count, max + 1);

    for (i = size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(count);
}
