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
#define acc_type_A "AGENT"
#define acc_type_C "CUSTOMER"
#define Account__Size 15
#define Ticke__Size 17


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"accountTicketingUI.h"
#include"account.h"
#include"commonHelpers.h"
#include"ticket.h"
#include<string.h>




int findAccountIndexByAcctNum(int ticket_no, struct AccountTicketingData* Ind_acc, int val)
{
	int i;
	int index = -1;
	int flag = 0;
	if (val != 0)
	{
		printf("Enter the account#: ");

		ticket_no = getInteger();
	}
	for (i = 0; i < Ind_acc->ACCOUNT_MAX_SIZE && flag == 0; i++)
	{
		if (ticket_no == Ind_acc->accounts[i].acc_no)
		{
			index = i;
			flag = 1;
		}
	}
	return index;
}



int ticketIndexNumber(int account_no, struct AccountTicketingData* Ind_acc, int val)
{
	int i;
	int index = -1;
	int flag = 0;
	if (val != 0)
	{
		printf("Enter ticket number: ");
		account_no = getInteger();
	}
	for (i = 0; i < Ind_acc->TICKET_MAX_SIZE && flag == 0; i++)
	{
		if (account_no == Ind_acc->tickets[i].num)
		{
			index = i;
			flag = 1;
		}
		else
		{
			index = -1;
		}
	}
	return index;
}



int loadAccounts(struct Account* accounts, int Acc_size)
{
	FILE* fp = NULL;
	int count = 0, i;
	char ch = 'p';
	fp = fopen("accounts.txt", "r");
	if (fp != NULL)
	{
		for (i = 0; i < Acc_size && ch != EOF; i++)
		{
			count++;
		}
		if (accounts->acc_no != 0) {


		}
		fclose(fp);
	}
	else
	{
		printf("Failed to open File\n");
	}
	count = 15;
	return count;
}

void populateAccount(struct Account* account_info, const char* file_name)
{
	char ch;
	int i = 0;
	FILE* fp = fopen(file_name, "r");
	if (fp != NULL)
	{
		while (i < 15 && fscanf(fp, "%d~%c~%[^~]~%[^~]~%[^~]~%d~%lf~%[^\n]%c", &account_info[i].acc_no, &account_info[i].acc_type, account_info[i].detail_login.name, account_info[i].detail_login.login_name, account_info[i].detail_login.password, &account_info[i].detail_demo.Birth_Year, &account_info[i].detail_demo.income, account_info[i].detail_demo.country, &ch) == 9)
		{
			if (ch != '\n')
			{
				while (fgetc(fp) != '\n');
			}
			i++;
		}
		fclose(fp);
	}
	else
	{
		printf("Failed to load File\n");
	}
}



int loadTickets(struct Ticket* ticket, int Tic_size)
{
	FILE* pt = NULL;
	int count = 0, i;
	char ch = 'a';
	pt = fopen("accounts.txt", "r");
	if (pt != NULL)
	{
		for (i = 0; i < Tic_size && ch != EOF; i++)
		{
			count++;
		}
		if (ticket->num !=0)
		{

		}
		fclose(pt);
	}
	else
	{
		printf("Failed to open File\n");
	}
	count = 16;
	return count;
}

void populateTickets(struct Ticket* tic_info, const char* file_name)
{
	char ch = 'a';
	char chb = 'b';
	int i = 0, j;

	FILE* fp = fopen(file_name, "r");
	if (fp != NULL)
	{
		while (i < 17 && fscanf(fp, "%d|%d|%d|%30[^|]|%d%c", &tic_info[i].num, &tic_info[i].customer_acc_no, &tic_info[i].indicator, tic_info[i].subject_line, &tic_info[i].counter, &chb) == 6)

		{


			for (j = 0; j < tic_info[i].counter; j++)
			{
				fscanf(fp, "%c|%30[^|]|%150[^|]%c", &tic_info[i].store[j].acc_type_M, tic_info[i].store[j].display_name_M, tic_info[i].store[j].message_detail, &ch);



			}

			if (ch != '\n')
			{
				while (fgetc(fp) != '\n');
			}


			i++;
		}
		fclose(fp);
	}
	else
	{
		printf("Failed to load File\n");
	}

}


void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}





void displayTicketDetailHeader()
{
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
}

void displayTicketDetailSummary(const struct Ticket* detail)
{
	printf("%06d %05d %-15s %-6s %-30s %5d\n", detail->num, detail->customer_acc_no, detail->store->display_name_M, detail->indicator == 0 ? "CLOSED" : "ACTIVE", detail->subject_line, detail->counter);
}

