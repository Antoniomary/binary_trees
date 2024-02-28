#include "binary_trees.h"

void delete_tree(binary_tree_t *tree);

/**
 * binary_tree_delete - a function that deletes an entire binary tree.
 * @tree: pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
		delete_tree(tree);
}

/**
 * delete_tree - a recursive function that deletes an entire binary tree.
 * @tree: pointer to the parent node of sub-tree.
 */
void delete_tree(binary_tree_t *tree)
{
	if (!tree)
		return;

	delete_tree(tree->left);
	delete_tree(tree->right);

	free(tree);
}
