#include<stdio.h>
#include<stdlib.h>

int totalDistance = 0;
int remainingDistance = 0;
int distanceToDrive = 0;
int choose();
int main()
{
	int i = 0;
    int j = 0;
	int jelly[10];
	int jack[10];
	printf("Enter the total distance to school :");
	scanf("%d",&totalDistance);
	remainingDistance = totalDistance;
    int toggle = 0;
	while(remainingDistance > 0){
		
		distanceToDrive =  choose();
        if(toggle % 2 == 0){
            jelly[i] = distanceToDrive;
            i++;
            toggle++;
        }
        else{
          jack[j] = distanceToDrive;
            j++;
            toggle++;  
        }
		remainingDistance = remainingDistance - distanceToDrive;
		
	}
  if(toggle % 2 == 0){
      printf("\nJelly have won the race\n");}
  else{
       printf("\nJack have won the race\n");}
	
	return 0;
}
int choose()
{
	//ANTICIPATION
    int i;
    int chosenDistance;

    if(remainingDistance%2 == 0 && (remainingDistance - 1 !=1 || remainingDistance - 1 != 2 ||remainingDistance - 1 != 4)&& remainingDistance/2 >=1 )
        chosenDistance = 1;
    
    else if(remainingDistance%2 == 1 && (remainingDistance -2!= 1 ||remainingDistance -2!= 2 ||remainingDistance -2!= 4)&& remainingDistance/2 >=2)
            chosenDistance = 2;
    else if(remainingDistance%2 == 1 && (remainingDistance -4!= 1 ||remainingDistance -4!= 2 ||remainingDistance -4!= 4)&& remainingDistance/2 >=4)
            chosenDistance = 4;
    else
            chosenDistance = 1;
    return chosenDistance;        
    /*
	int chosenDistance = 1;
	if(chosenDistance <= remainingDistance/2 ){
		//if even then choose odd if possible
		if(remainingDistance % 2 == 0){
			chosenDistance = 1;
		}
		//if odd then choose even if possible
		else{
			if(remainingDistance - 2 == 1 || remainingDistance - 2 == 2 || remainingDistance - 2 == 4 ){
				chosenDistance = 4;
			}
			if(remainingDistance - 4 == 1 || remainingDistance - 4 == 2 || remainingDistance - 4 == 4 ){
				chosenDistance = 2;
			}
		}
	}*/
}
	
