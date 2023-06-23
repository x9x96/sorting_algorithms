#include "sort.h"

void int_swapper(int *first_int, int *second_int);


/**
 * bubble_sort - implements the bubble sort algorithm to sort an array of
 *		integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t len_of_arr;
	size_t x;
	bool check_sorted = false;

	/* Return early if the array is NULL or has less than 2 elements*/
	if (array == NULL || size < 2)
	{
		return;
	}

	for (len_of_arr = size; check_sorted == false; len_of_arr--)
	{
		check_sorted = true;

		for (x = 0; x < len_of_arr - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				/*Swap the values of the preceeding elements for the latter*/
				int_swapper(array + x, array + x + 1);
				print_array(array, size);
				check_sorted = false;
			}
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
