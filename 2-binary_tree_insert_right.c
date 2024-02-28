#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as the
 * right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	 * this takes care of the right node in cases where
	 * (1) parent right node is null
	 * (2) parent right node already has a child
	 * in case (2), the new child takes on the old as its right child.
	 */
	node->right = parent->right;
	parent->right = node;
	if (node->right)
		node->right->parent = node;

	node->left = NULL;

	return (node);
}
