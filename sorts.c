#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void sort(int n, int* arr, void (*sort)(int, int*));
void selectionSort(int n, int* arr);
void insertionSort(int n, int* arr);
void mergeSort(int n, int* arr);
void mergeHelper(int n, int* arr, int start, int end);
void merge(int n, int*arr, int start1, int start2, int end);
void quickSort(int n, int* arr);
void quickSortHelper(int n, int* arr, int start, int end);
void heapSort(int n, int* arr);
void swap(int i, int j, int* arr);
void print(int n, int* arr);
void printPivot(int n, int* arr, int pivot);
int* copy(int n, int* arr);


int main() {
	
	srand(time(0));
	
	int n;
	printf("How many numbers? ");
	scanf("%d", &n);
	
	int* arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	
	//sort array
	sort(n, arr, selectionSort);
	sort(n, arr, insertionSort);
	sort(n, arr, mergeSort);
	sort(n, arr, quickSort);
	
	free(arr);
	
	return 0;
}

void sort(int n, int* arr, void (*sort)(int, int*)) {
	arr = copy(n, arr);
	sort(n, arr);
	free(arr);
}


void print(int n, int* arr) {
	printf("[");
	for (int i = 0; i < n - 1; i++) {
		printf("%02d, ", arr[i]);
	}
	printf("%02d]\n", arr[n-1]);
}

void printPivot(int n, int* arr, int pivot) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("[");
	for (int i = 0; i < n - 1; i++) {
		if (i != pivot) 
			printf("%02d, ", arr[i]);
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("%02d, ", arr[i]);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
	printf("%02d]\n", arr[n-1]);
}

int* copy(int n, int*arr) {
	int* cp = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cp[i] = arr[i];
	}
	return cp;
}

void swap(int i, int j, int* arr) {
	int temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

void selectionSort(int n, int* arr) {
	printf("\nSelection Sort:\n");
	print(n, arr);
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(i, min, arr);
		print(n, arr);
	}
}

void insertionSort(int n, int* arr) {
	printf("\nInsertion Sort:\n");
	print(n, arr);
	for (int i = 1; i < n; i++) {
		int j = i;
		while (arr[j] < arr[j-1] && j > 0) {
			swap(j, j-1, arr);
			j--;
		}
		print(n, arr);
	}
}

void mergeSort(int n, int* arr) {
	printf("\nMerge Sort:\n");
	print(n, arr);
	mergeHelper(n, arr, 0, n);
}

void mergeHelper(int n, int* arr, int start, int end) {
	if (end - start > 1) {
		int mid = (start + end) / 2;
		mergeHelper(n, arr, start, mid);
		mergeHelper(n, arr, mid, end);
		
		merge(n, arr, start, mid, end);
	}
}

void merge(int n, int* arr, int start1, int start2, int end) {
	int size = end - start1;
	int* temp = malloc(size * sizeof(int));
	
	int i = 0, a = start1, b = start2;
	while (a < start2 && b < end) {
		if (arr[a] < arr[b]) {
			temp[i] = arr[a];
			a++;
		} else {
			temp[i] = arr[b];
			b++;
		}
		i++;
	}
	while (a < start2) {
		temp[i] = arr[a];
		a++;
		i++;
	}
	while (b < end) {
		temp[i] = arr[b];
		b++;
		i++;
	}
	
	for (int j = 0; j < size; j++) {
		arr[j + start1] = temp[j];
	}
		
	print(size, temp);
	
	free(temp);
}

void quickSort(int n, int* arr) {
	printf("\nQuick Sort:\n");
	print(n, arr);
	quickSortHelper(n, arr, 0, n);
	print(n, arr);
}

void quickSortHelper(int n, int* arr, int start, int end) {
	if (end - start > 1) {
		int i = start;
		for (int j = start; j < end - 1; j++) {
			if (arr[j] < arr[end-1]) {
				swap(i, j, arr);
				i++;
			}
		}
		swap(i, end-1, arr);
		printPivot(n, arr, i);
		quickSortHelper(n, arr, start, i);
		quickSortHelper(n, arr, i+1, end);
	}
}