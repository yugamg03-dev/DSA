#include<stdio.h>
int main(){
    int a[100],n;

    printf("Enter size of array");
    scanf("%d", &n);

    printf("Enter array elements");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int pos;
    printf("Enter position to delete ");
    scanf("%d",&pos);

    for(int i = pos-1; i<n-1; i++){
        a[i] = a[i + 1];
    }
    n--;

printf("Array after deletion:");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}