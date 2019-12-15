#pragma once
#include <string>
#include <iostream>
using namespace std;
class Enemy
{
private:
	string name;
	int health;
	int damage;
	int experience;
	int gold;
public:
	Enemy(string name, int health, int damage, int experience, int gold);

	string GetName();

	int GetHealth();
	void SetHealth(int healthToSet);

	int GetDamage();
	void SetDamage(int damageToSet);

	int GetExperience();

	int GetGold();
	void SetGold(int goldToSet);
};