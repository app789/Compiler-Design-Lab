#include <stdio.h>
#define ANSI_COLOR_RED     "\x1b[1;31m"      //To make it ColorFull - courtesy of Abhiram[bro]
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

float parseSum();
float parseProduct();
float parseFactor();
float parseNumber();
float parseExpression();

char *x;
int error = 0;

float parseExpression()
{
	return parseSum();
}

float parseProduct()
{
    float operand_1 = parseFactor();
    while(*x == '*') 
    {
        ++x;
        float operand_2 = parseFactor();
        operand_1 = operand_1 * operand_2; 
    }
	while(*x == '/')
	{
		++x;
        float operand_2 = parseFactor();
        operand_1 = operand_1 / operand_2;
	}
    return operand_1;
}

float parseSum()
{
    float operand_1 = parseProduct();
    
	while(*x == '+' || *x == '-')
    {
        float op = *x;
		++x;
        float operand_2 = parseProduct();
		if(op == '+')
			operand_1 = operand_1 + operand_2;
		else
			operand_1 = operand_1 - operand_2;
    }
    return operand_1;
}

float parseNumber()
{
    float number = 0;
    while(*x >= '0' && *x <= '9')
    {
        number = number * 10;
        number += *x - '0';
        ++x;
    }
    return number;
}
float parseFactor()
{
    if(*x >= '0' && *x <= '9')
    {
        return parseNumber();
    }
    else if(*x == '(')
    {
        ++x;        //skip (
        float sum = parseSum();
        ++x;        //skip )
        return sum;
    }
    else
    {
        printf("\nExpected digit but got " ANSI_COLOR_GREEN "%c\n" ANSI_COLOR_RESET,*x);
		error = 1;
    }
}

int main()
{
    x = "(355/113+5)-(2*3)";
    float result = parseExpression();
	if(!error)
		printf("\nresult = %.2f",result);
	else
		printf(ANSI_COLOR_RED "\nRUNTIME ERROR" ANSI_COLOR_RESET);
    return 0;
}