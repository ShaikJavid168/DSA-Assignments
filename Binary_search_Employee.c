#include <stdio.h>

int main()
{
    int a[100], n, key;
    int low, high, mid;
    int comparisons = 0;
    int found = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    printf("Enter employee IDs in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if (a[mid] == key)
        {
            found = 1;
            printf("\nEmployee ID found at position %d\n", mid + 1);
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == 1)
    {
        printf("Successful search\n");
    }
    else
    {
        printf("Employee ID not found\n");
        printf("Unsuccessful search\n");
    }

    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}