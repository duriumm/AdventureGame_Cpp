#include "HealingItems.h"

HealingItems::HealingItems(string name, int healingAmount)
{
	this->name = name;
	this->healingAmount = healingAmount;
}

string HealingItems::GetName() { return this->name; }
int HealingItems::GetHealingAmount() { return this->healingAmount; }



