#include <stdio.h>

void swap(int* a, int*b);
void print(int a, int b);


int main() {
	int a, b = 0;
	
	printf("First number: ");
	scanf("%d", &a);
	
	printf("Second number: ");
	scanf("%d", &b);
	
	printf("\n");
	print(a,b);
	printf("Swapping...\n");
	swap(&a, &b);
	print(a,b);
	
	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int a, int b) {
	printf("Values are %d and %d\n", a, b);
}