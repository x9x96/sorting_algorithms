#include "sort.h"

void quick_sort(int *array, size_t size);
int custm_lomuto_partion(int *array, size_t size, int toLeft, int toRight);
void custm_lomuto_sort(int *array, size_t size, int toLeft, int toRight);
void int_swapper(int *first_int, int *second_int);


/**
 * quick_sort - implements the quick sort algorithm to sort an
 *		array of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: Lomuto partition scheme is used for printing after each swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	custm_lomuto_sort(array, size, 0, size - 1);
}


/**
 * custm_lomuto_partion - implements the Lomuto partition scheme, which is
 *		used in the QuickSort algorithm to partition an array into
 *		two parts based on a pivot_val element
 * @array: A pointer to the array of integers
 * @size: array size
 * @toLeft: index of the leftmost element of the partition range
 * @toRight: index of the rightmost element of the partition range
 *
 * Return: index of final partition
 */
int custm_lomuto_partion(int *array, size_t size, int toLeft, int toRight)
{
	int *pivot_val;
	int idx_above;
	int idx_below;

	pivot_val = array + toRight;

	/* initializes two index variables, idx_above and idx_below */
	/* to the leftmost index */
	for (idx_above = idx_below = toLeft; idx_below < toRight; idx_below++)
	{
		if (array[idx_below] < *pivot_val)
		{
			if (idx_above < idx_below)
			{
				int_swapper(array + idx_below, array + idx_above);
				print_array(array, size);
			}
			idx_above++;
		}
	}

	if (array[idx_above] > *pivot_val)
	{
		int_swapper(array + idx_above, pivot_val);
		print_array(array, size);
	}

	return (idx_above);
}

/**
 * custm_lomuto_sort - a custom quicksort algorithm through recursion
 * @array: A pointer to the array of integers
 * @size: array size
 * @toLeft: index of the leftmost element of the partition range
 * @toRight: index of the rightmost element of the partition range
 */
void custm_lomuto_sort(int *array, size_t size, int toLeft, int toRight)
{
	int partition_idx;

	if (toRight - toLeft > 0)
	{
		partition_idx = custm_lomuto_partion(array, size, toLeft, toRight);

		/*  left partition is sorted by calling my_lomuto_sort */
		/* with the updated right index as pivot_idx - 1 */
		custm_lomuto_sort(array, size, toLeft, partition_idx - 1);
		custm_lomuto_sort(array, size, partition_idx + 1, toRight);
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
