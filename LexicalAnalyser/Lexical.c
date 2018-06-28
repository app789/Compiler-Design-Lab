#include<stdio.h>
#include<ctype.h>
#include<string.h>

FILE *fi,*fo,*fop,*fk;
int flag = 0;
int i = 1;
char c,t,a[15],ch[15],file[20];

void CheckOperator()
{
	while(!feof(fop))
	{
		if(strcmp(ch,a) == 0)
		{
			fscanf(fop,"%s",ch);
			printf("\t\t%s\t:\t%s\n",a,ch);
			flag = 1;
			break;
		} 
		fscanf(fop,"%s",ch);
	}
	rewind(fop);	
}

void CheckKeyword()
{
	fscanf(fk,"%s",ch);
		
	//Checking for keywords
	while(!feof(fk))
	{
		if(strcmp(ch,a) == 0)
		{
			fscanf(fk,"%k",ch);
			printf("\t\t%s\t:\tKeyword\n",a);
			flag = 1;
			break;
		}
		fscanf(fk,"%s",ch);
	}
	rewind(fk);
}

int main()
{
	printf("\n Enter the File Name:");
	scanf("%s",&file);
	fi = fopen(file,"r");

	fo = fopen("inter.c","w");
	fop = fopen("oper.c","r");
	fk = fopen("key.c","r");
	c = getc(fi);
	while(!feof(fi))
	{
		if(isalpha(c)|| isdigit(c)|| c == '.')
			fputc(c,fo);
		else
		{
			if(c == '\n')
				fprintf(fo,"\t$\t");
			else 
				fprintf(fo,"\t%c\t",c);
		}
		c = getc(fi);
	}
	fclose(fi);
	fclose(fo);
	fi = fopen("inter.c","r");
	printf("\n LEXICAL ANALYSIS");
	
	//Read the first line
	fscanf(fi,"%s",a);
	
	printf("\n Line: %d\n",i++);
	while(!feof(fi))
	{
		//'$' to separate lines
		if(strcmp(a,"$") == 0)    
		{ 
			printf("\n Line: %d\n",i++);
			fscanf(fi,"%s",a);
		}
		
		fscanf(fop,"%s",ch); //CHECK
		
		//Checking for Operators
		CheckOperator();
		
		//if not operator
		if(flag != 1)
		{
			CheckKeyword();
		}
		
		
		//If not operator or keyword
		if(flag == 0)
		{
			if(isdigit(a[0]))
				printf("\t\t%s\t:\tConstant\n",a);
			else
				printf("\t\t%s\t:\tIdentifier\n",a);
		}
		flag = 0;
		fscanf(fi,"%s",a);
	}
	return 0;
}
	
