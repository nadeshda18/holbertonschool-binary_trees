#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_size - measure the size
 * @tree: pointer to the root of the node
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;

	if (!tree)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}