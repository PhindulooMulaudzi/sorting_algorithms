#include "sort.h"
#include <stdio.h>

/**
 * partition - Get partition for quicksort using the Lomuto scheme
 * @array: array
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 *
 * Return: partition index
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array`
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
