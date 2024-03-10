#include "binary_trees.h"

size_t get_tree_size(heap_t *root);

/**
 * heap_to_sorted_array - a function that converts a Binary Max Heap to a
 * sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array.
 *
 * Return: an array sorted in descending order.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted = NULL;
	size_t i;

	if (!heap)
		return (NULL);

	*size = get_tree_size(heap);
	sorted = malloc(sizeof(int) * *size);
	if (sorted)
		for (i = 0; i < *size; ++i)
			sorted[i] = heap_extract(&heap);

	return (sorted);
}

/**
 * get_tree_size - a function that gets the size of a tree.
 * @root: the root node of the tree.
 *
 * Return: the size >= 0
 */
size_t get_tree_size(heap_t *root)
{
	if (!root)
		return (0);

	return (1 + get_tree_size(root->left) + get_tree_size(root->right));
}
