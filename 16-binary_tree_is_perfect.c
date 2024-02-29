#include "binary_trees.h"

size_t bt_height(const binary_tree_t *tree);
size_t bt_size(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: if not perfect or tree is NULL, 0 else 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, size = 0, max_node = 1;

	if (!tree)
		return (0);

	height = bt_height(tree);
	size = bt_size(tree);

	height += 1;
	while (height--)
		max_node *= 2;
	max_node -= 1;

	return (size == max_node);
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

/**
 * bt_size - a recursive function that counts the nodes in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 *
 * Return: an int >= 1
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_size(tree->left) + bt_size(tree->right) + 1);
}
