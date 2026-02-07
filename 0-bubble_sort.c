#include <stdio.h>
#include <stdlib.h>

/**
 * bubble_sort - Massivi Bubble sort alqoritmi ilə sıralayır.
 * @array: Sıralanacaq massiv (pointer)
 * @size: Massivin ölçüsü
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Elementlərin yerini dəyişirik */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Hər swap-dan sonra massivi çap edirik */
                for (size_t k = 0; k < size; k++)
                {
                    printf("%d%s", array[k], (k < size - 1) ? ", " : "");
                }
                printf("\n"); 
                swapped = 1;
            }
        }
        /* Əgər heç bir swap baş vermədisə, massiv artıq sıralanıb */
        if (swapped == 0)
            break;
    }
}
