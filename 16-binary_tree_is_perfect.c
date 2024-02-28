#include "binary_trees.h"

int bt_is_full(const binary_tree_t *tree);
size_t bt_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: if not perfect or tree is NULL, 0 else 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_is_full(tree) &&
			(bt_height(tree->left) == bt_height(tree->right)));
}

/**
 * bt_is_full - a recursive function that checks if a binary tree is full.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 0 if not full or 1 if full.
 */
int bt_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (!(bt_is_full(tree->left) ^ bt_is_full(tree->right)));
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
