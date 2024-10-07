#include <stdlib.h>
void exit_with_error_message(char *message) {
	printf("\033[0;31m");
	printf("%s\n", message);
	printf("\033[0m");
	exit(1);
}
