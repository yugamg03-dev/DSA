#include <stdio.h>

int main()
{
    int a[100], n;
    int i, j,k;
    int maxXor = 0;
    int x, y;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            k = (a[i] ^ a[j]);
            if( k > maxXor)
            {
                maxXor = k;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("Pair with maximum XOR: %d and %d\n", x, y);
    printf("Maximum XOR value = %d", maxXor);

    return 0;
}