#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: pointer to the node
 *
 * Return: pointer to the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
