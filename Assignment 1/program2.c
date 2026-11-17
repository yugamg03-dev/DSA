#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

for(int i = 0;i < n-1;i++){
    for(int j = i+1;j<n;j++){
        if((arr[i]+arr[j])%2 == 0){
            printf("{%d,%d}",arr[i],arr[j]);
        }
    }
}
return 0;
}