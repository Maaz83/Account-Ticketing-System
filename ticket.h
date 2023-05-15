// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Name    : Maaz Saiyed
//  ID      : mmmsaiyed@myseneca.ca
//  Email   : 113485205
//  Section : ZBB
// ===================================================================================

#ifndef TICKET_H_
#define TICKET_H_
#include"account.h"

struct Message
{
	char acc_type_M;
	char display_name_M[300];
	char message_detail[300];
};

struct Ticket
{
	int num;
	int customer_acc_no;
	int indicator;
	char subject_line[300];
	int counter;
	struct Message store[20];
};
void newTicket(struct Ticket* new_tic, int max);

void modifyActiveticket(struct Ticket* tic);

void manage_ticket(struct Ticket* tic);

#endif // !TICKET_H_
