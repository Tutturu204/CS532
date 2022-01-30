#include <stdio.h>
#include <stdlib.h>


void print_the_array(int arr[], int size){

    for (int i=0; i < size; i++) {
        printf("%d  ", arr[i]);
        
    }
    printf("\n");
}

void ins_sort (int array[], int size){
    

    for (int i=0; i<=size-1; i++) {
        for (int j=i; j<=size-1; j++){
            if (array[i]>array[j]){
                
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
}

int fill_the_array(int array_of_elemetns[], int size){
    int temp;
    for (int i = 0; i < size; i++) {
        printf("Enter a number: \n");
        scanf("%d", &temp);
        array_of_elemetns[i] = temp;
    }
    return 1;
}

int main(){
    
    int size;

    printf("Enter a number of array elements: \n");
    scanf("%d", &size);
    printf("the size is : %d\n", size);

    int array_elements [size];
    
    fill_the_array(array_elements, size);

    printf("array before sorting: \n");
    print_the_array(array_elements, size);

    ins_sort(array_elements, size);

    printf("array after sorting: \n");
    print_the_array(array_elements, size);

}
