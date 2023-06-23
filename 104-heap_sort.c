#include "sort.h"

void heap_sort(int *array, size_t size);
void Maintain_max_heap(int *array, size_t size,
		size_t idxOfBase, size_t idxOfRoot);
void int_swapper(int *first_int, int *second_int);


/**
 * heap_sort - implements the heap sort algorithm to sort an
 *		array of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (idx = (size / 2) - 1; idx >= 0; idx--)
	{
		Maintain_max_heap(array, size, size, idx);
	}

	/* rearranges the elements to satisfy the */
	/* max heap property, where the parent node is always */
	/* greater than its children */
	for (idx = size - 1; idx > 0; idx--)
	{
		int_swapper(array, array + idx);
		print_array(array, size);
		Maintain_max_heap(array, size, idx, 0);
	}
}

/**
 * Maintain_max_heap - Maintain the max heap property of a binary heap
 * @array: pointer to the array
 * @size: array size
 * @idxOfBase: base index of the current sub-heap
 * @idxOfRoot: root index of the current sub-heap
 */
void Maintain_max_heap(int *array, size_t size, size_t idxOfBase,
		size_t idxOfRoot)
{
	size_t largest_index;
	size_t idxOfRight;
	size_t idxOfLeft;

	idxOfLeft = 2 * idxOfRoot + 1;
	idxOfRight = 2 * idxOfRoot + 2;
	largest_index = idxOfRoot;

	if (idxOfLeft < idxOfBase && array[idxOfLeft] > array[largest_index])
	{
		largest_index = idxOfLeft;
	}
	if (idxOfRight < idxOfBase && array[idxOfRight] > array[largest_index])
	{
		largest_index = idxOfRight;
	}

	if (largest_index != idxOfRoot)
	{
		int_swapper(array + idxOfRoot, array + largest_index);
		print_array(array, size);
		Maintain_max_heap(array, size, idxOfBase, largest_index);
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
