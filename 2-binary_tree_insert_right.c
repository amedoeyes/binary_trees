#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of the parent
 *
 * @parent: pointer to the parent
 * @value: value to be inserted
 *
 * Return: pointer to the new node or Null
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	new_node->right = parent->right;
	if (new_node->right != NULL)
		new_node->right->parent = new_node;
	parent->right = new_node;

	return (new_node);
}
