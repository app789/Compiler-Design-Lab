#include <stdio.h>
#include <math.h>

int rows = 0;
int i,j,h,space;
int num = 1;
int d = 0;

int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return (n * factorial(n-1));
}
//Returns nCr
int combination(int n,int r)
{
    return (factorial(n) / (factorial(n-r) * factorial(r)));
}

int main()
{
    printf("\nenter number of rows:");
    scanf("%d",&rows);

    for(i = 0; i < rows; i++){

        for(space = 1; space < rows - i; space++){
            printf(" ");
        }
        for(j = 0; j <= i; j++){
            num = combination(i,j);
            printf(" %d",num);
        }
       /* while(num > 0){
            d = num % 10;
            printf("%d ",d);
            num = num / 10;
        }*/
        printf("\n");
    }

    
    return 0;
}