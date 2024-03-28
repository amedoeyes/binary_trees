#include "binary_trees.h"
#include <stdlib.h>

/**
 * height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the tree
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left_height = 1;
	size_t right_height = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = 1 + height(tree->left);
	if (tree->right != NULL)
		right_height = 1 + height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height(tree->left) - height(tree->right));
}
