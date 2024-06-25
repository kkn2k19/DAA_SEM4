// 04.04.2024

#include <stdio.h>

void quickSort(int arr[], int lb, int ub);
int partition(int arr[], int lb, int ub);
void swap(int *a, int *b);

int main()
{
    int n, i, arr[20], lb, ub;
    printf("Enter size of the Array : ");
    scanf("%d", &n);
    printf("Enter the elements of Array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array Before Sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    lb = 0;
    ub = n - 1;
    quickSort(arr, lb, ub);
    printf("\nArray After Sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void quickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc;
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc + 1, ub);
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot) 
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

// OUTPUT ---
// Enter size of the Array : 9
// Enter the elements of Array : 7 6 10 5 9 2 1 15 7
// Array Before Sorting : 7 6 10 5 9 2 1 15 7 
// Array After Sorting : 1 2 5 6 7 7 9 10 15
