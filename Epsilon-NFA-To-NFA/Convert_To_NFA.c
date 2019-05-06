/*Source : Me */

#include <stdio.h>     
#include <string.h> 	//WHEN I'M GONE 
#include <errno.h>
#include <stdlib.h>
#include <time.h>

FILE *file;
FILE *fout;
int  numberOfStates = 0;
int  flag = 0;
int  states[20];
int final_states[20];
int inFinal[20];
int no_of_final = 0;
int no_of_inputs = 0;
int inputs[10];

int j = 0;
int i = 0;
int k = 0;
int ex = 0; 

char a[150];

int  transitions[10][5][5];
int  visited[10];

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

int * epsilon_closure(int state)
{
	int  e_closure[10];
	int n = 0;
	int* out ;
	//free(out);
	
	for(int i = 0; i < 10; i++ )
	{	e_closure[i] = -1;
		visited[i] = 0;
	}
	
	push(state);
	visited[state] = 1;
		
	while(top != -1)
	{
		int u = pop();

		j = 1;
		while(j < numberOfStates)
		{
			//if there is an epsilon transition from the state 'u' to 'v'
			if(transitions[j][0][0] == u && transitions[j][ex][0] != 232) //ASCII of Φ = 232
			{
				for(int d = 0; transitions[j][ex][d] != 232; d++)  //loop through the 3rd dimension
					if(! IsVisited(transitions[j][ex][d]))  		//REPLACED 4 with ex
					{
						visited[transitions[j][ex][d]] = 1;
						push(transitions[j][ex][d]);
					}
			}
			j++;
		}
	}

	j = 0;
	for(int edge = 0; edge < 10; edge++)
	{
		if(visited[edge] == 1)
		{	
			e_closure[j++] = edge;
			n++;
		}
	}
	printf("e-closure(%d) : ",state);
	for (i = 0; e_closure[i] != -1; ++i)
		printf("%d ", e_closure[i]);
	printf("\n");

	out = (int*) malloc((n+1) * sizeof(int)); //new array
	if (out == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	
	for(i = 0; i < n; ++i) //i < 10 changed to i < n due to SIGSEV
	{
		out[i] = e_closure[i];
	}
	out[i] = -1;     //Set delimter as -1 at the end
	return out;
}

void Read()
{
	file = fopen("nfa.txt","r");
	fout = fopen("output.txt","w");
	    //BITCH PLEASE!
	if (file == NULL ) {
		perror("fopen");
		//return -1;
	}
	else if (fout == NULL ) {
		perror("fopen");
		//return -1;
	}
	printf("Reading...\n");
	//Reading the states 
	while(!feof(file))
	{
		fscanf(file,"%s",a);
		if(strcmp("//states",a) == 0)
			flag = 1;
		else if(strcmp("//input_symbols",a) == 0)
		{	
			fscanf(file,"%s",a);
			while(a[0] != '/')
			{	
				inputs[no_of_inputs++] = a[0] - '0';
				fscanf(file,"%s",a);
			}
			flag = 0;
		}
		else if(strcmp("//final_state",a) == 0)
		{
			fscanf(file,"%s",a);
			while(a[0] != '/')
			{
				final_states[no_of_final++] = a[1] - '0';
				inFinal[a[1] - '0'] = 1;
				fscanf(file,"%s",a);
			}
			break;
		}
		
		if (flag == 1 && a[0] != '/')
		{
			states[i++] = a[1] - '0';
		}
		numberOfStates = i;	
	}
	
	//Display the states of the e-NFA
	printf("\nStates : \n");
	for(i = 0; i < numberOfStates; i++ )
	{	
		printf("q%d\n",states[i]);
	}
	
	//Reading the transition table
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{ 
			for(int k = 0; k < 5; k++)
			transitions[i][j][k] = 232;
		}
	}
	for(i = 1; i <= no_of_inputs; i++)  //initialize the top row with input
		transitions[0][i][0] = inputs[i-1];
	transitions[0][i][0] = -1;           // ε input
	ex = i;	// column of ε input 
	
	while(!feof(file))
	{
		fgets(a,100,file);
		if(a[0] == 'q')
		{	
			//FOUND A NEW WAY OF STORING TRANSITION TABLE IN A MATRIX
			if(a[3] == 'e')
			{
				for(int d = 0; d < 5; d++)
					if(transitions[(a[1] - '0') + 1][ex][d] == 232)
					{	
						transitions[(a[1] - '0') + 1][ex][d] = a[6] - '0';
						break;
					}
			}
			else	
			{	
				for(j = 1; j <= no_of_inputs; j++)  //initialize the top row with input
				{	
					if(transitions[0][j][0] ==  a[3] - '0')
						break;
				}
				transitions[(a[1] - '0') + 1][j][0] = a[6] - '0';
			}
			/*if(a[3] != 'e')
				transitions[0][a[3] - '0' + 1] = a[3] - '0';		//input
			else
				transitions[0][4] = -1;		// epsilon input*/
			transitions[(a[1] - '0') + 1][0][0] = a[1] - '0'; //initial state
			
		}
	}
	for(i = 0; i < numberOfStates; i++ )
	{	
		if(transitions[i][0][0] == 232)
			transitions[i][0][0] = states[i-1];
	}
	printf("\nTransitions read\n");
	
}

