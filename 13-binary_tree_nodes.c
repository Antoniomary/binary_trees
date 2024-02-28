#include "binary_trees.h"

void bt_nodes(const binary_tree_t *tree, size_t *count);

/**
 * binary_tree_nodes - a function that counts the nodes with at least 1 child
 * in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 *
 * Return: if tree is NULL, the function must return 0 else the size >= 1
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
		bt_nodes(tree, &count);

	return (count);
}

/**
 * bt_nodes - a recursive that counts the nodes with at least 1 child
 * in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 * @count: a pointer to a counter variable.
 *
 * Return: an int >= 1
 */
void bt_nodes(const binary_tree_t *tree, size_t *count)
{
	if (!tree)
		return;

	bt_nodes(tree->left, count);
	bt_nodes(tree->right, count);

	if (tree->left || tree->right)
		++*count;
}
