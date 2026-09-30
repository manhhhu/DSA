#include <stdio.h>

void merge(int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1, j = high, temp;

    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (j >= low + 1 && a[j] > pivot)
            j--;

        if (i > j)
            break;

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int mergeArray[] = {324, 125, 456, 218, 102, 389, 275, 147};
    int quickArray[] = {324, 125, 456, 218, 102, 389, 275, 147};
    int n = 8;

    mergeSort(mergeArray, 0, n - 1);
    quickSort(quickArray, 0, n - 1);

    printf("MergeSort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", mergeArray[i]);

    printf("\n\nQuickSort result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", quickArray[i]);

    printf("\n");
    return 0;
}
