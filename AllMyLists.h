#pragma once
#include "Enemy.h"
#include "Weapon.h"
#include "HealingItems.h"
#include <vector>
class AllMyLists
{
private:
	vector<Enemy> enemyVector;
	vector<Weapon> weaponVector;
	vector<HealingItems> healingItemsVector; // IN PROGRESS FIXA 
public:
	AllMyLists();
	vector<Enemy> GetEnemyVector();
	void AddEnemyToVector(Enemy enemyToAdd);

	vector<Weapon> GetWeaponVector();
	void AddweaponToVector(Weapon weaponToAdd);

}; 
