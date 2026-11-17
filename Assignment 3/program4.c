#include <stdio.h>

int main()
{
    int a[100], n;
    int i, j;
    int leftSum, rightSum;
    int found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Equilibrium indices are ");

    for(i = 0; i < n; i++)
    {
        leftSum = 0;
        rightSum = 0;

        
        for(j = 0; j < i; j++)
        {
            leftSum = leftSum + a[j];
        }

        for(j = i + 1; j < n; j++)
        {
            rightSum = rightSum + a[j];
        }

        if(leftSum == rightSum)
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("not found");
    }

    return 0;
}