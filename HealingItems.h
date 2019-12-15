#pragma once
#include <string>
using namespace std;;

class HealingItems
{
private:
	string name;
	int healingAmount;
public:
	HealingItems(string name, int healingAmount);

	string GetName();
	int GetHealingAmount();
};

