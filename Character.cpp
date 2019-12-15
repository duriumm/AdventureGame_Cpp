#include "Character.h"


Character::Character(string name, int health, int damage)
{
	this->name = name;
	this->health = health;
	this->damage = damage;
}
string Character::GetName() { return name; }

int Character::GetHealth() { return health; }
void Character::SetHealth(int healthToSet) { this->health = healthToSet; }
void Character::AddHealth(int healthToAdd) { this->health += healthToAdd; }

int Character::GetDamage() { return damage + equippedWeapon.GetDamage(); }
void Character::SetDamage(int damageToSet) { this->damage = damageToSet; }

int Character::GetExperience() { return experience; }
void Character::SetExperience(int experienceToSet) { experience = experienceToSet; }

int Character::GetGold() { return gold; }
void Character::SetGold(int goldToSet) { gold = goldToSet; }
void Character::AddGold(int goldToAdd) { gold += goldToAdd; }
void Character::RemoveGold(int goldToRemove) { gold -= goldToRemove; }

Weapon Character::GetEquippedWeapon() { return equippedWeapon; }
void Character::SetEquippedWeapon(Weapon weaponToEquip) { equippedWeapon = weaponToEquip; }
