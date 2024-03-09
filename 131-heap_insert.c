#include "binary_trees.h"

size_t bt_size(heap_t *tree);
void insert_heap(heap_t *tree, heap_t *parent, heap_t **node,
		size_t i, size_t size, int n);
void heapify(heap_t *node);

/**
 * heap_insert - a function that inserts a value in Max Binary Heap.
 * @root: a pointer to the root node of the tree to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	heap_t *node = NULL;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = bt_size(*root);
	insert_heap(*root, *root, &node, 0, size, value);

	return (node);
}

/**
 * bt_size - a recursive function that finds the size of a tree.
 * @tree: a pointer to the root node of the tree.
 *
 * Return: size of the tree >= 0
 */
size_t bt_size(heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + bt_size(tree->left) + bt_size(tree->right));
}

/**
 * insert_heap - a recursive function that finds the right place and inserts
 * a node.
 * @tree: a pointer to the root.
 * @parent: the parent node to give to inserted node.
 * @node: a double pointer to the new node.
 * @i: the index of the node in the tree.
 * @size: the number of nodes in the tree.
 * @n: the value to insert.
 */
void insert_heap(heap_t *tree, heap_t *parent, heap_t **node,
		size_t i, size_t size, int n)
{
	if (i == size && !*node)
	{
		*node = binary_tree_node(parent, n);
		if (i % 2)
			parent->left = *node;
		else
			parent->right = *node;
		heapify(*node);
		return;
	}

	if (!tree)
		return;

	insert_heap(tree->left, tree, node, 2 * i + 1, size, n);
	insert_heap(tree->right, tree, node, 2 * i + 2, size, n);
}

/**
 * heapify - a function that recursively turns a tree to a max heap.
 * @node: the node to check it value.
 */
void heapify(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return;

	if (node->parent->n < node->n)
	{
		temp = node->parent->n;
		node->parent->n = node->n;
		node->n = temp;
	}

	heapify(node->parent);
}
