#include <stdio.h>

int size = 0;
int i,j;
int toggle = 0;
int col_limit = 0;

int main()
{
    printf("\nenter size:");
    scanf("%d",&size);

    col_limit = size + (size - 1);
    //TOP HALF
    for(i = 0; i < size-1; i++){
        for( j = 0; j < i + 1; j++){
            if(toggle % 2 != 0){
                if(j % 2 != 0)
                    printf("*"); 
                else  printf(" ");
            }
            else{
                if(j % 2 == 0)
                    printf("*");
                else  printf(" ");
            }
           
        }
        
        for(j = i + 1; j <= col_limit - (i + 1 * 2); j++){
           printf(" ");
        }

        //right side - Print * alternatively
        for( j = 0; j < i + 1; j++){
           if(j % 2 == 0)
                    printf("*");
                else  printf(" ");
        }

         toggle++;
        printf("\n");  //new line
    } 
    //MIDDLE ROW
    for(j = 0; j <  col_limit; j++){
        if(j % 2 == 0) printf("*");
        else printf(" ");
    }
    printf("\n");
    //BOTTOM HALF
    toggle = 0;
    int d = 0;
    
    for(i = size ; i > 1; i--){
        //left side
        for( j = 0; j < i - 1; j++){
            if(toggle % 2 == 0){
                if(j % 2 != 0) printf("*");
                else printf(" ");
            }
            else{
                if(j % 2 == 0) printf("*");
                else printf(" ");
            }
           
        }
        toggle++;
        for(int k = j; k < i + (d*2) ; k++){
           printf(" ");
           
        }
        d++;
        //right side - Print * alternatively
        for( j = 0; j < i - 1; j++){
           if(j % 2 == 0)
                    printf("*");
            else  printf(" ");
           
        }
        
        printf("\n"); //new line
    }
   return 0;
}