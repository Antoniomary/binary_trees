#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node.
 * @node: a pointer to the node to find the sibling.
 *
 * Return: pointer to the sibling node if it exists else NULL if not
 *         or if parent/node is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *leftchild, *rightchild;

	if (!node || !node->parent)
		return (NULL);

	leftchild = node->parent->left;
	rightchild = node->parent->right;

	return (node == leftchild ? rightchild : leftchild);
}
