#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 *
 * @tree: pointer to the root node
 *
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
