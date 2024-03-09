#include "binary_trees.h"

size_t bt_size(const binary_tree_t *tree);
int bt_is_heap(const binary_tree_t *tree, size_t i, size_t size);

/**
 * binary_tree_is_heap - a function that checks if a binary tree is a valid
 * Max Binary Heap
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 *         If tree is NULL, then 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = bt_size(tree);

	return (bt_is_heap(tree, 0, size));
}

/**
 * bt_size - a recursive function that finds the size of a tree.
 * @tree: a pointer to the root node of the tree.
 *
 * Return: size of the tree >= 0
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + bt_size(tree->left) + bt_size(tree->right));
}

/**
 * bt_is_heap - a recursive function that checks if a binary tree is max heap.
 * @tree: a pointer to the root.
 * @i: the index of the node in the tree.
 * @size: the number of nodes in the tree.
 *
 * Return: 1 if tree is Max Binary Heap or 0.
 */
int bt_is_heap(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	if (i >= size)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (bt_is_heap(tree->left, 2 * i + 1, size) &&
			bt_is_heap(tree->right, 2 * i + 2, size));
}
