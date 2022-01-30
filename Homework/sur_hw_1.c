#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int NUM_OF_INPUT_STR = 1;


//prints {"<command line arg>" : <num_of_occurences>}
void print_array(int num[], char **labels, int size){
    //printf("size is %d\n", size);
    for(int i=0; i< size; i++){
        //printf("label %d is %s\n ", i, *(labels+1+i));
        printf("%c%s%c pattern: %d \n", '"', *(labels+1+i), '"', num[i]);
    }
    
}

//This function compares 2 strings: test string that was provided as command line argument
//and the line in a buffer, that was readed from a file
//test -> char array with test string
//buf -> char array with a buffer line
//index -> index of current character from buffer string  
//size -> size of a buffer line (num of characters in a buffer)

//return 1 if strings are same; else 0
int compare_strings(char test [] , char buf [], int index, int size){
    int answ = 1;

    if (test[0] == '\0'){
        return 0;
    }

    for (int j = 0; j < strlen(test); j++){
        
        if ((index < size) && (test[j] != buf[index])) {
            answ = 0;
            return answ;
        }
        index++;
    }
    return answ;
}

//fill the array of current size with zeroes {0}
void fill_array (int array [], int size) {
    for (int i = 0; i < size; i ++){
        array[i] = 0;
    }
}

int main(int argc, char** argv) {
    
    NUM_OF_INPUT_STR = argc - 1;
    int num_of_occurrences[NUM_OF_INPUT_STR];
    char **pattern;

    fill_array(num_of_occurrences, NUM_OF_INPUT_STR);

    //asssign comand line arguments to pattern array
    pattern = calloc(NUM_OF_INPUT_STR, sizeof(char *)); 
    //printf("this is num_of_elemetns: %d\n",argc );
    for (int i = 1; i < argc; i++ ){
        //printf("strgin %s is an cmd argiment\n", argv[i]);
        *(pattern + i-1) = argv[i];  
        //printf("%d element %s  in the array \n", i-1, *(pattern + i-1));
    }
   	
    //read file "file.txt" in a current directory
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    filePointer = fopen("file.txt", "r");

    // read file line by line
    while(fgets(buffer, bufferLength, filePointer)) {
        
        size_t size = strlen(buffer);
        
        for (int i = 0; i < size; i++) {
            
            //prints ecah char in the current line
            //printf("%c\n",buffer[i]);

            //while meets \n -> line is ended
            if (buffer[i] == '\n'){
                //printf("BREAK founded\n");
                break;
            }

            //for number of strings in commend line arg compare cmd line strings to the buf string
            for (int n = 0; n < NUM_OF_INPUT_STR; n++){
                if (compare_strings(*(pattern + n), buffer, i, size) == 1) {
                    //printf("PATTERN[%s] FOUNDED\n", *(pattern+ n));

                    num_of_occurrences[n]++;

                }   
            }
        }
    }
    print_array(num_of_occurrences, argv, NUM_OF_INPUT_STR);
    fclose(filePointer);
    free(pattern);
}
