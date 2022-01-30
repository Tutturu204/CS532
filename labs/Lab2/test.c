# include <stdio.h>


void pr (int c, int *ptr) {
    printf("%d\n",c);
    printf("%p\n",ptr);
}

int main (void){
    int c = 23;
    int *ptr;

   
    pr(c,ptr);
    printf("\n%p\n", &ptr);

    return 1;
}
