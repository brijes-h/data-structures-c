#include <stdio.h>

int main()
{
    int i, j, current;
    int n;

    // array input loop
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // insertion sort
    for (i = 1; i < n; i++) {  // indexing from 1, i.e. the second element
        current = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    // display loop
    printf("The sorted array is: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}