#include "binary_trees.h"

int bt_depth(const binary_tree_t *node);

/**
 * binary_trees_ancestor - a function that finds the lowest common ancestor
 * of two nodes
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes.
 *         NULL if it does not exist.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	int depth_diff, diff;

	if (!first || !second)
		return (NULL);

	depth_diff = bt_depth(first) - bt_depth(second);
	diff = depth_diff;
	while (first->parent && diff > 0)
	{
		first = first->parent;
		diff--;
	}
	diff = depth_diff;
	while (second->parent && diff < 0)
	{
		second = second->parent;
		diff++;
	}

	while (1)
	{
		if (!first)
			break;

		if (first == second)
			return ((binary_tree_t *) first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}

/**
 * bt_depth - a recursive function that measures the depth of a binary tree.
 * @node: a pointer to the node of the tree to measure the depth.
 *
 * Return: the depth >= 0.
 */
int bt_depth(const binary_tree_t *node)
{
	int depth = 0;

	if (!node)
		return (0);

	while (node->parent)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}
