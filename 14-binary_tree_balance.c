#include "binary_trees.h"

size_t bt_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 *
 * Description: the balance factor is measured by minusing the height of
 * left subtree from the right-subtree.
 *
 * Return: if tree is NULL, must return 0, else the balance.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_height(tree->left) - bt_height(tree->right));
}

/**
 * bt_height - a recursive function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height >= 0.
 */
size_t bt_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);

	left = bt_height(tree->left);
	right = bt_height(tree->right);

	return ((left >= right ? left : right) + 1);
}
