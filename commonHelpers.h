// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Name    : Maaz Saiyed
//  ID      : mmmsaiyed@myseneca.ca
//  Email   : 113485205
//  Section : ZBB
// ===================================================================================

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_


int currentYear(void);							

void clearStandardInputBuffer(void);

int getInteger(void);

int getPositiveInteger(void);

int getIntFromRange(int lower_bound, int upper_bound);

double getDouble(void);

double getPositiveDouble(void);

char getCharOption(const char* check);

void getCString(char* C_stringvalue, int low_bound, int up_bound);

int positiveInteger(void);

#endif // !COMMON_HELPERS_H_