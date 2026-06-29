// Basic Computations

// Find sum of elements
// Find product of elements
// Find average
// Find minimum element
// Find maximum element
// Count elements
// Count even numbers
// Count odd numbers
// Count positive / negative

#include<stdio.h>

int sumOfEle(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int productOfEle(int arr[], int size){
    int product = 1;
    for(int i = 0; i < size; i++)
        product *= arr[i];
    return product;
}

float avgOfEle(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return (float)sum / size;
}

void minOfEle(int arr[], int size){
    int min = arr[0], idx = 0;
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            idx = i;
        }
    }
    printf("\nMinimum element: %d at index %d", min, idx);
}

void maxOfEle(int arr[], int size){
    int max = arr[0], idx = 0;
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
            idx = i;
        }
    }
    printf("\nMaximum element: %d at index %d", max, idx);
}

void evenOddCount(int arr[], int size, int *even, int *odd){
    *even = *odd = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
}

void posNegCount(int arr[], int size, int *pos, int *neg){
    *pos = *neg = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > 0)
            (*pos)++;
        else if(arr[i] < 0)
            (*neg)++;
    }
}

int main(){
    int size, arr[100];

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter array elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("\nSum = %d", sumOfEle(arr, size));
    printf("\nProduct = %d", productOfEle(arr, size));
    printf("\nAverage = %.2f", avgOfEle(arr, size));

    minOfEle(arr, size);
    maxOfEle(arr, size);

    printf("\nCount of elements = %d", size);

    int even, odd;
    evenOddCount(arr, size, &even, &odd);
    printf("\nEven count = %d", even);
    printf("\nOdd count = %d", odd);

    int pos, neg;
    posNegCount(arr, size, &pos, &neg);
    printf("\nPositive count = %d", pos);
    printf("\nNegative count = %d", neg);

    return 0;
}
