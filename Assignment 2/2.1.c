#include <stdio.h>
#include <limits.h>
int main()
{
    int arr[100], n;
    int a = INT_MIN;
    int b = INT_MIN;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(arr[i] > a)  {
            b = a;
            a = arr[i];
        }
        else if(arr[i] > b && arr[i] != a){
            b = arr[i];
        }
    }

    if(b == INT_MIN)
    {
        printf("Second largest element does not exist.");
    }
    else
    {
        printf("Second largest element = %d", b);
    }

    return 0;
}