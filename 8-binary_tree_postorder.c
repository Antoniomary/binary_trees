#include "binary_trees.h"

void bt_postorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_postorder - a function that goes through a binary tree
 * using post-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
		bt_postorder(tree, func);
}

/**
 * bt_postorder - a recursive function that traverses a binary tree
 * in postorder
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void bt_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	bt_postorder(tree->left, func);
	bt_postorder(tree->right, func);
	func(tree->n);
}
