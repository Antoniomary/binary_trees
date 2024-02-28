#include "binary_trees.h"

void bt_preorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_preorder - a function that goes through a binary tree
 * using pre-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
		bt_preorder(tree, func);
}

/**
 * bt_preorder - a recursive function that traverses a binary tree in preorder
 *
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 */
void bt_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	func(tree->n);

	bt_preorder(tree->left, func);
	bt_preorder(tree->right, func);
}
