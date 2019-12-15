#include "Weapon.h"

Weapon::Weapon(string name, int damage, int value)
{
	this->name = name;
	this->damage = damage;
	this->value = value;
}
int Weapon::GetDamage() { return this->damage; }
string Weapon::GetName() { return this->name; }
int Weapon::GetValue() { return this->value; }
