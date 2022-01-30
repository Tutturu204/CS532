#include <stdio.h>

int main(){
    
    int given_number;

    printf("Enter a number: ");
    scanf("%d", &given_number);
    
    if (given_number <= 0) {
        printf("You should enter a positive number\n");
        return 0;
    }

    if (given_number == 1) {
        printf("1 is not a Prime number");
        return 0;
    }

    for (int start=2; start < given_number; start++){
        
        if (given_number % start == 0){
            printf("Your number is not Prime\n");
            return 0;
        }
    }
    printf("Your nuber is Prime\n");
    return 0;
    
}