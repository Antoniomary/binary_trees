#include "binary_trees.h"

void bt_leaves(const binary_tree_t *tree, size_t *count);

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of leaves.
 *
 * Return: if tree is NULL, the function must return 0 else the size >= 1
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
		bt_leaves(tree, &count);

	return (count);
}

/**
 * bt_leaves - a recursive that counts the leaves in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of leaves.
 * @count: a pointer to a counter variable.
 *
 * Return: an int >= 1
 */
void bt_leaves(const binary_tree_t *tree, size_t *count)
{
	if (!tree)
		return;

	bt_leaves(tree->left, count);
	bt_leaves(tree->right, count);

	if (!tree->left && !tree->right)
		++*count;
}
