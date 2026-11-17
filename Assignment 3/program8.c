#include <stdio.h>

int main()
{
    int a[100];
    int n, i, j;
    int count, maxCount = 0;
    int found;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++)
    {
        count = 1;

        for(j = 0; j < n; j++)
        {
            found = 0;

            if(a[j] == a[i] + count)
            {
                found = 1;
            }

            if(found == 1)
            {
                count++;
                j = -1;
            }
        }

        if(count > maxCount)
        {
            maxCount = count;
        }
    }

    printf("Length of longest consecutive sequence = %d", maxCount);

    return 0;
}