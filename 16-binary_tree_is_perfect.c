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
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = 1 + height(tree->left);
	if (tree->right != NULL)
		right_height = 1 + height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: size of tree
 */
static size_t size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (size(tree->left) + 1 + size(tree->right));
}

/**
 * _pow - calculates the power of a number
 *
 * @x: base
 * @y: exponent
 *
 * Return: base^exponent
 */
static int _pow(int x, int y)
{
	int i;
	int j = 1;

	for (i = 0; i < y; i++)
		j *= x;

	return (j);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_pow(2, height(tree) + 1) - 1 == (int)size(tree));
}
