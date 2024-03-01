#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);
bst_t *successor(bst_t *tree, bst_t *min);
void remove_leaf(bst_t **root, bst_t *leaf);
void remove_node_with_a_child(bst_t **root, bst_t *node);

/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree to remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing
 * the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *replace;

	node = bst_search(root, value);
	if (node)
	{
		if (!node->left && !node->right) /* node to remove is leaf node */
			remove_leaf(&root, node);
		else if (node->left && node->right) /* has two children */
		{
			replace = successor(node->right, node->right);
			if (replace)
			{
				if (replace->parent->left == replace)
					replace->parent->left = replace->left;
				else
					replace->parent->right = replace->right;

				replace->parent = node->parent;
				replace->left = node->left;
				replace->right = node->right;

				if (!node->parent) /* node to remove is root node */
					root = replace;
				else
				{
					if (node->parent->left == node)
						node->parent->left = replace;
					else
						node->parent->right = replace;
				}
				free(node);
			}
		}
		else /* has one child */
			remove_node_with_a_child(&root, node);
	}

	return (root);
}

/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search.
 * @value: the value to search in the tree.
 *
 * Return: a pointer to the node containing a value equals to value.
 *         NULL if tree is NULL or value is not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree)
	{
		if (tree->n == value)
			break;
		else if (tree->n > value)
			tree = tree->left;
		else /* tree->n < value */
			tree = tree->right;
	}

	return ((bst_t *) tree);
}

/**
 * successor - a recursive function that finds the min value node in a tree.
 * @tree: the tree to check.
 * @min: the variable to hold the min.
 *
 * Return: the node with the min value or NULL if tree is NULL.
 */
bst_t *successor(bst_t *tree, bst_t *min)
{
	if (!tree)
		return (min);

	if (min->n > tree->n)
		min = tree;

	return (successor(tree->left, min));
}

/**
 * remove_leaf - a function that removes a leaf node.
 * @root: the root node of the BST.
 * @leaf: the leaf to remove.
 */
void remove_leaf(bst_t **root, bst_t *leaf)
{
	bst_t *parent = leaf->parent;

	if (!parent) /* it is the root node*/
		*root = NULL;
	else /* not the root node */
	{
		if (parent->left == leaf)
			parent->left = NULL;
		else
			parent->right = NULL;
	}

	free(leaf);
}

/**
 * remove_node_with_a_child - a function that removes a node with
 * only one child.
 * @root: the root node of the BST.
 * @node: the node with one child to be removed.
 */
void remove_node_with_a_child(bst_t **root, bst_t *node)
{
	bst_t *node_parent = node->parent, *node_child;

	node_child = node->left ? node->left : node->right;
	if (!node_parent)
	{
		node_child->parent = node_parent;
		*root = node_child;
	}
	else
	{
		if (node_parent->left == node)
			node_parent->left = node_child;
		else
			node_parent->right = node_child;
		node_child->parent = node_parent;
	}

	free(node);
}
