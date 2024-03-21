// 21.03.2024

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, arr[10], n, index, key;
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    printf("Enter the elements of the Array : ");
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array Before Sorting : ");
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nArray After Sorting : ");
    sortArray(arr, n);
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the value to search : ");
    scanf("%d", &key);
    index = binarySearch(arr, n, key);
    if (index == -1) {
        printf("Not Found\n");
    } else {
        printf("Found at index : %d\n", index);
    }
}

void sortArray(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i<n; i++) {
        for (j=i+1; j<n; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    int mid;
    while (start <= end) {
        mid = start + (end-start)/2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            end = mid -1;
        } else {
            start = mid +1;
        }
    }
    return -1;
}

/*
OUTPUT --

Enter the size of Array : 5
Enter the elements of the Array : 5 3 4 2 6
Array Before Sorting : 5 3 4 2 6
Array After Sorting : 2 3 4 5 6
Enter the value to search : 5
Found at index : 3
*/
