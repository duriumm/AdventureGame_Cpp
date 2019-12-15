#include "Bank.h"

Bank::Bank(int amountOfMoneyInBank)
{
	this->amountOfMoneyInBank = amountOfMoneyInBank;
}
int Bank::GetBankBalance() { return this->amountOfMoneyInBank; }
void Bank::DepositToBank(int sumToDepositToBank) { amountOfMoneyInBank += sumToDepositToBank; }
void Bank::WithdrawFromBank(int sumToWithdrawFromBank){ amountOfMoneyInBank -= sumToWithdrawFromBank; }