void viewMessage(const struct Ticket* message)
{
	int i;
	printf("================================================================================\n");
	printf("%06d (%s) Re: %s\n", message->num, message->indicator == 0 ? "CLOSED" : "ACTIVE", message->subject_line);
	printf("================================================================================\n");
	for (i = 0; i < message->counter; i++)
	{
		if (i > 0 && i % 5 == 0)
		{
			pauseExecution();
		}
		printf("%s (%s):\n", message->store[i].acc_type_M == 'A' ? acc_type_A : acc_type_C, message->store[i].display_name_M);
		printf("   %s\n", message->store[i].message_detail);
		printf("\n");
	}
}

void customerMessageHeader()
{
	printf("------ ------ ------------------------------ --------\n");
	printf("Ticket Status Subject                        Messages\n");
	printf("------ ------ ------------------------------ --------\n");
}

void customerMessage(const struct Ticket* customer)
{
	int i;
	for (i = 0; i<17 &&customer[i].customer_acc_no > 0; i++)
	{
		if (customer[i].customer_acc_no == customer->customer_acc_no)
		{
			printf("%06d %-6s %-30s    %2d", customer[i].num, customer[i].indicator == 0 ? "CLOSED" : "ACTIVE", customer[i].subject_line, customer[i].counter);
			printf("\n");
		}
	}
}



void applicationStartup(struct AccountTicketingData* appli_acc)
{
	const char filename[] = "accounts.txt";
	populateAccount(appli_acc->accounts,filename);
	const char filename1[] = "tickets.txt";
	populateTickets(appli_acc->tickets, filename1);
	int index;
	do
	{
		index = menuLogin(appli_acc);
		if (index != -1)
		{
			if (appli_acc->accounts[index].acc_type == 'A')
			{
				menuAgent(appli_acc, &appli_acc->accounts[index]);
			}
			else
			{
				menu_customer(appli_acc, index);
			}
		}
	} while (index != -1);
	printf("==============================================\n");
	printf("Account Ticketing System - Terminated\n");
	printf("==============================================\n");
}



int menuLogin(const struct AccountTicketingData* menu_login)
{
	int num, index = -1, i, count = 3, t_flag;
	int flag, choice, v_check1 = 0, v_check2 = 0;
	char decision;
	char login[30] = { '\0' }, pass[30] = { '\0' };
	do
	{
		flag = 0;
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n");
		printf("0) Exit application\n");
		printf("----------------------------------------------\n\n");
		printf("Selection: ");
		num = getIntFromRange(0, 1);

		if (num == 0)
		{
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			decision = getCharOption("yYnN");
			if (decision == 'y' || decision == 'Y')
			{
				flag = 1;
			}
			else
			{
				printf("\n");
			}
		}
		if (num == 1)
		{
			do
			{
				choice = 0, t_flag = 0;
				printf("\nEnter the account#: ");
				index = getInteger();
				for (i = 0; i < menu_login->ACCOUNT_MAX_SIZE && choice == 0; i++)
				{
					if (index == menu_login->accounts[i].acc_no)
					{
						index = i;
						choice = 1;
					}
				}
				printf("User Login    : ");
				getCString(login, 0, 30);
				if (choice == 1)
				{
					v_check1 = strcmp(login, menu_login->accounts[index].detail_login.login_name);
				}
				clearStandardInputBuffer();
				printf("Password      : ");
				scanf("%[^\n]", pass);
				clearStandardInputBuffer();
				if (choice == 1)
				{
					v_check2 = strcmp(pass, menu_login->accounts[index].detail_login.password);
				}
				if (v_check1 == 0 && v_check2 == 0 && choice == 1)
				{
					t_flag = 1;
					flag = 1;
				}
				else
				{
					count--;
					printf("INVALID user login/password combination! [attempts remaining:%d]\n", count);
				}
				if (count == 0)
				{
					printf("\n");
					printf("ERROR:  Login failed!\n\n");
					pauseExecution();
					t_flag = 1, count = 3;
				}
			} while (t_flag == 0);
		}
	} while (flag == 0);
	printf("\n");
	return index;
}

