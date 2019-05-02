#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	printf("Next value:\t\t\t");
	char str[1];
	gets(str);
	int val = atoi(str);
	
	while (val != -1) {
		int *pointer = &val;
			
		printf("Pointer points to value:\t%d\n", *pointer);
		printf("Value stored in address:\t%#x\n", &val);
		printf("Pointer holds value:\t\t%#x\n", pointer);
		
		printf("\n\nNext value:\t\t\t");
		gets(str);
		val = atoi(str);
	}
	
	return 0;
	
}