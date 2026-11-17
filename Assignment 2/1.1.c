#include<stdio.h>
int main(){
    int arr[100],n;

    printf("Enter size of array");
    scanf("%d",&n);
    printf("Enter elements");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int pos,item;
   printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter element: ");
    scanf("%d", &item);

    for(int i = n; i >= pos; i--){
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = item;
    n++;

    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}


