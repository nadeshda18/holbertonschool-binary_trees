#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if its perfect
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right) &&
			binary_tree_depth(tree->left) == binary_tree_depth(tree->right))
	{
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	}

	else
	{
		return (0);
	}
}
/**
 * binary_tree_height - measure the height
 * @tree: pointer to the root of the node
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height += 1 + binary_tree_height(tree->left);

	if (tree->right != NULL)
		right_height += 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}
/**
 *binary_tree_depth - measure the depth of a node
 *@tree: pointer to the node to measure
 * Return: 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
	{
		depth += 1 + binary_tree_depth(tree->parent);
	}
	return (depth);
}
