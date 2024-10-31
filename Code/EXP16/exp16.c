// Loop Unrolling

#include <stdio.h>

void loopunrolledsum(int arr[], int n)
{
    int sum = 0;
    printf("| Index | Value | Current Sum |\n");
    for (int i = 0; i < n - 1; i += 2)
    {
        sum += arr[i];
        printf("| %5d | %5d | %11d |\n", i, arr[i], sum);

        sum += arr[i + 1];
        printf("| %5d | %5d | %11d |\n", i + 1, arr[i + 1], sum);
    }

    if (n % 2 != 0)
    {
        sum += arr[n - 1];
        printf("| %5d | %5d | %11d |\n", n - 1, arr[n - 1], sum);
    }
    printf("\nFinal sum: %d\n", sum);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    loopunrolledsum(array, size);
    return 0;
}
