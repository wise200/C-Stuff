#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    while (i < strlen(a) && i < strlen(b)) {
        char aChar = *(a+i);
        char bChar = *(b+i);
        if (aChar != bChar)
            return aChar - bChar;
        i++;
    }
    return strlen(a) - strlen(b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int aChars[26] = {0};
    int bChars[26] = {0};
    
    for (int i = 0; i < strlen(a); i++) {
        int index = *(a+i) - 'a';
        if (aChars[index] == 0)
            aChars[index] = 1;
    }
    for (int i = 0; i < strlen(b); i++) {
        int index = *(b+i) - 'a';
        if (bChars[index] == 0)
            bChars[index] = 1;
    }
    
    int aCount = 0;
    int bCount = 0;
    for (int i = 0; i < 26; i++) {
        if (aChars[i] == 1) aCount++;
        if (bChars[i] == 1) bCount++;
    }
    return aCount - bCount;
}

int sort_by_length(const char* a, const char* b) {
    return strlen(a) - strlen(b);
}
void swap(char* a, char* b);


void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char** ptr1 = arr;
    for (int i = 0; i < len - 1; i++) {
        char** ptr2 = ptr1;
        char** min = ptr2;
        for (int j = i; j < len; j++) {
            if (cmp_func(*ptr2, *min) < 0) {
                min = ptr2;
            }
            ptr2++;
        }
        swap(ptr1, min);
        ptr1++;
    }
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
	
	free(arr);
}