#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a right-rotation
 * on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left;

	if (!tree || !tree->left)
		return (NULL);

	left = tree->left;
	left->parent = tree->parent;
	tree->parent = left;
	if (left->right)
		left->right->parent = tree;
	tree->left = left->right;
	left->right = tree;

	return (left);
}
