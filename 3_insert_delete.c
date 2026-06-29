// 3️⃣ INSERTION OPERATIONS

// Insert at beginning
// Insert at end
// Insert at specific position
// Insert in sorted array
// Multiple insertions

// 🔹 4️⃣ DELETION OPERATIONS

// Delete from beginning
// Delete from end
// Delete from specific position
// Delete by value
// Delete duplicates

#include<stdio.h>
#define MAX 100

void insert_at_beg(int arr[], int *size, int val);
void insert_at_end(int arr[], int *size, int val);
void insert_at_pos(int arr[], int *size, int pos, int val);
void delete_from_beg(int arr[], int *size);
void delete_from_end(int arr[], int *size);
void delete_from_pos(int arr[], int *size, int pos);
void delete_by_val(int arr[], int *size, int val);
void delete_duplicate(int arr[], int *size);
void display(int arr[], int *size);

void insert_at_beg(int arr[], int *size, int val){
    if(*size == MAX){
        printf("\nArray is full");
        return;
    }
    for(int i = *size-1; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = val;
    (*size)++;
    printf("\n%d element is inserted at beginning", val);
    printf("\n");
}

void insert_at_end(int arr[], int *size, int val){
    if(*size == MAX){
        printf("\nArray is full");
        return;
    }
    arr[*size] = val;
    (*size)++;
    printf("\n%d element is inserted at end", val);
    printf("\n");

}

void insert_at_pos(int arr[], int *size, int pos, int val){
    if(*size == MAX){
        printf("\nArray is full");
        return;
    }
    if(pos < 1 || pos > *size + 1){
        printf("\nInvalid position");
        return;
    }
    for(int i = *size-1; i >= pos-1 ; i--){
        arr[i+1] = arr[i];
    }
    arr[pos-1] = val;
    (*size)++;
    printf("\n%d element is inserted at %d position", val, pos);
    printf("\n");

}

void delete_from_beg(int arr[], int *size){
    if(*size == 0 ){
        printf("\nArray is empty");
        return;
    }
    
    printf("\n%d element from Beginning of array is deleted", arr[0]);

    for(int i = 0; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("\n");

}

void delete_from_end(int arr[], int *size){
    if(*size == 0 ){
        printf("\nArray is empty");
        return;
    }

    printf("\n%d element from end of array is deleted", arr[*size-1]);
    (*size)--;
    printf("\n");

}

void delete_from_pos(int arr[], int *size, int pos){
    if(*size == 0 ){
        printf("\nArray is empty");
        return;
    }

    if(pos < 1 || pos > *size){
        printf("\nInvalid Position.....");
        return;
    }

    printf("\n%d element from %d position of array is deleted", arr[pos-1], pos);
    
    for(int i = pos-1; i < *size - 1; i++){
        arr[i] = arr[i+1];
    }
    (*size)--;
    printf("\n");

}

void delete_by_val(int arr[], int *size, int val){
    int idx = -1;
    if(*size == 0 ){
        printf("\nArray is empty");
        return;
    }

    for(int i = 0; i < *size; i++){
        if(arr[i] == val){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        printf("\n%d element is not present in array", val); 
        return;
    }
    printf("\n%d element from array is deleted", val);
  
    for(int i = idx; i < *size-1; i++){
        arr[i] = arr[i+1];
    }
    
    (*size)--;
    printf("\n");

}

void delete_duplicate(int arr[], int *size){

    if(*size == 0){
        printf("\nArray is empty");
        return;
    }

    for(int i = 0; i < *size; i++){
        for(int j = i + 1; j < *size; j++){
            if(arr[i] == arr[j]){

                for(int k = j; k < *size - 1; k++){
                    arr[k] = arr[k + 1];
                }

                (*size)--;   
                j--;         
            }
        }
    }

    printf("\nDuplicate elements removed successfully");
    printf("\n");

}

void display(int arr[], int *size){
    
    if(*size == 0){
        printf("\nArray is empty");
        return;
    }

    printf("\nArray Elements : ");
    for(int i = 0; i < *size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main(){
    int arr[MAX], size, ch, pos, val;

    printf("Enter Size : ");
    scanf("%d", &size);

    printf("Enter %d Array Elements : ", size);
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    do{
        printf("\n\n---- MENU ----");
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert at specific position");
        printf("\n4.Delete from beginning");
        printf("\n5.Delete from end");
        printf("\n6.Delete from specific position");
        printf("\n7.Delete by value");
        printf("\n8.Delete duplicate");
        printf("\n9.Display");
        printf("\n10.Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("\nEnter Value : ");
                scanf("%d", &val);
                insert_at_beg(arr, &size, val);
                break;

            case 2:
                printf("\nEnter Value : ");
                scanf("%d", &val);
                insert_at_end(arr, &size, val);
                break;

            case 3:
                printf("\nEnter position : ");
                scanf("%d", &pos);
                printf("\nEnter Value : ");
                scanf("%d", &val);
                insert_at_pos(arr, &size, pos, val);
                break;

            case 4:
                delete_from_beg(arr, &size);
                break;

            case 5:
                delete_from_end(arr, &size);
                break;

            case 6:
                printf("\nEnter position : ");
                scanf("%d", &pos);
                delete_from_pos(arr, &size, pos);
                break;

            case 7:
                printf("Enter value : ");
                scanf("%d", &val);
                delete_by_val(arr, &size, val);
                break;

            case 8:
                delete_duplicate(arr, &size);
                break;

            case 9:
                display(arr, &size);
                break;

            case 10:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    }while(ch != 10);

    return 0;
}
