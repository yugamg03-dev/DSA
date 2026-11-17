#include<stdio.h>
int main(){
int n, i, p = 0, neg = 0, k = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], pos[n], negative[n], result[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);}
for(i = 0; i < n; i++){
    if(arr[i] >= 0){
        pos[p] = arr[i];
        p++;}
    else
{        negative[neg] = arr[i];
        neg++;}
}
i = 0;
int j = 0;
while(k<n){
    result[k] = pos[i];
    k++,i++;
    result[k] = negative[j];
    k++ ,j++;
}
for(k = 0;k<n;k++){
    printf("%d ",result[k]);
}



    return 0;
}4