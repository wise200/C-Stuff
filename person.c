#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
	char* name;
	int age;
};

typedef struct person human;

int main(int argc, char **argv) {
	if (argc < 5) {
		printf("Insufficient arguments.");
		return 1;
	}
	
	human temp = {argv[1], atoi(argv[2])};
	human* p1 = &temp;
	printf("%s is %d years old and located at %#x\n", p1->name, p1->age, p1);
	printf("Their name is at %#x and their age is at %#x\n\n", &p1->name, &p1->age);
	
	human temp2 = {argv[3], atoi(argv[4])};
	human* p2 = &temp2;
	printf("%s is %d years old and located at %#x\n", p2->name, p2->age, p2);
	printf("Their name is at %#x and their age is at %#x\n\n", &p2->name, &p2->age);

	return 0;
}
