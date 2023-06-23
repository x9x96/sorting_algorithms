#include "sort.h"

void int_swapper(int *first_int, int *second_int);


/**
 * selection_sort - implements the selection sort algorithm to sort
 *		an array of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void selection_sort(int *array, size_t size)
{
	int *min_val;
	size_t x;
	size_t y;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (x = 0; x < size - 1; x++)
	{
		/* Assume the current element is the minimum */
		min_val = array + x;
		for (y = x + 1; y < size; y++)
		{
			/* Update min_val if a smaller element is found */
			min_val = (array[y] < *min_val) ? (array + y) : min_val;
		}

		if ((array + x) != min_val)
		{
			int_swapper(array + x, min_val);
			print_array(array, size);
		}
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
