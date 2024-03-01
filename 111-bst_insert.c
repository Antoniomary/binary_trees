#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *ptr = *tree;

	if (!tree)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!*tree)
		*tree = node;
	else
		while (ptr)
		{
			if (ptr->n == value)
				return (free(node), NULL);
			else if (ptr->n > value)
			{
				if (ptr->left)
					ptr = ptr->left;
				else
				{
					ptr->left = node, node->parent = ptr;
					break;
				}
			}
			else /* ptr->n < value */
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

	return (node);
}
