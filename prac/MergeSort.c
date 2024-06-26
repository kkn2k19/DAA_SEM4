// 20.03.2024

#include <stdio.h>

int main()
{
    int n, i, arr[20], low, high;
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
    low = 0;
    high = n - 1;
    mergeSort(arr, low, high); 
    printf("\nArray After Sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int arr2[high]; 
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k] = arr[i];
            i++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= high)
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = low; k <= high; k++)
    {
        arr[k] = arr2[k];
    }
}

// OUTPUT ---
// Enter size of the Array : 10
// Enter the elements of Array : 1 2 3 6 5 4 0 9 8 7 
// Array Before Sorting : 1 2 3 6 5 4 0 9 8 7 
// Array After Sorting : 0 1 2 3 4 5 6 7 8 9