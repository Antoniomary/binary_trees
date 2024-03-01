#include "binary_trees.h"

void bt_levelorder(const binary_tree_t *tree, void (*func)(int), int depth);
int bt_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, depth;

	if (tree && func)
	{
		height = bt_height(tree);

		for (depth = 0; depth < height; ++depth)
			bt_levelorder(tree, func, depth);
	}
}

/**
 * bt_levelorder - a recursive function that traverses a binary tree
 * in level order
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * @depth: a variable that keeps track of the level
 */
void bt_levelorder(const binary_tree_t *tree, void (*func)(int), int depth)
{
	if (depth == 0)
		func(tree->n);
	else
	{
		bt_levelorder(tree->left, func, depth - 1);
		bt_levelorder(tree->right, func, depth - 1);
	}
}

/**
 * bt_height - a recursive function that gets the height of a binary tree.
 * @tree: a pointer to the root node of the tree to find height.
 *
 * Return: the height of tree >= 1.
 */
int bt_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = bt_height(tree->left);
	right = bt_height(tree->right);

	return (1 + (left >= right ? left : right));
}
