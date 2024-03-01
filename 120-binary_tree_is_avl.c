#include "binary_trees.h"

int bt_is_avl(const binary_tree_t *tree, int min, int max);
size_t bt_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - a function that checks if a binary tree is
 * a valid AVL Tree.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, or 0 if not.
 *         0 also is tree is NULL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_is_avl(tree, INT_MIN, INT_MAX));
}

/**
 * bt_is_avl - a function that checks if a binary tree is a valid AVL Tree.
 * @tree: a pointer to the root node of the tree to check.
 * @min: the lower bound.
 * @max: the upper bound.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int bt_is_avl(const binary_tree_t *tree, int min, int max)
{
	int balance_factor;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	balance_factor = bt_height(tree->left) - bt_height(tree->right);
	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (bt_is_avl(tree->left, min, tree->n) &&
			bt_is_avl(tree->right, tree->n, max));
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
