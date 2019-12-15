#include "Weapon.h"

class Character
{
private:
	string name;
	int health;
	int damage;
	int experience = 0;
	int gold = 0;
	Weapon equippedWeapon = Weapon("Bare knuckles", 0, 0);   ///ÄNDRA SÅ VAPNETS SKADA ÄR SEPARAT FRÅN BAS DAMAGE
public:
	Character(string name, int health, int damage);

	string GetName();

	int GetHealth();
	void SetHealth(int healthToSet);
	void AddHealth(int healthToAdd);

	int GetDamage();
	void SetDamage(int damageToSet);

	int GetExperience();
	void SetExperience(int experienceToSet);

	int GetGold();
	void SetGold(int goldToSet);
	void AddGold(int goldToAdd);
	void RemoveGold(int goldToRemove);

	Weapon GetEquippedWeapon();
	void SetEquippedWeapon(Weapon weaponToEquip);

};