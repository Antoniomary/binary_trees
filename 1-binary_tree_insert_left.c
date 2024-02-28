#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the
 * left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;

	/**
	 * this takes care of the left node in cases where
	 * (1) parent left node is null
	 * (2) parent left node already has a child
	 * in case (2), the new child takes on the old as its left child.
	 */
	node->left = parent->left;
	parent->left = node;

	node->right = NULL;

	return (node);
}
