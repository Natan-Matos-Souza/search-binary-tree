#include "../binary_node/binary_node.c"
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
