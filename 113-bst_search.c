#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search.
 * @value: the value to search in the tree.
 *
 * Return: a pointer to the node containing a value equals to value.
 *         NULL if tree is NULL or value is not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree)
	{
		if (tree->n == value)
			break;
		else if (tree->n > value)
			tree = tree->left;
		else /* tree->n < value */
			tree = tree->right;
	}

	return ((bst_t *) tree);
}
