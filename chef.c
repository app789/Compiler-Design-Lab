/*
Chef who have pairs of dolls.
Finds if any doll type is not in pairs.
*/

#include <stdio.h>

int T = 1;      //no of test cases
int N = 0;      //no of types  MAX 100000
int dolls[100000];
int i = 0;
int j = 0;
int count[100000];

int main()
{
    printf("\nenter the no of tests:");
    scanf("%d",&T);
    
    while(T){

        printf("\nenter no of types of dolls:");
        scanf("%d",&N);

        printf("\nenter values for array:");
        for(i = 0; i < N; i++){
            scanf("%d",&dolls[i]);
        }
        
        for(i = 0; i < N; i++){
            count[dolls[i]]++;
            j++;
        }

        for(i = 0; i < 100; i++){
            if(count[i] % 2 != 0){
                printf("\ntype %d is not even\n",i);
               // break;
            }
        }

        --T;
    }
    
    return 0;
}