#include "binary_trees.h"

void bt_size(const binary_tree_t *tree, size_t *count);

/**
 * binary_tree_size - a function that measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: if tree is NULL, the function must return 0 else the size >= 1
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
		bt_size(tree, &count);

	return (count);
}

/**
 * bt_size - a recursive that measures the size of a subtree
 * @tree: a pointer to the root node of the tree to measure the size.
 * @count: a pointer to a counter variable.
 *
 * Return: an int >= 1
 */
void bt_size(const binary_tree_t *tree, size_t *count)
{
	if (!tree)
		return;

	bt_size(tree->left, count);
	bt_size(tree->right, count);

	++*count;
}
