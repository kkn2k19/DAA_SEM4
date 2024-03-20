#include<stdio.h>

int main()
{
    int n, i, arr[20], key;
    printf("Enter size of the Array : ");
    scanf("%d", &n);
    printf("Enter the elements of Sorted Array : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the value to search : ");
    scanf("%d", &key);
    int index;
    index = binarySearch(arr, n, key); 
    if (index == -1) {
        printf("Not Found\n");
    } else {
        printf("Found at index : %d\n", index);
    }
    return 0;
}

int binarySearch(int arr[], int n, int key) 
{
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
            start = mid + 1;
        }
    }
    return -1;
}

/*
OUTPUT ---

Enter size of the Array : 5
Enter the elements of Sorted Array : 1 2 3 4 5
Array : 1 2 3 4 5 
Enter the value to search : 3
Found at index : 2
*/