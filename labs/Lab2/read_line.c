#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000;

/*
int getline(char s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim> 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c; 
        
        if(c == '\n'){
            s[i++] = c;
        }
       
        s[i] ='\0';
        return i;
    }
}
*/

int main(int argc, char** argv) {
    
    char strings[3][256] = {"he", "th", "o" };


    //open the file
    FILE *the_file = fopen("file.txt", "r");
    
    if (the_file == NULL){
        printf("Problem with file\n");
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;

    while(getline(&line, &len, the_file)) {
        for (int i = 0; i < 3; i++){
            for(int j = 0; i < len; i++){
                printf("/s\n", line[j]);
            }
            printf("\n");
        }

        fputs(line, stdout);
    }
    printf("\n");
    fclose(the_file);
}