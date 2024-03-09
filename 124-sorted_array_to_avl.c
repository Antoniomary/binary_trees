#include "binary_trees.h"

void create_avl_tree(avl_t **tree, avl_t *parent, int *ar, size_t l, size_t r);

/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 *
 * Return: a pointer to the root node of the created AVL tree,
 *         or NULL (failure)
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array || !size)
		return (NULL);

	create_avl_tree(&tree, NULL, array, -1, size);

	return (tree);
}

/**
 * create_avl_tree - a function that recursively divides a tree and makes
 * an avl tree from a sorted array.
 * @tree: the root of the tree.
 * @parent: a pointer to the parent node of cureent node to create.
 * @ar: pointer to the array of integer to create AVL tree from.
 * @l: lower bound.
 * @r: upper bound.
 */
void create_avl_tree(avl_t **tree, avl_t *parent, int *ar, size_t l, size_t r)
{
	size_t mid;

	if (r - l > 1)
	{
		mid = l + (r - l) / 2;
		*tree = binary_tree_node(parent, ar[mid]);
		create_avl_tree(&(*tree)->left, *tree, ar, l, mid);
		create_avl_tree(&(*tree)->right, *tree, ar, mid, r);
	}
}
