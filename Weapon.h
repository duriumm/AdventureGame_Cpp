#pragma once
#include <string>
#include <iostream>
using namespace std;
class Weapon
{
private:
	string name;
	int damage;
	int value;
public:
	Weapon(string name, int damage, int value);

	int GetDamage();
	string GetName();
	int GetValue();

};