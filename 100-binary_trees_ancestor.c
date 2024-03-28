#include "binary_trees.h"
#include <stdlib.h>

/**
 * depth - measures the depth of a node
 *
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of a node
 */
static size_t depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (depth(tree->parent) + 1);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t d1 = 0, d2 = 0;

	if (!first || !second)
		return (NULL);

	d1 = depth(first), d2 = depth(second);

	while (d1 > d2)
		first = first->parent, d1--;

	while (d2 > d1)
		second = second->parent, d2--;

	while (first != second)
		first = first->parent, second = second->parent;

	if (!first || !second)
		return (NULL);

	return ((binary_tree_t *)first);
}
