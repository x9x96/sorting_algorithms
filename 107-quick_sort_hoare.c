#include "sort.h"


void quick_sort_hoare(int *array, size_t size);
int my_hoare_partition(int *array, size_t size, int toLeft, int toRight);
void my_hoare_sort(int *array, size_t size, int toLeft, int toRight);
void int_swapper(int *first_int, int *second_int);


/**
 * quick_sort_hoare - implements the quick sort algorithm to sort
 *		an array of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	my_hoare_sort(array, size, 0, size - 1);
}

/**
 * my_hoare_partition - perform the Hoare partition scheme on
 *		a subarray within the given array
 * @array: array of integers
 * @size: size of the array
 * @toLeft: left index of the subarray to be partitioned
 * @toRight: right index of the subarray to be partitioned
 *
 * Return: index of final partition
 */
int my_hoare_partition(int *array, size_t size, int toLeft, int toRight)
{
	int above_val;
	int below_val;
	int valOfPivot;

	valOfPivot = array[toRight];
	for (above_val = toLeft - 1, below_val = toRight + 1; above_val < below_val;)
	{
		do {
			above_val++;
		} while (array[above_val] < valOfPivot);

		do {
			below_val--;
		} while (array[below_val] > valOfPivot);

		if (above_val < below_val)
		{
			int_swapper(array + above_val, array + below_val);
			print_array(array, size);
		}
	}

	return (above_val);
}

/**
 * my_hoare_sort - perform the Hoare sort algorithm on a
 *		subarray within the given array
 * @array: array of integers
 * @size: size of the array
 * @toLeft: left index of the subarray to be partitioned
 * @toRight: right index of the subarray to be partitioned
 */
void my_hoare_sort(int *array, size_t size, int toLeft, int toRight)
{
	int partition;

	if (toRight - toLeft > 0)
	{
		partition = my_hoare_partition(array, size, toLeft, toRight);
		my_hoare_sort(array, size, toLeft, partition - 1);
		my_hoare_sort(array, size, partition, toRight);
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
