#include <stdio.h>
#include "binary_tree/binary_tree.c"

int main() {
	BinaryTree *binary_tree = create_binary_tree();
	insert_element(10, binary_tree);
	insert_element(30, binary_tree);
	insert_element(-10, binary_tree);
	printf("Value: %i\n", binary_tree->root->left_node->value);
	return 0;
}
