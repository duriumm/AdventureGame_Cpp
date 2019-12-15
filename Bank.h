#pragma once
class Bank
{
private:
	int amountOfMoneyInBank;
public:
	Bank(int amountOfMoneyInBank);

	int GetBankBalance();
	void DepositToBank(int sumToDepositToBank);
	void WithdrawFromBank(int sumToWithdrawFromBank);

};

