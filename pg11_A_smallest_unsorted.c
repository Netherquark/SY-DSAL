#include<stdio.h>

int findMissingInteger (int my_array[], int array_len)
{
    int j, k; 
    for (j = 0; j <= array_len - 1; j++)
    {
        for (k = 0; k <= array_len - j - 1; k++)
        {
            if (my_array[k] > my_array[k + 1])
            {
                int temp = my_array[k];
                my_array[k] = my_array[k+1];
                my_array[k+1] = temp;
            }

                
        }
    }

    printf("\nSorted!\n");

    int h=0;

    for(int h = 0; (h < array_len && my_array[h] <= 0); h++)
    {
        printf("\nh: %d less than %d array length and element %d = %d less than 1\n", h, array_len, h, my_array[h]);        
    }

    int smallest_missing = 1;

    for (int n = h; n < array_len; n++) {
        if (my_array[n] == smallest_missing) {
            smallest_missing++;
        } else if (my_array[n] > smallest_missing) {
            break;
        }
    }
    return smallest_missing;
}

int main()
{
    int array_len;
    printf("Please enter the number of elements in the array:\n");
    scanf("%d", &array_len);
    int my_array[array_len];
    for (int i = 0; i < array_len; i++)
    {
        printf("\nElement %i:", i);
        scanf("%d", &my_array[i]);
    }
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    int missing_integer = findMissingInteger(my_array, array_len);
    printf("\nMissing integer is %d\n", missing_integer);
}