#include "binary_trees.h"


/**
 * max - Returns the maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: the maximum of a and b
 */

int max(int a, int b)
{
	if (a > b)
		return (a);

	return (b);
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, 0 if tree is NULL
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);

	return (1 + max(left_h, right_h));
}

/**
 * tree_size - Measures the size (number of nodes) of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: number of nodes, 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, expected_size, actual_size, i;

	if (tree == NULL)
		return (0);

	h = tree_height(tree);
	actual_size = tree_size(tree);

	expected_size = 1;
	i = 0;

	while (i < h)
	{
		i++;
		expected_size = expected_size * 2;
	}
	expected_size = expected_size - 1;

	return (actual_size == expected_size);
}
