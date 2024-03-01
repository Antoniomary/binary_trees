#include "binary_trees.h"

int bt_is_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - a function that checks if a binary tree is
 * a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 *         0 if tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * bt_is_bst - a function that checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: a pointer to the root node of the tree to check.
 * @min: the lower bound.
 * @max: the upper bound.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int bt_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (bt_is_bst(tree->left, min, tree->n) &&
			bt_is_bst(tree->right, tree->n, max));
}
