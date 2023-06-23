#include "sort.h"

void merge_sort(int *array, size_t size);
void subarrayMerge(int *ptrToSubarr, int *buffPtr, size_t frntIdx,
		size_t midIdx, size_t bckIdx);
void recursive_merge_sort(int *ptrToSubarr, int *buffPtr, size_t frntIdx,
		size_t bckIdx);


/**
 * merge_sort - implements the merge sort algorithm to sort an array
 *		of integers in ascending order
 * @array: integer array
 * @size: size of the array
 *
 * Description: iterates while printing until the array is fully sorted
 */
void merge_sort(int *array, size_t size)
{
	int *valOfBuff;

	/*  checks if the array is NULL or if it contains less than 2 elements */
	if (array == NULL || size < 2)
	{
		return;
	}

	valOfBuff = malloc(sizeof(int) * size);

	if (valOfBuff == NULL)
	{
		return;
	}

	recursive_merge_sort(array, valOfBuff, 0, size);

	free(valOfBuff);
}


/**
 * subarrayMerge - merges two subarrays into a single sorted subarray
 * @ptrToSubarr: pointer to the original array containing the subarrays
 * @buffPtr: pointer to the buffer array for temporary storage
 * @frntIdx: starting index of the first subarray
 * @midIdx: ending index of the first subarray and the starting index
 *		of the second subarray
 * @bckIdx: ending index of the second subarray.
 */
void subarrayMerge(int *ptrToSubarr, int *buffPtr, size_t frntIdx,
		size_t midIdx, size_t bckIdx)
{
	size_t tempForFront, tempForMid, buff_temp = 0;

	printf("Merging...\n[left]: ");
	print_array(ptrToSubarr + frntIdx, midIdx - frntIdx);

	printf("[right]: ");
	print_array(ptrToSubarr + midIdx, bckIdx - midIdx);

	for (tempForFront = frntIdx, tempForMid = midIdx;
			tempForFront < midIdx && tempForMid < bckIdx; buff_temp++)
	{
		buffPtr[buff_temp] = (ptrToSubarr[tempForFront] <
				ptrToSubarr[tempForMid]) ? ptrToSubarr[tempForFront++] :
			ptrToSubarr[tempForMid++];
	}
	for (; tempForFront < midIdx; tempForFront++)
	{
		buffPtr[buff_temp++] = ptrToSubarr[tempForFront];
	}
	for (; tempForMid < bckIdx; tempForMid++)
	{
		buffPtr[buff_temp++] = ptrToSubarr[tempForMid];
	}
	for (tempForFront = frntIdx, buff_temp = 0; tempForFront < bckIdx;
			tempForFront++)
	{
		ptrToSubarr[tempForFront] = buffPtr[buff_temp++];
	}

	printf("[Done]: ");
	print_array(ptrToSubarr + frntIdx, bckIdx - frntIdx);
}

/**
 * recursive_merge_sort - via recursion implements a merge sort algorithm
 * @ptrToSubarr: pointer to the original array containing the subarrays
 * @buffPtr: pointer to the buffer array for temporary storage
 * @frntIdx: starting index of the first subarray
 * @bckIdx: ending index of the second subarray.
 */
void recursive_merge_sort(int *ptrToSubarr, int *buffPtr, size_t frntIdx,
		size_t bckIdx)
{
	size_t valOfMid;

	/* checks if the subarray size is greater than 1. If not */
	/* it means the subarray is already sorted */
	if (bckIdx - frntIdx > 1)
	{
		valOfMid = frntIdx + (bckIdx - frntIdx) / 2;
		recursive_merge_sort(ptrToSubarr, buffPtr, frntIdx, valOfMid);

		/* recursively calls itself to sort the right half of the subarray */
		recursive_merge_sort(ptrToSubarr, buffPtr, valOfMid, bckIdx);
		subarrayMerge(ptrToSubarr, buffPtr, frntIdx, valOfMid, bckIdx);
	}
}

