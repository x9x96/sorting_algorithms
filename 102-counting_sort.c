#include "sort.h"

int find_max(int *array, int size);

/**
 * counting_sort - implements the counting sort algorithm to sort a
 *		doubly-linked list in ascending order
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void counting_sort(int *array, size_t size)
{
	int idx, *isSorted, MaximVal, *isCounted;

	if (array == NULL || size < 2)
		return;

	isSorted = malloc(sizeof(int) * size);
	if (isSorted == NULL)
		return;
	MaximVal = find_max(array, size);
	isCounted = malloc(sizeof(int) * (MaximVal + 1));
	if (isCounted == NULL)
	{
		free(isSorted);
		return;
	}

	for (idx = 0; idx < (MaximVal + 1); idx++)
		isCounted[idx] = 0;
	for (idx = 0; idx < (int)size; idx++)
		isCounted[array[idx]] += 1;
	for (idx = 0; idx < (MaximVal + 1); idx++)
		isCounted[idx] += isCounted[idx - 1];
	print_array(isCounted, MaximVal + 1);

	for (idx = 0; idx < (int)size; idx++)
	{
		isSorted[isCounted[array[idx]] - 1] = array[idx];
		isCounted[array[idx]] -= 1;
	}

	for (idx = 0; idx < (int)size; idx++)
		array[idx] = isSorted[idx];

	free(isSorted);
	free(isCounted);
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
	/* initializes the maximum value (MaximVal) with the */
	/* first element of the array */
	int MaximVal;
	int idx;

	for (MaximVal = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > MaximVal)
			MaximVal = array[idx];
	}

	return (MaximVal);
}
