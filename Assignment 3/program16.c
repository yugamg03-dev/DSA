#include <stdio.h>

int main()
{
    int a[100];
    int n, i, count;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nCompressed Array:\n");
    printf("Element Frequency\n");

    i = 0;

    while(i < n)
    {
        count = 1;

        while(i + count < n && a[i] == a[i + count])
        {
            count++;
        }

        printf("%d\t%d\n", a[i], count);

        i = i + count;
    }

    return 0;
}