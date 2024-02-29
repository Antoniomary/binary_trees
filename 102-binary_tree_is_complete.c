#include "binary_trees.h"

int bt_complete(const binary_tree_t *tree, size_t i, size_t size);
size_t bt_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - a function that checks if a binary tree
 * is complete
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if a complete binary tree else 0 if:
 *         it is not or tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_complete(tree, 0, bt_size(tree)));
}

/**
 * bt_size - a recursive that measures the size of a subtree
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: an int >= 1
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + bt_size(tree->left) + bt_size(tree->right));
}

/**
 * bt_complete - a recursive function that checks if a binary tree
 * is complete
 * @tree: a pointer to the root node of the tree to check.
 * @i: the current index.
 * @size: the number of nodes in the binary tree.
 *
 * Return: 1 if a complete binary tree else 0
 */
int bt_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	if (i >= size)
		return (0);

	return (bt_complete(tree->left, 2 * i + 1, size) &&
			bt_complete(tree->right, 2 * i + 2, size));
}
