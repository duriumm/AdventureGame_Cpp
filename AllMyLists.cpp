#include "AllMyLists.h"

AllMyLists::AllMyLists()
{
	this->enemyVector = vector<Enemy> {
	Enemy("Rat", 50, 4, 5, 8),
	Enemy("Wolf", 60, 10, 20, 20),
	Enemy("Thief", 80, 15, 30, 30)
	};
	this->weaponVector = vector<Weapon> {
	Weapon("Piece of glass", 3,50),
	Weapon("Makeshift dagger", 7,100),
	Weapon("Big wooden club", 12,200),
	Weapon("Iron sword", 20,400),
	Weapon("Gladiators axe", 25,500),
	};
}

vector<Enemy> AllMyLists::GetEnemyVector() { return this->enemyVector; }
void AllMyLists::AddEnemyToVector(Enemy enemyToAdd) { enemyVector.push_back(enemyToAdd); }

vector<Weapon> AllMyLists::GetWeaponVector() { return this->weaponVector; }
void AllMyLists::AddweaponToVector(Weapon weaponToAdd) { weaponVector.push_back(weaponToAdd); }
