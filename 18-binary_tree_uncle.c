#include "binary_trees.h"

/**
 * binary_tree_uncle - a function that finds the uncle of a node.
 * @node: a pointer to the node to find the uncle.
 *
 * Return: pointer to the uncle node if it exists else NULL if not
 *         or if node is NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent, *leftchild, *rightchild;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grandparent = node->parent->parent;
	leftchild = grandparent->left;
	rightchild = grandparent->right;

	return (node->parent == leftchild ? rightchild : leftchild);
}
