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
#include<string.h>
#include"ticket.h"
#include<ctype.h>
#include"commonHelpers.h"
#include"accountTicketingUI.h"

void newTicket(struct Ticket* new_tic, int max)
{
	new_tic->num = max + 1;
	printf("New Ticket (Ticket#:0%05d)\n", new_tic->num);
	printf("----------------------------------------\n");
	printf("Enter the ticket SUBJECT (30 chars. maximum): ");
	getCString(new_tic->subject_line, 0, 30);
	printf("\n");
	clearStandardInputBuffer();
	printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
	
	getCString(new_tic->store->message_detail, 0, 150);
	printf("\n");
	clearStandardInputBuffer();
	new_tic->counter = new_tic->counter + 1;
	new_tic->indicator = 1;
}

void modifyActiveticket(struct Ticket* tic)
{
	int choose;
	char opt, opt1;
	do
	{
		printf("\n----------------------------------------\n");
		printf("Ticket %06d - Update Options\n", tic->num);
		printf("----------------------------------------\n");
		printf("Status  : %s\n", tic->indicator == 1 ? "ACTIVE" : "CLOSED");
		printf("Subject : %s\n", tic->subject_line);
		printf("----------------------------------------\n");
		printf("1) Modify the subject\n");
		printf("2) Add a message\n");
		printf("3) Close ticket\n");
		printf("0) Done\n");
		printf("Selection: ");
		choose = getIntFromRange(0, 3);
		printf("\n");
		if (choose == 1)
		{
			printf("Enter the revised ticket SUBJECT (30 chars. maximum): ");
			getCString(tic->subject_line, 0, 30);
		}
		else if (choose == 2)
		{
			if (tic->counter < 20)
			{
				printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
				
				getCString(tic->store[tic->counter].message_detail, 0, 150);
				strcpy(tic->store[tic->counter].display_name_M, tic->store->display_name_M);
				tic->counter = tic->counter + 1;
			}
			else
				printf("ERROR: Message limit has been reached, call ITS Support!\n");
		}
		else if (choose == 3)
		{

			printf("Are you sure you CLOSE this ticket? ([Y]es|[N]o): ");
			opt = getCharOption("YN");
			if (opt == 'Y')
			{
				if (tic->counter < 20)
				{
					printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
					opt1 = getCharOption("YN");
					if (opt1 == 'Y')
					{
						printf("\n");
						printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
						
						getCString(tic->store[tic->counter].message_detail, 0, 150);
						strcpy(tic->store[tic->counter].display_name_M, tic->store->display_name_M);
						clearStandardInputBuffer();
						tic->counter = tic->counter + 1;
					}
				}
				printf("\n*** Ticket closed! ***\n\n");
				tic->indicator = 0;
				choose = 0;
			}
		}
	} while (choose != 0);
}

void manage_ticket(struct Ticket* tic)
{
	int choose;
	char opt, opt1;
	do
	{
		printf("----------------------------------------\n");
		printf("Ticket %06d - Update Options\n", tic->num);
		printf("----------------------------------------\n");
		printf("Status  : %s\n", tic->indicator == 1 ? "ACTIVE" : "CLOSED");
		printf("Subject : %s\n", tic->subject_line);
		printf("Acct#   : %d\n", tic->customer_acc_no);
		printf("Customer: %s\n", tic->store->display_name_M);
		printf("----------------------------------------\n");
		printf("1) Add a message\n");
		printf("2) Close ticket\n");
		printf("3) Re-open ticket\n");
		printf("0) Done\n");
		printf("Selection: ");
		choose = getIntFromRange(0, 3);
		printf("\n");
		if (choose == 1)
		{
			if (tic->indicator != 1)
				printf("ERROR: Ticket is closed - new messages are not permitted.\n");
			else if (tic->counter >= 20)
			{
				printf("ERROR: Message limit has been reached, call ITS Support!\n");
			}
			else {
				printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
				
				char name[] = "Will Smith";
				getCString(tic->store[tic->counter].message_detail, 0, 150);
				strcpy(tic->store[tic->counter].display_name_M, name);
				
				tic->store[tic->counter].acc_type_M = 'A';
				strcpy(tic->store[tic->counter+1].display_name_M, name);

				tic->store[tic->counter+1].acc_type_M = 'A';
				tic->counter = tic->counter + 1;
			}
			printf("\n");
		}
		else if (choose == 2)
		{
			if (tic->indicator != 1)
				printf("ERROR: Ticket is already closed!\n\n");
			else
			{
				printf("Are you sure you CLOSE this ticket? ([Y]es|[N]o): ");
				opt = getCharOption("YN");
				printf("\n");
				if (opt == 'Y')
				{
					if (tic->counter < 20)
					{
						
						printf("Do you want to leave a closing message? ([Y]es|[N]o): ");
						opt1 = getCharOption("YN");
						printf("\n");
						if (opt1 == 'Y')
						{
							printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
							getCString(tic->store[tic->counter].message_detail, 0, 150);
							tic->counter++;
							printf("\n");
						}
					}
					printf("*** Ticket closed! ***\n\n");
					
					tic->indicator = 0;

				}
			}
		}
		else if (choose == 3)
		{
			if (tic->indicator == 1)
				printf("ERROR: Ticket is already active!\n\n");
			else {
				printf("Are you sure you RE-OPEN this closed ticket? ([Y]es|[N]o): ");
				opt = getCharOption("YN");
				printf("\n");
				if (opt == 'Y') {
					tic->indicator = 1;
					printf("*** Ticket re-opened! ***\n\n");
				}
			}
		}
	} while (choose != 0);
}


