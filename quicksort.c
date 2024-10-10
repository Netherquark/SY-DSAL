#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int array_len;
    printf("Please enter the number of elements in the array:\n");
    scanf("%d", &array_len);

    int my_array[array_len];
    for (int i = 0; i < array_len; i++) {
        printf("Element %i: ", i);
        scanf("%d", &my_array[i]);
    }

    printf("\nSorting the array using QuickSort...\n");
    quickSort(my_array, 0, array_len - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < array_len; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}
