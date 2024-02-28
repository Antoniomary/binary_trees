#include "binary_trees.h"

int bt_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - a function that checks if a binary tree is full.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL, your function must return 0 else
 *         0 or 1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	return (bt_is_full(tree));
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