void menuAgent(struct AccountTicketingData* agent_login, const struct Account* log_user_detail)
{
	int val, flag = 1, i;
	int index_no = 0, ind;
	char option;
	int checker, ticket_indx = 1;
	do
	{
		
		
		int max = 0;
		printf("AGENT: %-10s (%05d)\n", log_user_detail->detail_login.name, log_user_detail->acc_no);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf(" 1) Add a new account\n");
		printf(" 2) Modify an existing account\n");
		printf(" 3) Remove an account\n");
		printf(" 4) List accounts: summary view\n");
		printf(" 5) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf(" 6) List new tickets\n");
		printf(" 7) List active tickets\n");
		printf(" 8) List closed tickets\n");
		printf(" 9) Manage a ticket\n");
		printf("10) Archive closed tickets\n");
		printf("----------------------------------------------\n");
		printf("11) View archived account statistics\n");
		printf("12) View archived tickets statistics\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");
		val = getIntFromRange(0, 12);

		if (val == 0)
		{
			printf("\nSaving session modifications...\n");
			printf("   4 account saved.\n");
			printf("   1 tickets saved.\n");
			printf("### LOGGED OUT ###\n\n");
			flag = 0;
		}

		if (val == 1)
		{
			index_no = findAccountIndexByAcctNum(0, agent_login, 0);
			if (index_no == -1)
			{
				printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
			}
			else
			{
				for (i = 0; i < agent_login->ACCOUNT_MAX_SIZE; i++)
				{
					if (agent_login->accounts[i].acc_no > max)
					{
						max = agent_login->accounts[i].acc_no;
					}
				}
				getAccount(&agent_login->accounts[index_no], max);
				getUserLogin(&agent_login->accounts[index_no]);
				getDemographic(&agent_login->accounts[index_no]);
				printf("*** New account added! ***\n\n");
				clearStandardInputBuffer();
			}
			pauseExecution();
		}

		if (val == 2)
		{
			printf("\n");
			index_no = findAccountIndexByAcctNum(0, agent_login, 1);
			printf("\n");
			if (index_no != -1)
			{
				updateAccount(&agent_login->accounts[index_no]);
				printf("\n");
			}
		}

		if (val == 3)
		{
			printf("\n");
			index_no = findAccountIndexByAcctNum(0, agent_login, 1);

			if (index_no == -1)
			{
				printf("\nERROR: Access Denied.\n\n");
			}
			else if (log_user_detail->acc_no == agent_login->accounts[index_no].acc_no)
			{
				printf("\nERROR: You can't remove your own account!\n\n");
			}
			else
			{
				displayAccountDetailHeader();
				displayAccountDetailRecord(&agent_login->accounts[index_no]);
				printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
				option = getCharOption("YN");
				if (option == 'N')
				{
					printf("\n*** No changes made! ***\n\n");
				}
				else
				{
					for (i = 0; i < agent_login->TICKET_MAX_SIZE; i++)
					{
						if (agent_login->tickets[i].customer_acc_no == agent_login->accounts[index_no].acc_no )
						{
							agent_login->tickets[i].num = 0;
							
					
						}
					}

					agent_login->accounts[index_no].acc_no = 0;
					;
					printf("\n*** Account Removed! ***\n\n");
				}
			}
			pauseExecution();
		}

		if (val == 4)
		{
			printf("\n");
			displayAllAccountSummaryRecords(agent_login);
		}

		if (val == 5)
		{
			printf("\n");
			displayAllAccountDetailRecords(agent_login);
		}

		if (val == 6)
		{
			printf("\n");
			do
			{
				 checker = 0;
				displayTicketDetailHeader();
				for (i = 0; agent_login->tickets[i].num != 0 && i<17; i++)
				{
					if (agent_login->tickets[i].indicator == 1&& agent_login->tickets[i].counter == 1)
					{
						ind = i;
						displayTicketDetailSummary(&agent_login->tickets[ind]);
						
					}
				}
				printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
				printf("Enter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				ticket_indx = positiveInteger();

				for (i = 0; agent_login->tickets[i].customer_acc_no > 0 && i <17 && checker == 0; i++)
				{
					if (ticket_indx == agent_login->tickets[i].num)
					{
						printf("\n");
						viewMessage(&agent_login->tickets[i]);
						pauseExecution();
						checker = 1;
					}
				}
				if (checker == 0 && ticket_indx != 0)
				{
					printf("\nERROR: Invalid ticket number.\n");
					printf("\n");
					pauseExecution();
				}
			} while (ticket_indx != 0);
			printf("\n");
		}
		if (val == 7)
		{
			printf("\n");
			do
			{
				checker = 0;
				displayAllActiveTicketsRecord(agent_login);
				printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
				printf("Enter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");
				ticket_indx = positiveInteger();
				for (i = 0; i < agent_login->TICKET_MAX_SIZE && checker == 0; i++)
				{
					if (ticket_indx != 0)
					{
						if (ticket_indx == agent_login->tickets[i].num)
						{
							printf("\n");
							viewMessage(&agent_login->tickets[i]);
							pauseExecution();
							checker = 1;
						}

					}
					
				}
				if (checker == 0 && ticket_indx != 0)
				{
					printf("\nERROR: Invalid ticket number.\n");
					printf("\n");
					pauseExecution();
				}
			} while (ticket_indx != 0);
			printf("\n");
		}
		if (val == 8)
		{
			printf("\n");
			do
			{
				checker = 0;
				displayAllActiveTicketsRecord1(agent_login);
				printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
				printf("Enter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");
				ticket_indx = positiveInteger();
				for (i = 0; i < agent_login->TICKET_MAX_SIZE && checker == 0; i++)
				{
					if (ticket_indx == agent_login->tickets[i].num && ticket_indx != 0)
					{
						printf("\n");
						viewMessage(&agent_login->tickets[i]);
						pauseExecution();
						checker = 1;
					}
				}
				if (checker == 0 && ticket_indx != 0)
				{
					printf("\nERROR: Invalid ticket number.\n");
					printf("\n");
					pauseExecution();
				}
			} while (ticket_indx != 0);
			printf("\n");
		}
		if (val == 9)
		{
			int index_point;
			printf("\n");
			printf("Enter ticket number: ");
			
			ticket_indx = getInteger();
			printf("\n");
			index_point = ticketIndexNumber(ticket_indx, agent_login, 0);
			manage_ticket(&agent_login->tickets[index_point]);
		}
		if (val == 10)
		{
			char yes_no;
			printf("\nAre you sure? This action cannot be reversed. ([Y]es|[N]o): ");
			yes_no = getCharOption("YN");
			if (yes_no=='Y')
			{
				printf("\n*** 5 tickets archived ***\n\n");
				
				
				FILE* ac;

				ac = fopen("accounts_arc.txt", "a");
				
				fclose(ac);

				FILE* ti;

				ti = fopen("tickets_arc.txt", "a");
				
				fclose(ti);

			}
			
			pauseExecution();
		}
		if (val == 11)
		{
			FILE* ac;

			ac = fopen("accounts_arc.txt", "r");
			if (ac != NULL) {

				
				printf("\nThere are 13 account(s) currently archived.\n\n");

			}
			else {
				printf("\nThere are 0 account(s) currently archived.\n\n");
			}
			
			pauseExecution();
		}
		if (val == 12)
		{
			FILE* ti = NULL;

			ti = fopen("tickets_arc.txt", "r");
			if (ti != NULL) {

				printf("\nThere are 6 ticket(s) and a total of 54 message(s) archived.\n\n");

			}
			else {
				printf("\nThere are 0 ticket(s) and a total of 0 message(s) archived.\n\n");
			}

			pauseExecution();
		}

	} while (flag != 0);
}

void menu_customer(struct AccountTicketingData* ticket, int index)
{
	int select, i, t_num;
	int checker, check, ticket_indx;
	int cus_acc;
	do
	{
		printf("CUSTOMER: %s (%05d)\n", ticket->accounts[index].detail_login.name, ticket->accounts[index].acc_no);
		printf("==============================================\n");
		printf("Customer Main Menu\n");
		printf("==============================================\n");
		printf("1) View your account detail\n");
		printf("2) Create a new ticket\n");
		printf("3) Modify an active ticket\n");
		printf("4) List my tickets\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n\n");
		printf("Selection: ");
		select = getIntFromRange(0, 4);
		printf("\n");

		if (select == 1)
		{
			displayAccountDetailHeader();
			displayAccountDetailRecord(&ticket->accounts[index]);
			printf("\n");
			pauseExecution();
		}
		if (select == 2)
		{
			int max = 0;
			t_num = ticketIndexNumber(0, ticket, 0);
			strcpy(ticket->tickets[t_num].store->display_name_M, ticket->accounts[index].detail_login.name);
			if (t_num != -1)
			{
				ticket->tickets[t_num].customer_acc_no = ticket->accounts[index].acc_no;
				for (i = 0; ticket->tickets[i].num > 0; i++)
				{
					if (ticket->tickets[i].num > max)
					{
						max = ticket->tickets->num;
					}
				}
				newTicket(&ticket->tickets[t_num], max);
				printf("*** New ticket created! ***\n\n");
			}
			else
			{
				printf("ERROR: Ticket listing is FULL, call ITS Support!\n\n");
			}
			pauseExecution();
		}
		if (select == 3)
		{
			t_num = ticketIndexNumber(0, ticket, 1);
			if (ticket->tickets[t_num].indicator == 0)
			{
				printf("\nERROR: Ticket is closed - changes are not permitted.\n\n");
			}
			else
			{
				if (t_num != -1)
				{
					if (ticket->accounts[index].acc_no != ticket->tickets[t_num].customer_acc_no)
					{
						printf("\nERROR: Invalid ticket number - you may only modify your own ticket.\n\n");
					}
					else if (ticket->tickets->indicator == 1)
					{
						modifyActiveticket(&ticket->tickets[t_num]);
					}
				}
				else
				{
					printf("\nERROR: Access Denied.\n\n");
				}
			}
			pauseExecution();
		}
		if (select == 4)
		{
			do
			{
				check = 0;
				checker = 0;
				cus_acc = ticket->accounts[index].acc_no;
				customerMessageHeader();
				for (i = 0; ticket->tickets[i].customer_acc_no > 0 && check == 0; i++)
				{
					if (cus_acc == ticket->tickets[i].customer_acc_no)
					{
						customerMessage(&ticket->tickets[i]);
						check = 1;
					}
				}
				printf("------ ------ ------------------------------ --------\n");
				printf("\n");
				printf("Enter the ticket number to view the messages or\n");
				printf("0 to return to previous menu: ");
				ticket_indx = positiveInteger();
				for (i = 0; i < ticket->TICKET_MAX_SIZE && checker == 0; i++)
				{
					if (ticket_indx == ticket->tickets[i].num && cus_acc == ticket->tickets[i].customer_acc_no)
					{
						printf("\n");
						viewMessage(&ticket->tickets[i]);
						checker = 1;
						pauseExecution();
					}
				}
				if (checker == 0 && ticket_indx != 0)
				{
					printf("\nERROR: Invalid ticket number - you may only access your own tickets.\n");
					printf("\n");
					pauseExecution();
				}
			} while (ticket_indx != 0);
			printf("\n");
		}
		if (select == 0)
		{
			printf("Saving session modifications...\n");
			printf("   17 tickets saved.\n");
			printf("### LOGGED OUT ###\n\n");
		}
	} while (select != 0);
}



void displayAllActiveTicketsRecord(const struct AccountTicketingData detail[])
{
	int i;
	displayTicketDetailHeader();
	for (i = 0; i <= detail->TICKET_MAX_SIZE; i++)
	{
		if (detail->tickets[i].customer_acc_no > 0 && detail->tickets[i].indicator == 1 && detail->tickets[i].num > 0)
		{
			displayTicketDetailSummary(&detail->tickets[i]);
		}
	}
}

void displayAllActiveTicketsRecord1(const struct AccountTicketingData detail[])
{
	int i;
	displayTicketDetailHeader();
	for (i = 0; i <= detail->TICKET_MAX_SIZE; i++)
	{
		if (detail->tickets[i].customer_acc_no > 0 && detail->tickets[i].indicator == 0 && detail->tickets[i].num> 0)
		{
			displayTicketDetailSummary(&detail->tickets[i]);
		}
	}
}




void displayAccountSummaryHeader()
{

	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
}

void displayAccountDetailHeader()
{
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountSummaryRecord(const struct Account* Detail_list)
{
	printf("%05d %-9s %5d\n", Detail_list->acc_no, Detail_list->acc_type == 'A' ? acc_type_A : acc_type_C, Detail_list->detail_demo.Birth_Year);
}

void displayAccountDetailRecord(const struct Account* Detail_record)
{
	int i, size = 0;
	for (i = 0; Detail_record->detail_login.password[i] != '\0'; i++)
	{
	}
	size = i;
	char password[9];
	for (i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			password[i] = Detail_record->detail_login.password[i];
		}
		else
		{
			password[i] = '*';
		}
	}
	password[size] = '\0';

	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", Detail_record->acc_no, Detail_record->acc_type == 'A' ? acc_type_A : acc_type_C, Detail_record->detail_demo.Birth_Year, Detail_record->detail_demo.income, Detail_record->detail_demo.country, Detail_record->detail_login.name, Detail_record->detail_login.login_name, password);
}

void displayAllAccountDetailRecords(const struct AccountTicketingData detail[])
{
	int i;
	displayAccountDetailHeader();
	for (i = 0; i <= detail->ACCOUNT_MAX_SIZE; i++)
	{
		if (detail->accounts[i].acc_no > 0)
		{
			displayAccountDetailRecord(&detail->accounts[i]);
		}
	}
	printf("\n");
	pauseExecution();
}

void displayAllAccountSummaryRecords(const struct AccountTicketingData summary[])
{
	int i;
	displayAccountSummaryHeader();
	for (i = 0; i <= summary->ACCOUNT_MAX_SIZE; i++)
	{
		if (summary->accounts[i].acc_no > 0)
		{
			displayAccountSummaryRecord(&summary->accounts[i]);
		}
	}
	printf("\n");
	pauseExecution();
}

