#include <stdio.h>

int main()
{
    int a[100];
    int n, k, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if(k > n)
    {
        printf("Nth largest element does not exist.");
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                if(a[i] < a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }

            if(i == k - 1)
            {
                break;
            }
        }

        printf("%dth largest element = %d", k, a[k - 1]);
    }

    return 0;
}