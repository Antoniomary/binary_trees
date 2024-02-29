#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs a left-rotation
 * on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right;

	if (!tree || !tree->right)
		return (NULL);

	right = tree->right;
	tree->parent = right;
	right->parent = NULL;
	if (right->left)
		right->left->parent = tree;
	tree->right = right->left;
	right->left = tree;

	return (right);
}
