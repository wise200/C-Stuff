#include <stdio.h>

int main() {
	char buffer[1];
	
	printf("Enter values:");
	
	gets(buffer);
	
	printf("\nYou entered:");
	
	puts(buffer);
}