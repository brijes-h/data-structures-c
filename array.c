// Construct a program to find the 3rd largest element in the given array and divide the array
// into sub-arrays such that One sub array is with elements lesser than 3rd largest element; The other 
// sub array with elements greater than 3rd largest element.

#include <stdio.h>

void thirdLargest(int a[],int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("The third largest element is: %d\n", a[size-3]);
    int b[2], c[size-2];
    for(int j=0; j<size-2; j++){
        c[j] = a[j];
    }
    printf("First subarray: \n");
    for (int j = 0; j <=size-3; j++)
    {
        printf("%d ", c[j]);
    }
    printf("\nSecond subarray: \n");
    int temp1 = 0;
    for (int i=size-2; i<size; i++)
    {   
        // printf("%d %d\n",a[i], temp1);
        b[temp1] = a[i];
        temp1++;
    }
    for (int i = 0; i<2; i++)
    {
        printf("%d ", b[i]);
    }   

}

void subarray(){

}
int main(){
    int n, j;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (j=0; j<n; j++)
    {
        printf("Enter element %d: ", j+1);
        scanf("%d", &arr[j]);
    }
    thirdLargest(arr, n);
    return 0;
}