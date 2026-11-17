#include<stdio.h>
int main(){
    int a[100], n;
    int i;
    int minprice, profit, maxprofit;

    printf("Enter the number of days: ");
    scanf("%d", &n);

    printf("Enter the stock prices:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    minprice = a[0];
    maxprofit = 0;

    for(i = 1; i < n; i++)
    {
        profit = a[i] - minprice;

        if(profit > maxprofit)
        {
            maxprofit = profit;
        }

        if(a[i] < minprice)
        {
            minprice = a[i];
        }
    }

    printf("Maximum Profit = %d", maxprofit);

    return 0;
}