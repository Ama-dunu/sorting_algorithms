#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Perform a Lomuto partition on an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Perform the quicksort using the Lomuto partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array.
 * @right: The ending index of the array.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int partition;

    if (right - left > 0)
    {
        partition = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, partition - 1);
        lomuto_sort(array, size, partition + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * using the quicksort algorithm with Lomuto partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