void UpdateFinalStates(int **ptr)
{
	//update the final states
	for(k = 0; k < no_of_final; k++){
		for(i = 0; i < numberOfStates; ++i){
			for(j = 0; ptr[i][j] >= 0; ++j){	
				if(final_states[k] == ptr[i][j] && !inFinal[*ptr[i]]){
					final_states[no_of_final++] = *ptr[i];
					inFinal[*ptr[i]] = 1;
				}
				if(no_of_final == numberOfStates)
					break;
			}
		}
	}
}

void Convert(int **pointers)
{
	int intermed[20];
	int e[10];
	int initial = -1;
	int ei = -1;

	for(i = 1; i < (numberOfStates+1); ++i)
	{
		for(j = 1; j < no_of_inputs+1; ++j)
		{
			initial = transitions[i][0][0];     // do ε input ε
			
			for(int i = 0; i < 20; i++)
				intermed[i] = -1;
			
			for(k = 0; pointers[initial][k] >= 0; ++k)
			{
				ei = pointers[initial][k];          // ε
				intermed[k] = transitions[ei+1][j][0]; // ε input
			}
			
			for(int b = 0; b < 10; b++)   //clear the array
				e[b] = -1;
			
			int n = 0;
			for(int m = 0; intermed[m] >= 0; m++)
			{
				if(intermed[m] != 232)
					e[n++] = intermed[m];                 //ε input ε
			}
			if(j != ex)
			{
				fprintf(fout,"\n(q%d,%d) =  ",transitions[i][0][0],transitions[0][j][0]);
				for(int p = 0; e[p] != -1; p++)
					for(int m = 0; pointers[e[p]][m] >= 0; m++)
						fprintf(fout,"q%d,",pointers[e[p]][m]);
			}
		}
	}
}

int main()
{
	clock_t	start, end;

	start = clock();//time count starts
	
	Read();

	int *pointers[numberOfStates]; //stores pointers to the e-closures of all states
	//Calling e-closure for all the states	
	for(k = 0; k < numberOfStates; k++)
	{
		pointers[k] = epsilon_closure(states[k]);
	}
	
	UpdateFinalStates(pointers);
	
	fprintf(fout,"Final states:");
	for(i = 0; i < no_of_final; i++)
		fprintf(fout,"q%d ",final_states[i]);
	printf("Final states:");
	for(i = 0; i < no_of_final; i++)
		printf("q%d ",final_states[i]);
	
	Convert(pointers);
	
	fclose(file);
	fclose(fout);
	
	//Free the memory used to store e-closures of all states
	for(i = 0; i < numberOfStates; i++)
		free(pointers[i]);
	
	end = clock();//time count stops 
	printf("\nTime taken : %f\n", (float)(end-start)/CLOCKS_PER_SEC);	
	
	return 0;
}

