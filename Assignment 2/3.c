#include <stdio.h>
int main(){
    int a[10][10];
    int m, n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nRow Column Value\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(a[i][j] != 0){
                printf("%d %d %d\n", i+1, j+1, a[i][j]);
            }
        }
    }

    return 0;
}