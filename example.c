#include <stdio.h>
#include <stdlib.h>

long long fib(int n) {
	if (n <= 0) return -1;
	if (n < 3) return 1;
	
	long long f1 = 1;
	long long f2 = 1;
	
	for (int i = 2; i < n; i++) {
		long long temp = f2;
		f2 = f1 + f2;
		f1 = temp;
	}
	
	return f2;
}

int main(int argc, char **argv) {
	
	for (int i = 1; i < argc; i++)
		printf("%d ", fib(atol(argv[i])));
	printf("\n");
	
	return 0;
}
