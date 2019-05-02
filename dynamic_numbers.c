#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, *ptr, sum = 0;
	
	printf("How many elements? ");
	scanf("%d", &n);
	
	ptr = (int*) malloc(n * sizeof(int));
	if (ptr == NULL) {
		printf("ERROR: Not enough space?");
		return 1;
	}
	
	printf("Enter elements: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", ptr + i);
		sum += *(ptr+i);
	}
	
	printf("Sum: %d\nValues: ", sum);
	for (int i = 0; i < n; i++) {
		printf("%d ", *(ptr+i));
	}
	printf("\n");
	
	free(ptr);
	return 0;
}