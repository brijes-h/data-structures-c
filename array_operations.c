/* Array Operations:
	1. Insertion
	2. Deletion
	3. Linear Search
	4. Bubble Sort
	5. Merge Arrays
*/
#include <stdio.h>

void insertion(int a[], int size){
    int pos, element, i, n=size;
    printf("Enter the position and element: ");
    scanf("%d%d", &pos, &element);
    pos = pos -1;
    if(pos<=n && pos>0){
        for(i=n; i>pos; i--){
            a[i] = a[i-1];
        }
        a[pos] = element;
        printf("Updated Array: ");
        for(i=0; i<n+1; i++){
            printf("%d ", a[i]);
        }
    }
    else{
        printf("This position is invalid");
    }
}
/****************************************************/

void deletion(int a[], int size){
    int pos, element, i, n=size;
    int index = -1;
    printf("\nEnter the element to delete: ");
    scanf("%d", &element);
    for(i=0; i<n; i++){
        if(a[i]==element){
            index = i;
            break;
        }
    }
    if(index != -1){
        for(i=index; i<n-1; i++){
            a[i] = a[i+1];
        }
        printf("Updated array: ");
        for(i=0; i<n-1; i++){
            printf("%d ", a[i]);
        }
    }
    else{
        printf("\nThe element is not found in the array.");
    }
}

/*****************************************************/
// using binary search
int searching(int a[], int size){
    int i, n=size, key;
    int low = 0, high = n-1, mid;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    while(low <= high){
        mid = (low+(high-low))/2;
        if(a[mid]==key)
        return mid;
        else if(a[mid]<key)
        high = mid - 1;
        else
        low = mid + 1;
    }
    return -1;
}

/******************************************************/
// using bubble sort
void sorting(int a[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted Array: ");
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
}

/*******************************************************/
void mergeArrays(int a[], int size){
    int newsize, z;
    printf("\nInput the new array to be merged: ");
    printf("\nEnter the number of elements: "); scanf("%d", &newsize);
    z = size + newsize;
    int c[z];
    int b[newsize];
    for(int i=0; i<newsize; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &b[i]);
    }    
    int x=0, y=0;
    for(int j=0; j<z; j++){
        if(a[x]<=b[y]){
            c[j] = a[x];
            x++;
        }
        else{
            c[j] = b[y];
            y++;
        }
    }
    printf("\nNew Array: ");
    for(int i=0; i<z; i++){
        printf("%d ", c[i]);
    }
}
/*******************************************************/
void reverse(){


}

void main() {
    int option, size, ind;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int a[size+1];
    for(int i=0; i<size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("1. Insertion\n2. Deletion\n3. Searching\n4. Sorting\n5. Merging");
    printf("\nSelect an option: ");
    scanf("%d", &option);
    switch(option){
        case 1:
        insertion(a, size);
        break;
        case 2:
        deletion(a, size);
        break;
        case 3:
        ind = searching(a, size);
        if(ind!=-1)
        printf("The element %d is found in present in the array at the position %d", a[ind], ind);
        else
        printf("The element is not found in the array");
        break;
        case 4:
        sorting(a, size);
        break;
        case 5:
        mergeArrays(a, size);
        break; 
    }
}

