#include "binary_trees.h"

size_t bt_depth(const binary_tree_t *tree);

/**
 * binary_tree_depth - a function that measures the depth of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the depth.
 *
 * Return: if tree is NULL, must return 0, else the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_depth(tree));
}

/**
 * bt_depth - a recursive function that measures the depth of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the depth.
 *
 * Return: the depth >= 0.
 */
size_t bt_depth(const binary_tree_t *tree)
{
	if (!tree->parent)
		return (0);

	return (1 + bt_depth(tree->parent));
}
