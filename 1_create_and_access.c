// Creation & Access

// Declare array
// Initialize array
// Read elements
// Print elements
// Access element by index
// Traverse array (forward)
// Traverse array (reverse)

#include<stdio.h>

void initilizeaArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void readAndPrint(int arr[], int size){
    printf("\nEnter elements of array 2 : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\n5 Elements of array 2 : ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void for_traverse(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void back_traverse(int arr[], int size){
    for(int i = size-1 ; i >= 0; i--){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr1[] = {12, 23, 45, 78, 80};
    int size = 5;
    int arr2[5];

    printf("Elements of array 1 : \n");
    initilizeaArray(arr1, size);

    printf("\nRead and print elements of array 2 : ");
    readAndPrint(arr2, size);

    printf("\nelement at position 2 : ", arr1[3]);

    printf("\nforword traverse : ");
    for_traverse(arr1, size);

    printf("\nBackword traverse : ");
    back_traverse(arr1, size);

}