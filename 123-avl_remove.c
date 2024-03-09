#include "binary_trees.h"

void remove_node(avl_t **root, int value);
void remove_leaf(avl_t **root);
void remove_one_child(avl_t **root);
avl_t *find_min(avl_t *root);

/**
 * avl_remove - a function that removes a node from an AVL tree.
 * @root: a pointer to the root node of the tree for removing a node.
 * @value: the value to remove in the tree.
 *
 * Return: a pointer to the new root node of the tree after
 *         (1) removing the desired value, or
 *         (2) after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	remove_node(&root, value);

	return (root);
}

/**
 * remove_node - a function that removes a value from an AVL Tree.
 * @root: a double pointer to the root node of the tree for removing a node.
 * @value: the value to remove in the tree.
 */
void remove_node(avl_t **root, int value)
{
	avl_t *node;
	int balance_factor;

	if (!*root)
		return;

	if (value == (*root)->n)
	{
		if (!(*root)->left && !(*root)->right)
			remove_leaf(root);
		else if ((*root)->left && (*root)->right)
		{
			node = find_min((*root)->right);
			(*root)->n = node->n;
			remove_node(&node, node->n);
		}
		else /* has a child */
			remove_one_child(root);
	}
	else if (value < (*root)->n)
		remove_node(&(*root)->left, value);
	else /* value > (*root)->n */
		remove_node(&(*root)->right, value);

	balance_factor = binary_tree_balance(*root);
	if (balance_factor > 1)
	{
		if (binary_tree_balance((*root)->left) < 0)
			(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance((*root)->right) > 0)
			(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
}

/**
 * remove_leaf - a function that removes a leaf in an AVL Tree.
 * @root: a double pointer to the leaf to remove.
 */
void remove_leaf(avl_t **root)
{
	avl_t *node = *root, *parent = node->parent;

	if (parent->left == node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(node);
	*root = NULL;
}

/**
 * remove_one_child - a function that removes a node with a child
 * in an AVL Tree.
 * @root: a double pointer to the node to remove.
 */
void remove_one_child(avl_t **root)
{
	avl_t *node = *root, *child;

	child = node->left ? node->left : node->right;
	child->parent = node->parent;
	if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;

	free(node);
}

/**
 * find_min - a function that finds the min value in a tree.
 * @root: a pointer to the root node of the tree.
 *
 * Return: the node with the min value else NULL
 */
avl_t *find_min(avl_t *root)
{
	if (!root)
		return (NULL);

	while (root->left)
		root = root->left;

	return (root);
}
