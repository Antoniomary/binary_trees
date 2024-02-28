#include "binary_trees.h"

void bt_inorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_inorder - a function that goes through a binary tree
 * using in-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
		bt_inorder(tree, func);
}

/**
 * bt_inorder - a recursive function that traverses a binary tree in inorder
 *
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void bt_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	bt_inorder(tree->left, func);
	func(tree->n);
	bt_inorder(tree->right, func);
}
