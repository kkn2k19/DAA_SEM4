#include<stdio.h>

int main()
{
    int arr[20][20], i, j, rows, cols;
    printf("Enter rows and columns of the Matrix Required : ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of the Matrix : ");
    for (i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Matrix Entered : \n");
    for (i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of the given Matrix : \n");
    for(j=0; j<cols; j++) {
        for (i=0; i<rows; i++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
