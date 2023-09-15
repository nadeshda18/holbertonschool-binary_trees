#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor
 * @tree: pointer to the root node
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_balance = 0;
	int right_balance = 0;

	if (tree == NULL)
		return (0);

	left_balance = binary_tree_height(tree->left);

	right_balance = binary_tree_height(tree->right);

	return (left_balance - right_balance);
}

/**
 * binary_tree_height - measure the height
 * @tree: pointer to the root of the node
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height += 1 + binary_tree_height(tree->left);

	right_height += 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}
