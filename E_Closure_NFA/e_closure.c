#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

FILE *file,*temp;

int  numberOfStates = 0;
int  flag = 0;
int  states[20];

int  j = 0;
int  i = 0;
int  k = 0;

char a[20];

int  transitions[5][3];
int  visited[10];
int CLOSURE[5][10];

int  MAXSIZE = 8;       
int  stack[8];     
int  top = -1;            

int isempty()
{
   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull()
{
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}


int peek() 
{
   return stack[top];
}


int pop() 
{
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }
   else
         printf("Could not retrieve data, Stack is empty.\n");
 }


int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   }
   else 
	  printf("Could not insert data, Stack is full.\n");
}

int IsVisited(int edge)
{
	for(int i = 0; i < 10; i++)
		if(visited[edge] == 1)
			return 1;

	return 0;
}

void epsilon_closure(int state)
{
	int  e_closure[10];
	
	
	for(int i = 0; i < 10; i++ )
	{	e_closure[i] = -1;
		visited[i] = 0;
	}
	/*for(int edge = 0; P[edge] >= 0; edge++)
	{	push(P[edge]);
		visited[P[edge]] = 1;
	}*/
	push(state);
	visited[state] = 1;
		
	while(top != -1)
	{
		int u = pop();

		j = 0;
		while(j < 5){

			if(transitions[j][0] == u && transitions[j][1] == -1) //epsilon transition from the state
			{
				if(! IsVisited(transitions[j][2]))
				{
					visited[transitions[j][2]] = 1;
					push(transitions[j][2]);
				}
				
			}
			j++;
		}
	}

	j = 0;
	for(int edge = 0; edge < 10; edge++)
	{
		if(visited[edge] == 1)
			e_closure[j++] = edge;
	}
	printf("e-closure(%d) : ",state);
	for (i = 0; e_closure[i] != -1; ++i)
		printf("%d ", e_closure[i]);
	printf("\n");
	
	//return e_closure;
} 


int main()
{
	file = fopen("nfa_2.txt","r");

	if (file == NULL) {
		perror("fopen");
		return -1;
	}

	printf("Reading...\n");
	
	while(!feof(file))
	{
		fscanf(file,"%s",a);
		if(strcmp("//states",a) == 0)
			flag = 1;
		else if(strcmp("//input_symbols",a) == 0)
			break;
		if (flag == 1 && a[0] != '/')
		{
			states[i++] = a[1] - '0';

		}
		numberOfStates = i;	
	}
	

	printf("\nStates : \n");
	for(i = 0; i < numberOfStates; i++ )
	{	
		printf("q%d\n",states[i]);
	}
	printf("\nStack ready");
	i = 0;
	flag = 0;
	
	while(!feof(file))
	{
		fgets(a,100,file);
		if(a[0] == '/')
		{	
			flag = 1;
		}
		if(flag == 1 && a[0] != '/')
		{	
			j = 0;
			transitions[i][j++] = a[1] - '0';
			if(a[3] == 'e')
				transitions[i][j++] = -1;
			else
				transitions[i][j++] = a[3] - '0';
			transitions[i][j] = a[6] - '0';
			i++;
		}
	}
	printf("\nTransitions read\n");
		//j= 0
		for(k = 0; k < numberOfStates; k++)
		{
			//int temp[] = {states[j],-1,-1,-1,-1,-1,-1,-1,-1};
			epsilon_closure(states[k]);
		}
		
		/*for(j = 0; j < 5; j++)
			for(k = 0; k < 10; k++)
				CLOSURE[j][k] = epsilon_closure({0})[k];
				*/
	
	
	return 0;
}