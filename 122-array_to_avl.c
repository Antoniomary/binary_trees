#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 *
 * Return: a pointer to the root node of the created AVL tree,
 *         or NULL (failure)
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (!array || !size)
		return (NULL);

	for (i = 0; i < size; ++i)
		avl_insert(&tree, array[i]);

	return (tree);
}
