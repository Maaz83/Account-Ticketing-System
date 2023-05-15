// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Name    : Maaz Saiyed
//  ID      : mmmsaiyed@myseneca.ca
//  Email   : 113485205
//  Section : ZBB
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

#include"commonHelpers.h"





char getCharOption(const char* check)
{
	char val, nl = 'x';
	int flag, i, j = 0;
	do
	{
		flag = 1;
		scanf(" %c%c", &val, &nl);
		if (nl == '\n')
		{
			for (i = 0; check[i] != '\0'; i++)
			{
				if (val == check[i])
				{
					j = 1;
				}
			}
		}
		else
		{
			clearStandardInputBuffer();
		}
		if (j == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", check);
			flag = 0;
		}

	} while (flag == 0);
	return val;
}

void getCString(char* C_stringvalue, int low_bound, int up_bound)
{
	int i, num_cha;
	char Cstring[256];
	do
	{
		scanf(" %[^\n]", Cstring);
		for (i = 0; Cstring[i] != '\0'; i++)
		{

		}
		num_cha = i;
		if (low_bound == up_bound && num_cha != up_bound)
		{
			printf("ERROR: String length must be exactly %d chars: ", low_bound);
		}
		else if (num_cha > up_bound && num_cha > low_bound)
		{
			printf("ERROR: String length must be no more than %d chars: ", up_bound);
		}
		else if (num_cha<low_bound || num_cha>up_bound)
		{
			printf("ERROR: String length must be between %d and %d chars: ", low_bound, up_bound);
		}
	} while (num_cha<low_bound || num_cha>up_bound);

	for (i = 0; i <= up_bound; i++)
	{
		if (Cstring != '\0')
		{
			C_stringvalue[i] = Cstring[i];
		}
	}
}

int positiveInteger(void)
{
	int value;
	do
	{
		value = getInteger();
		if (value < 0)
		{
			printf("ERROR: Value must be positive or zero: ");
		}
	} while (value < 0);
	return value;
}

int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing 
	}
}



int getInteger(void)
{
	char newline = 'x';
	int val, flag;
	do
	{
		scanf("%d%c", &val, &newline);
		if (newline == '\n')
		{
			flag = 1;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
			flag = 0;
		}
	} while (flag == 0);
	return val;
}

int getPositiveInteger(void)
{
	int value;
	do
	{
		value = getInteger();
		if (value <= 0)
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	} while (value <= 0);
	return value;
}

int getIntFromRange(int lower_bound, int upper_bound)
{
	int val;
	do
	{
		val = getInteger();
		if (val<lower_bound || val>upper_bound)
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
		}
	} while (val<lower_bound || val>upper_bound);
	return val;
}



double getDouble(void)
{
	char newline;
	double val;
	do
	{
		scanf("%lf%c", &val, &newline);
		if (newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (newline != '\n');
	return val;
}

double getPositiveDouble(void)
{
	double val;
	do
	{
		val = getDouble();
		if (val <= 0)
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	} while (val <= 0);
	return val;
}