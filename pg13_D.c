#include <stdio.h>
#include <string.h>

// Binary search function to find the target word
int binarySearch(char *my_array[], int array_len, char *target) {
    int low = 0, high = array_len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int res = strcmp(my_array[mid], target);

        if (res == 0) {
            return mid; // target found
        } else if (res < 0) {
            low = mid + 1; // search right half
        } else {
            high = mid - 1; // search left half
        }
    }
    
    return -1; // target not found
}

int main() {
    int array_len;
    
    printf("Please enter the number of words in the array:\n");
    scanf("%d", &array_len);
    
    char *my_array[array_len];
    char word[100]; // buffer to store input words

    // Reading array of words
    for (int i = 0; i < array_len; i++) {
        printf("\nWord %d: ", i);
        scanf("%s", word);
        my_array[i] = strdup(word); // copy word into array
    }
    
    char target[100];
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("Please enter the target word:\n");
    scanf("%s", target);
    
    // Perform binary search
    int index = binarySearch(my_array, array_len, target);

    if (index != -1) {
        printf("\nThe target word '%s' is at index %d.\n", target, index);
    } else {
        printf("\nThe target word '%s' was not found.\n", target);
    }

    return 0;
}
