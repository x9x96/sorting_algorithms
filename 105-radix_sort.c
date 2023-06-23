#include "sort.h"

void radix_sort(int *array, size_t size);
int find_max(int *array, int size);
void custom_radix_sort(int *array, size_t size, int significant, int *temp);



/**
 * radix_sort - implements the radix sort algorithm to sort an array
 *		of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void radix_sort(int *array, size_t size)
{
	int *buffer;
	int significance;
	int max_val;


	if (array == NULL || size < 2)
	{
		return;
	}

	buffer = malloc(sizeof(int) * size);

	if (buffer == NULL)
	{
		return;
	}

	max_val = find_max(array, size);

	for (significance = 1; max_val / significance > 0; significance *= 10)
	{
		custom_radix_sort(array, size, significance, buffer);
		print_array(array, size);
	}

	free(buffer);
}


/**
 * find_max - finds the maximum value in an array of integers
 * @array: A pointer to the array of integers
 * @size: array size
 *
 * Return: maximum integer in the array
 */
int find_max(int *array, int size)
{
	int valOfMax;
	int idx;

	for (valOfMax = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > valOfMax)
			valOfMax = array[idx];
	}

	return (valOfMax);
}

/**
 * custom_radix_sort - P implementation of the radix counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @significant: ssignificance of the current digit being sorted
 * @temp: temporary array
 */
void custom_radix_sort(int *array, size_t size, int significant, int *temp)
{
	size_t idx;
	int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (idx = 0; idx < size; idx++)
	{
		freq[(array[idx] / significant) % 10] += 1;
	}

	for (idx = 0; idx < 10; idx++)
	{
		freq[idx] += freq[idx - 1];
	}

	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		temp[freq[(array[idx] / significant) % 10] - 1] = array[idx];
		freq[(array[idx] / significant) % 10] -= 1;
	}

	for (idx = 0; idx < size; idx++)
	{
		array[idx] = temp[idx];
	}
}

