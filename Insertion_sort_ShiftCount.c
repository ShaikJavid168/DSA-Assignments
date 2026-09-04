#include <stdio.h>

int main()
{
    int a[100], n;
    int shifts = 0;
    int comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                shifts++;
                j--;
            }
            else
            {
                break;
            }
        }

        a[j + 1] = key;
    }

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nNumber of shifts = %d\n", shifts);
    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}