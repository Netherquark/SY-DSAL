#include <stdio.h>

// Bubble Sort function
void bubbleSort(int my_array[], int array_len) {
    int j, k; 
    for (j = 0; j < array_len - 1; j++) {
        for (k = 0; k < array_len - j - 1; k++) {
            if (my_array[k] > my_array[k + 1]) {
                int temp = my_array[k];
                my_array[k] = my_array[k + 1];
                my_array[k + 1] = temp;
            }
        }
    }
    printf("\nArray sorted using Bubble Sort!\n");
}

// Selection Sort function
void selectionSort(int my_array[], int array_len) {
    int i, j, min_idx;
    for (i = 0; i < array_len - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < array_len; j++) {
            if (my_array[j] < my_array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = my_array[min_idx];
        my_array[min_idx] = my_array[i];
        my_array[i] = temp;
    }
    printf("\nArray sorted using Selection Sort!\n");
}

// Insertion Sort function
void insertionSort(int my_array[], int array_len) {
    int i, key, j;
    for (i = 1; i < array_len; i++) {
        key = my_array[i];
        j = i - 1;
        while (j >= 0 && my_array[j] > key) {
            my_array[j + 1] = my_array[j];
            j = j - 1;
        }
        my_array[j + 1] = key;
    }
    printf("\nArray sorted using Insertion Sort!\n");
}

int main() {
    int array_len, choice;

    printf("Please enter the number of elements in the array:\n");
    scanf("%d", &array_len);

    int my_array[array_len];
    
    for (int i = 0; i < array_len; i++) {
        printf("\nElement %i: ", i);
        scanf("%d", &my_array[i]);
    }

    printf("\nChoose sorting technique:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    scanf("%d", &choice);
    printf("\n----------------------------------------------------------------------------------------------------------\n");

    switch (choice) {
        case 1:
            bubbleSort(my_array, array_len);
            break;
        case 2:
            selectionSort(my_array, array_len);
            break;
        case 3:
            insertionSort(my_array, array_len);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Display sorted array
    for (int i = 0; i < array_len; i++) {
        printf("\nElement %d = %d", i, my_array[i]);
    }
    
    return 0;
}
