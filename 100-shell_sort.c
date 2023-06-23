#include "sort.h"

void int_swapper(int *first_int, int *second_int);

/**
 * shell_sort - implements the shell sort algorithm to sort an array of
 *		integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t valOfSpace;
	size_t x;
	size_t y;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (valOfSpace = 1; valOfSpace < (size / 3);)
	{
		valOfSpace = valOfSpace * 3 + 1;
	}

	for (; valOfSpace >= 1; valOfSpace /= 3)
	{
		for (x = valOfSpace; x < size; x++)
		{
			y = x;
			/* compares each element with the elements that are space */
			/* positions before it, and swaps them if necessary to achieve */
			/* ascending order */
			while (y >= valOfSpace && array[y - valOfSpace] > array[y])
			{
				int_swapper(array + y, array + (y - valOfSpace));
				y -= valOfSpace;
			}
		}
		print_array(array, size);
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
