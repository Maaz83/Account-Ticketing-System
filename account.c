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
#include"accountTicketingUI.h"
#include"commonHelpers.h"
#include"account.h"
#include"ticket.h"
#include<ctype.h>
#include<stdlib.h>




void getDemographic(struct Account* demo)
{
	int Year = 0, i;
	printf("Demographic Data Input\n");
	printf("----------------------------------------\n");
	printf("Enter birth year (current age must be between 18 and 110): ");
	Year = currentYear();
	demo->detail_demo.Birth_Year = getIntFromRange(Year - 110, Year - 18);
	printf("Enter the household Income: $");
	demo->detail_demo.income = getPositiveDouble();
	printf("Enter the country (30 chars max.): ");
	getCString(demo->detail_demo.country, 0, 30);
	for (i = 0; demo->detail_demo.country[i] != '\0'; i++)
	{
		demo->detail_demo.country[i] = toupper(demo->detail_demo.country[i]);
	}
	printf("\n");
}

void updateAccount(struct Account* update_acc)
{
	
		int val;
		do
		{
			printf("Account: %05d - Update Options\n", update_acc->acc_no);
			printf("----------------------------------------\n");
			printf("1) Update account type (current value: %c)\n", update_acc->acc_type);
			printf("2) Login\n");
			printf("3) Demographics\n");
			printf("0) Done\n");
			printf("Selection: ");
			val = getIntFromRange(0, 3);
			if (val == 1)
			{
				printf("\nEnter the account type (A=Agent | C=Customer): ");
				update_acc->acc_type = getCharOption("AC");
			}
			else if (val == 2)
			{
				updateUserLogin(&update_acc->detail_login);
				printf("\n");
			}
			else if (val == 3)
			{
				
				updateDemographic(&update_acc->detail_demo);
				printf("\n");
			}
			else if (val == 0)
			{
				val = 0;
			}
		} while (val != 0);
	}

void updateUserLogin(struct UserLogin* user_login)
{
	int val;
	int a, b, c, d, result, i;
	do
	{
		printf("\nUser Login: %s - Update Options\n", user_login->login_name);
		printf("----------------------------------------\n");
		printf("1) Display name (current value: %s)\n", user_login->name);
		printf("2) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		val = getIntFromRange(0, 2);
		if (val > 2 || val < 0)
		{
			printf("ERROR: Value must be between 0 and 2 inclusive: ");
		}
		if (val == 1)
		{
			printf("\nEnter the display name (30 chars max): ");
			getCString(user_login->name, 0, 30);
		}
		if (val == 2)
		{
			do
			{
				a = 0, b = 0, c = 0, d = 0;
				result = 0;
				printf("\nEnter the password (must be 8 chars in length): ");
				getCString(user_login->password, 8, 8);
				for (i = 0; user_login->password[i] != '\0'; i++)
				{
					if (isupper(user_login->password[i]))
					{
						a++;
					}
					else if (islower(user_login->password[i]))
					{
						b++;
					}
					else if (isdigit(user_login->password[i]))
					{
						c++;
					}
					else if (isspace(user_login->password[i]))
					{

					}
					else
					{
						d++;
					}
				}
				if (a == 2 && b == 2 && c == 2 && d == 2)
				{
					result = 1;
				}
				else
				{
					printf("SECURITY: Password must contain 2 of each:\n");
					printf("          Digit: 0-9\n");
					printf("          UPPERCASE character\n");
					printf("          lowercase character\n");
					printf("          symbol character: !@#$%c%c&*", 37, 94);
				}
			} while (result == 0);
		}
		if (val == 0)
		{
			val = 0;
		}
	} while (val != 0);
}

void updateDemographic(struct Demographic* demo_)
{
	int val, i;
	do
	{
		printf("\nDemographic Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Household Income (current value: $%.2lf)\n", demo_->income);
		printf("2) Country (current value: %s)\n", demo_->country);
		printf("0) Done\n");
		printf("Selection: ");
		val = getIntFromRange(0, 2);
		if (val > 2 || val < 0)
		{
			printf("ERROR: Value must be between 0 and 2 inclusive: ");
		}
		if (val == 1)
		{
			printf("\n");
			printf("Enter the household Income: $");
			demo_->income = getPositiveDouble();
		}
		if (val == 2)
		{
			printf("\n");
			printf("Enter the country (30 chars max.): ");
			getCString(demo_->country, 0, 30);
			for (i = 0; demo_->country[i] != '\0'; i++)
			{
				demo_->country[i] = toupper(demo_->country[i]);
			}
		}
	} while (val != 0);
}

void getAccount(struct  Account* account_detail, int max)
{
	account_detail->acc_no = max + 1;
	printf("\nNew Account Data (Account#:%05d)\n", account_detail->acc_no);
	printf("----------------------------------------\n");
	printf("Enter the account type (A=Agent | C=Customer): ");
	account_detail->acc_type = getCharOption("AC");
	printf("\n");
}


void getUserLogin(struct Account* login_detail)
{
	int result, i;
	int a, b, c, d;
	printf("User Login Data Input\n");
	printf("----------------------------------------\n");
	do
	{
		result = 0;
		printf("Enter user login (10 chars max): ");
		getCString(login_detail->detail_login.login_name, 0, 10);
		for (i = 0; login_detail->detail_login.login_name[i] != '\0'; i++)
		{
			if (isspace(login_detail->detail_login.login_name[i]))
			{
				result = 1;
			}
		}
		if (result == 1)
		{
			printf("ERROR:  The user login must NOT contain whitespace characters.\n");
		}
	} while (result == 1);

	printf("Enter the display name (30 chars max): ");
	getCString(login_detail->detail_login.name, 0, 30);

	do
	{
		a = 0, b = 0, c = 0, d = 0;
		result = 0;
		printf("Enter the password (must be 8 chars in length): ");
		getCString(login_detail->detail_login.password, 8, 8);
		for (i = 0; login_detail->detail_login.password[i] != '\0'; i++)
		{
			if (isupper(login_detail->detail_login.password[i]))
			{
				a++;
			}
			else if (islower(login_detail->detail_login.password[i]))
			{
				b++;
			}
			else if (isdigit(login_detail->detail_login.password[i]))
			{
				c++;
			}
			else if (isspace(login_detail->detail_login.password[i]))
			{

			}
			else if (login_detail->detail_login.password[i] == '!' || login_detail->detail_login.password[i] == '@' || login_detail->detail_login.password[i] == '#' || login_detail->detail_login.password[i] == '$' || login_detail->detail_login.password[i] == '%' || login_detail->detail_login.password[i] == '^' || login_detail->detail_login.password[i] == '&' || login_detail->detail_login.password[i] == '*')
			{
				d++;
			}
		}
		if (a == 2 && b == 2 && c == 2 && d == 2)
		{
			result = 1;
		}
		else
		{
			printf("SECURITY: Password must contain 2 of each:\n");
			printf("          Digit: 0-9\n");
			printf("          UPPERCASE character\n");
			printf("          lowercase character\n");
			printf("          symbol character: !@#$%c%c&*\n", 37, 94);
		}
	} while (result == 0);
	printf("\n");
}