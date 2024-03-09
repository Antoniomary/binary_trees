#include "binary_trees.h"

avl_t *avl_balance(avl_t **tree, int value);

/**
 * avl_insert - a function that inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL to insert the value
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *ptr = *tree;

	if (!tree)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!*tree)
		return ((*tree = node));

	while (ptr)
	{
		if (ptr->n == value)
			return (free(node), NULL);
		else if (value < ptr->n)
		{
			if (ptr->left)
				ptr = ptr->left;
			else
			{
				ptr->left = node, node->parent = ptr;
				break;
			}
		}
		else /* value > ptr->n */
		{
			if (ptr->right)
				ptr = ptr->right;
			else
			{
				ptr->right = node, node->parent = ptr;
				break;
			}
		}
	}

	avl_balance(tree, value);

	return (node);
}

/**
 * avl_balance - a recursive function that balances an AVL Tree.
 * @tree: a double pointer to the root node of the AVL to insert the value
 * @value: the value that was inserted..
 *
 * Return: a pointer to the new root.
 */
avl_t *avl_balance(avl_t **tree, int value)
{
	int balance_factor;

	if (!*tree)
		return (NULL);

	if (value > (*tree)->n)
		(*tree)->right = avl_balance(&(*tree)->right, value);
	else if (value < (*tree)->n)
		(*tree)->left = avl_balance(&(*tree)->left, value);

	balance_factor = binary_tree_balance(*tree);
	if (balance_factor < -1) /* right subtree is imbalance */
	{
		if (binary_tree_balance((*tree)->right) <= 0) /* */
			*tree = binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}
	else if (balance_factor > 1) /* left subtree is imbalance */
	{
		if (binary_tree_balance((*tree)->left) >= 0) /* */
			*tree = binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}

	return (*tree);
}
