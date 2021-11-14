#include <stdio.h>

int main()
{
    int i, j, temp, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // bubble sort    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            
            if (arr[j+1] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 


    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}