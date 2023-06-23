#include "sort.h"


void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t startIdx, size_t sArrSize,
		char flowDir);
void recursive_bitonic_sequence(int *array, size_t size, size_t startIdx,
		size_t sArrSize, char flowDir);
void int_swapper(int *first_int, int *second_int);


/**
 * bitonic_sort - implements the bitonic sort algorithm to sort an
 *		array of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	recursive_bitonic_sequence(array, size, 0, size, UP);
}


/**
 * bitonic_merge - Perform a bitonic merge on a subarray within the given array
 * @array: array of integers
 * @size: size of the array
 * @startIdx: starting index of the subarray to be merged
 * @sArrSize: size of the subarray to be merged
 * @flowDir: flow direction of the merge (UP or DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t startIdx,
	size_t sArrSize, char flowDir)
{
	size_t stepper = sArrSize / 2;
	size_t idx;

	if (sArrSize > 1)
	{
		for (idx = startIdx; idx < startIdx + stepper; idx++)
		{
			if ((flowDir == UP && array[idx] > array[idx + stepper]) ||
			    (flowDir == DOWN && array[idx] < array[idx + stepper]))
				int_swapper(array + idx, array + idx + stepper);
		}

		bitonic_merge(array, size, startIdx, stepper, flowDir);
		bitonic_merge(array, size, startIdx + stepper, stepper, flowDir);
	}
}

/**
 * recursive_bitonic_sequence - Perform a bitonic sequence operation
 *		on a subarray within the given array
 * @array: array of integers
 * @size: size of the array
 * @startIdx: starting index of the subarray to be merged
 * @sArrSize: Tsize of the subarray to be merged
 * @flowDir: flow direction of the merge (UP or DOWN)
 */
void recursive_bitonic_sequence(int *array, size_t size, size_t startIdx,
		size_t sArrSize, char flowDir)
{
	size_t splitter = sArrSize / 2;
	char *str_content;

	str_content = (flowDir == UP) ? "UP" : "DOWN";

	if (sArrSize > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sArrSize, size, str_content);
		print_array(array + startIdx, sArrSize);

		recursive_bitonic_sequence(array, size, startIdx, splitter, UP);
		recursive_bitonic_sequence(array, size, startIdx + splitter, splitter, DOWN);
		bitonic_merge(array, size, startIdx, sArrSize, flowDir);

		printf("Result [%lu/%lu] (%s):\n", sArrSize, size, str_content);
		print_array(array + startIdx, sArrSize);
	}
}

/**
 * int_swapper - responsible for swapping two integers of an arr
 * @first_int: first integer to be swapped.
 * @second_int: second integer to be swapped.
 */
void int_swapper(int *first_int, int *second_int)
{
	int temp_value;

	temp_value = *first_int;
	*first_int = *second_int;
	*second_int = temp_value;
}
