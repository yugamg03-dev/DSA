#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int a[], int n){
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; }
}

void bubbleSort(int a[], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1])
            {  temp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    int *a, *b;
    clock_t start, end;
    double insertionTime, bubbleTime;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        a[i] = rand() % 10000;
        b[i] = a[i];
    }
    start = clock();
    insertionSort(a, n);
    end = clock();
    insertionTime = (double)(end - start) / CLOCKS_PER_SEC;
    start = clock();
    bubbleSort(b, n);
    end = clock();
    bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nFor input size %d:\n", n);
    printf("Time taken by Insertion Sort = %f seconds\n", insertionTime);
    printf("Time taken by Bubble Sort = %f seconds\n", bubbleTime);

    free(a);
    free(b);

    return 0;
}