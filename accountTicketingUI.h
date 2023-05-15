// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Name    : Maaz Saiyed
//  ID      : mmmsaiyed@myseneca.ca
//  Email   : 113485205
//  Section : ZBB
// ===================================================================================

#include"account.h"
#include"ticket.h"

#ifndef ACCOUNTTICKETINGUI_H_
#define ACCOUNTTICKETINGUI_H_

struct AccountTicketingData
{
	struct Account* accounts;				
	const int ACCOUNT_MAX_SIZE;				
	struct Ticket* tickets;					
	const int TICKET_MAX_SIZE;				
};


void applicationStartup(struct AccountTicketingData* appli_acc);

int menuLogin(const struct AccountTicketingData* menu_login);

void menuAgent(struct AccountTicketingData* agent_login, const struct Account* log_user_detail);

int findAccountIndexByAcctNum(int account_no, struct AccountTicketingData* Ind_acc, int val);

int ticketIndexNumber(int account_no, struct AccountTicketingData* Ind_acc, int val);


void displayAccountSummaryHeader(void);

void displayAccountDetailHeader(void);

void displayAccountSummaryRecord(const struct Account* Detail_list);

void displayAccountDetailRecord(const struct Account* Detail_record);



void displayTicketDetailHeader();

void displayTicketDetailSummary(const struct Ticket* detail);

void displayAllActiveTicketsRecord(const struct AccountTicketingData detail[]);

void displayAllActiveTicketsRecord1(const struct AccountTicketingData detail[]);

void viewMessage(const struct Ticket* message);

void customerMessageHeader();

void customerMessage(const struct Ticket* customer);







void displayAllAccountSummaryRecords(const struct AccountTicketingData summary[]);

void displayAllAccountDetailRecords(const struct AccountTicketingData detail[]);

void menu_customer(struct AccountTicketingData* ticket, int index);

void pauseExecution(void);

 

int loadAccounts(struct Account* accounts, int ACCOUNT_SIZE);

void populateAccount(struct Account* account_info, const char* file_name);



int loadTickets(struct Ticket* tickets, int TICKET_SIZE);

void populateTickets(struct Ticket* tic_info, const char* file_name);

#endif // !accountTicketingUI_H_