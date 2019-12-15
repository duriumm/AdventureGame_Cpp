#include "Enemy.h"


Enemy::Enemy(string name, int health, int damage, int experience, int gold)
{
	this->name = name;
	this->health = health;
	this->damage = damage;
	this->experience = experience;
	this->gold = gold;
}
string Enemy::GetName() { return name; }

int Enemy::GetHealth() { return health; }
void Enemy::SetHealth(int healthToSet) { this->health = healthToSet; }

int Enemy::GetDamage() { return damage; }
void Enemy::SetDamage(int damageToSet) { this->damage = damageToSet; }

int Enemy::GetExperience() { return experience; }

int Enemy::GetGold() { return gold; }
void Enemy::SetGold(int goldToSet) { gold = goldToSet; }
