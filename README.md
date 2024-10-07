# About
Since I'm studing data structures, I'm creating some repositories implementing some of them.

## Documentation
To use the data structure, you must import "binary_tree.c".

### Insert elements
```C
#include "binary_tree/binary_tree.c"

int main() {
	BinaryTree *binary_tree = create_binary_tree();
	insert_element(10, binary_tree);
	return 0;
}
```
