#include "../binary_node/binary_node.c"
#include "../errors/error_message.c"
#include <stdlib.h>

typedef struct BinaryTree {
	BinaryNode *root;
} BinaryTree;

BinaryTree *create_binary_tree() {
	BinaryTree *binary_tree = (BinaryTree*) malloc(sizeof(BinaryTree));
	binary_tree->root = NULL;
	return binary_tree;
}

void insert_element(int value, BinaryTree *binary_tree) {
	BinaryNode *node = (BinaryNode*) malloc(sizeof(BinaryNode));
	node->value = value;
	node->left_node = NULL;
	node->right_node = NULL;

	if (!binary_tree->root) {
		binary_tree->root = node;
		return;
	}

	BinaryNode *last_element = binary_tree->root;
	while (last_element->left_node || last_element->right_node) {
		if (!last_element->right_node && node->value > last_element->value) {
			break;
		}

		if (!last_element->left_node && node->value < last_element->value) {
			break;
		}

		if (node->value > last_element->value) {
			last_element = last_element->right_node;
			continue;
		}

		last_element = last_element->left_node;
	}

	if (node->value > last_element->value) {
		last_element->right_node = node;
		return;
	}

	last_element->left_node = node;
}

void remove_element(int value, BinaryTree *binary_tree)
{
	BinaryNode *current_element = binary_tree->root;
	BinaryNode *previous_element = current_element;

	while (current_element->value != value) {
		if (current_element->left_node && current_element->value > value) {
			previous_element = current_element;
			current_element = current_element->left_node;
			continue;
		}

		if (current_element->right_node && current_element->value < value) {
			previous_element = current_element;
			current_element = current_element->right_node;
			continue;
		}

		exit_with_error_message("Element not found.");
	}

	if (current_element == binary_tree->root) {
		if (!current_element->left_node && !current_element->right_node) {
			binary_tree->root = NULL;
			free(current_element);
			return;
		}

		if (current_element->left_node) {
			binary_tree->root = current_element->left_node;
			binary_tree->root->right_node = current_element->right_node;
			free(current_element);
			return;
		}

		binary_tree->root = current_element->right_node;
		free(current_element);
		return;
	}

	if (previous_element->left_node == current_element) {
		if (current_element->right_node) {
			previous_element->left_node = current_element->right_node;
			previous_element->left_node->left_node = current_element->left_node;
			free(current_element);
			return;
		}

		previous_element->left_node = current_element->left_node;
		free(current_element);
		return;
	}

	if (current_element->left_node) {
		previous_element->right_node = current_element->left_node;
		previous_element->right_node->right_node = current_element->right_node;
		free(current_element);
		return;
	}

	previous_element->right_node = current_element->right_node;
	free(current_element);
}
