// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Name    : Maaz Saiyed
//  ID      : mmmsaiyed@myseneca.ca
//  Email   : 113485205
//  Section : ZBB
// ===================================================================================

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

struct Demographic
{
	int Birth_Year;
	double income;
	char country[50];
};
struct UserLogin
{
	char name[50];
	char login_name[50];
	char password[50];
};
struct Account
{
	int acc_no;
	char acc_type;
	struct UserLogin detail_login;
	struct Demographic detail_demo;
};



void getAccount(struct Account* account_detail, int max);

void getUserLogin(struct Account* login_detail);

void getDemographic(struct Account* demo);

void updateAccount(struct Account* update_acc);

void updateUserLogin(struct UserLogin* user_login);

void updateDemographic(struct Demographic* demo_);
#endif // !ACCOUNT_H_