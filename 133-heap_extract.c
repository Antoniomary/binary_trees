#include "binary_trees.h"

void find_last_levelorder(heap_t *root, size_t i, size_t size, heap_t **node);
size_t get_size(heap_t *root);
void heapify_down(heap_t *node);

/**
 * heap_extract - a function that extracts the root node of a Max Binary Heap.
 * @root: a double pointer to the root node of heap.
 *
 * Return: the value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int value = 0;
	size_t size;
	heap_t *node = NULL;

	if (*root)
	{
		value = (*root)->n;
		size = get_size(*root);
		if (size > 1)
		{
			find_last_levelorder(*root, 0, size, &node);
			(*root)->n = node->n;
			free(node);
			heapify_down(*root);
		}
		else
		{
			free(*root);
			*root = NULL;
		}
	}

	return (value);
}

/**
 * find_last_levelorder - a recursive function that gets the right most
 * node in the lowest level.
 * @root: the root of the tree.
 * @i: the index of current node.
 * @size: the size of the whole tree.
 * @node: double pointer to hold address of the last node in the lowest level
 */
void find_last_levelorder(heap_t *root, size_t i, size_t size, heap_t **node)
{
	if (!root)
		return;

	if (i + 1 == size)
	{
		*node = root;
		if (root->parent && root->parent->left == *node)
			root->parent->left = NULL;
		else
			root->parent->right = NULL;
	}
	else
	{
		find_last_levelorder(root->left, 2 * i + 1, size, node);
		find_last_levelorder(root->right, 2 * i + 2, size, node);
	}
}

/**
 * get_size - a function that gets the size of a tree.
 * @root: the root node of the tree.
 *
 * Return: the size >= 0
 */
size_t get_size(heap_t *root)
{
	if (!root)
		return (0);

	return (1 + get_size(root->left) + get_size(root->right));
}

/**
 * heapify_down - a recursive function that max heapifies a tree by moving
 * from top to bottom.
 * @node: a pointer to the node to check its value.
 */
void heapify_down(heap_t *node)
{
	int temp;
	heap_t *max = node;

	if (!node)
		return;

	if (node->left && node->left->n > max->n)
		max = node->left;
	if (node->right && node->right->n > max->n)
		max = node->right;

	if (max != node)
	{
		temp = max->n;
		max->n = node->n;
		node->n = temp;
		heapify_down(max);
	}
}
