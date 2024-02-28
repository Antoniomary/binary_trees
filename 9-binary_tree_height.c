#include "binary_trees.h"

size_t bt_height(const binary_tree_t *tree);

/**
 * binary_tree_height - a function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, must return 0, else the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_height(tree));
}

/**
 * bt_height - a recursive function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height >= 0.
 */
size_t bt_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);

	left = bt_height(tree->left);
	right = bt_height(tree->right);

	return ((left >= right ? left : right) + 1);
}
