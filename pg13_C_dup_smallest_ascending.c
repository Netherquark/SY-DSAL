#include<stdio.h>

int bubbleSort (int my_array[], int array_len)
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
    bubbleSort(my_array, array_len);

    for (int i = 0; i < array_len; i++)
    {
        printf("\nElement %d = %d", i, my_array[i]);
    }
}