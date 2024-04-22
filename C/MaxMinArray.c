#include<stdio.h>

int main()
{
    int arr[20], n, i, min, max;
    printf("Enter size of Array : ");
    scanf("%d", &n);
    printf("Enter elements of the Array : ");
    for(i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array : ");
    for(i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    min = minValue(arr, n);
    printf("\nMin Value : %d\n", min);
    max = maxValue(arr, n);
    printf("Max Value : %d\n", max);
}

int minValue(int arr[], int n) {
    int min = arr[0];
    int i;
    for (i =1; i<n; i++) {
        if (min>arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int maxValue(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i =1; i<n; i++) {
        if (max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}
