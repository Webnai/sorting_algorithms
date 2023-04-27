#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two subarrays of arr[].
 * @arr: The array to be sorted.
 * @l: Left index of the subarray.
 * @m: Middle index of the subarray.
 * @r: Right index of the subarray.
 */
void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temporary arrays */
	int *L = malloc(sizeof(int) * n1);
	int *R = malloc(sizeof(int) * n2);

	/* copy data to temporary arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* merge the temporary arrays back into arr[l..r] */
	i = 0; /* initial index of first subarray */
	j = 0; /* initial index of second subarray */
	k = l; /* initial index of merged subarray */
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
			/* print merged elements */
			printf("Merging...\n");
			print_array(&arr[k], n1 + n2 - k);
		}
		k++;
	}

	/* copy the remaining elements of L[], if there are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* copy the remaining elements of R[], if there are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	/* free temporary arrays */
	free(L);
	free(R);
}

/**
 * merge_sort_recursive - Recursively sorts an array in ascending order
 *                        using the merge sort algorithm.
 * @arr: The array to be sorted.
 * @l: Left index of the subarray.
 * @r: Right index of the subarray.
 */
void merge_sort_recursive(int *arr, int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		/* sort first and second halves */
		merge_sort_recursive(arr, l, m);
		merge_sort_recursive(arr, m + 1, r);

		/* merge the sorted halves */
		merge(arr, l, m, r);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}
