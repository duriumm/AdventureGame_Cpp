#include <string>
#include <iostream>
#include <vector>
#include "time.h"
#include <map>
#include <queue>
#include <algorithm>
#include "Enemy.h"
#include "Weapon.h"
#include "AllMyLists.h"
#include "Character.h"
#include "Bank.h"
#include <conio.h>
#include <ctype.h>
using namespace std;

Character CreateCharacter()
{
	string adventurerName;
	cout << "Hello adventurer! What is your name?\n-> ";
	cin >> adventurerName;
	cout << "oh.. thats an ugly name.. I mean.. Welcome " << adventurerName << " !!! Now your journey begins!\n" << endl;
	_getch();
	Character newCharacter = Character(adventurerName, 100, 20);
	return newCharacter;
}
void PrintAdventurerStats(Character& myAdventurer)
{
	system("cls");
	cout << "----- Current stats for " << myAdventurer.GetName() <<
		" -----\nHealth: " << myAdventurer.GetHealth() <<
		"\nDamage: " << myAdventurer.GetDamage() << " (" << myAdventurer.GetEquippedWeapon().GetName() << ///ÄNDRA SÅ VAPNETS SKADA ÄR SEPARAT FRÅN BAS DAMAGE
		 " damage: " << myAdventurer.GetEquippedWeapon().GetDamage() <<") " <<
		"\nExperience: " << myAdventurer.GetExperience() <<
		"\nGold: " << myAdventurer.GetGold() << endl;
}

void CheckIfCinIntInput(int cinIntToInput)
{
	if (cin.fail())
	{
		cout << "You did not enter a correct number.. Try again!\n";

		// get rid of failure state
		cin.clear();

		// From Eric's answer (thanks Eric)
		// discard 'bad' character(s) 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int RandomNrMaxToMin(int maxInput, int minInput)
{
	int randomNumberToOutput = rand() % (maxInput - minInput + 1) + minInput;
	return randomNumberToOutput;
}

void AdventurerDeath(Character& myAdventurer)
{
	system("cls");
	cout << myAdventurer.GetName() << " was killed in battle..." << endl;
	myAdventurer.SetHealth(100);
	myAdventurer.SetExperience(myAdventurer.GetExperience() / 2);
	myAdventurer.SetGold(myAdventurer.GetGold() / 3);
}

void RealBattleVsEnemy(Character& myAdventurer,Enemy& enemyToFight)
{

	string adventurerName = myAdventurer.GetName();
	string enemyName = enemyToFight.GetName();
	int randGoldNr = RandomNrMaxToMin(enemyToFight.GetGold(), enemyToFight.GetGold() / 3);
	int randEscapeNr = RandomNrMaxToMin( 10, 1);

	int choice;
	while (true)
	{		
		int randAttackNrAdventurer = RandomNrMaxToMin(myAdventurer.GetDamage(), myAdventurer.GetDamage() / 2);
		int randAttackNrEnemy = RandomNrMaxToMin(enemyToFight.GetDamage(), enemyToFight.GetDamage() / 2);

		cout << "\n" << adventurerName << " is fighting a fierce " << enemyName
			<< "\n1. Attack\n2. Flee\n-> ";
		// IMPLEMENTERA \t\t\t\t på samma sätt som där nere (man ska se hp på dig och monster innan ni slåss)
		cin >> choice;
		CheckIfCinIntInput(choice);
		system("cls");
		if (choice == 1)
		{
			cout << adventurerName << " attacks for " << randAttackNrAdventurer << " hp!";
			enemyToFight.SetHealth(enemyToFight.GetHealth() - randAttackNrAdventurer);
			cout << "\t\t\t\t" << "Current hp of " << adventurerName << ": " << myAdventurer.GetHealth() << endl;
			if (enemyToFight.GetHealth() <= 0)
			{
				system("cls");
				cout << adventurerName << " has succesfully killed " << enemyName << "!!!" << endl;
				myAdventurer.SetExperience(enemyToFight.GetExperience());
				myAdventurer.AddGold(randGoldNr);
				cout << adventurerName << " has gained " << enemyToFight.GetExperience() << " Experience and "
				<< randGoldNr << " Gold from the battle!" << endl;
				return;
			}
			cout << enemyName << " attacks for " << randAttackNrEnemy << "hp!";
			myAdventurer.SetHealth(myAdventurer.GetHealth() - randAttackNrEnemy);
			cout << "\t\t\t\t" << "Current hp of " << enemyName << ": " << enemyToFight.GetHealth() << endl;
			if (myAdventurer.GetHealth() <= 0)
			{
				AdventurerDeath(myAdventurer);
				return;
			}
		}
		else if (choice == 2)
		{
			cout << "This is a random number showing if u got less than 4 and also the ESCAPE number: " << randEscapeNr << endl;
			if (randEscapeNr > 4)
			{
				system("cls");
				cout << "\nYou escaped succesfully...\n" << endl;
				return;
			}
			else if (randEscapeNr <= 4)
			{
				system("cls");
				cout << "You manage to escape but lost 10 hp from " << enemyToFight.GetName() << endl;
				myAdventurer.SetHealth(myAdventurer.GetHealth() - 10);
				if (myAdventurer.GetHealth() <= 0)
					AdventurerDeath(myAdventurer);
				return;
			}
		}
	}
}
void StageBeforeBattle(Character& myAdventurer, AllMyLists& myEnemyList)
{
	while (true) 
	{
		vector<Enemy> enemyVector = myEnemyList.GetEnemyVector(); // david, ange vectorn redan här så programmet inte behöver gå till funktionen get enemy vector
		int randNr = rand() % enemyVector.size() + 0; 
		int choice;
		//cout << "This is the random number: " << randNr << endl; //#TEST

		cout << "\nOn your search for monsters to slay you find a " << enemyVector[randNr].GetName()
			<< " looking very angry! What do you do?\n\n1. Engage\n2. Run away!\n-> ";
		cin >> choice;
		CheckIfCinIntInput(choice);
		if (choice == 1)
		{
			RealBattleVsEnemy(myAdventurer, enemyVector[randNr]);
			return;
		}
		else if (choice == 2)
		{
			cout << "You managed to escape...\n" << endl;
			return;
		}
	}
}

void VisitTheChurch(Character& myAdventurer)
{
	if (myAdventurer.GetHealth() > 30)
	{
		cout << "Sorry I cannot help you unless you are really wounded... This isnt some charity work we do here you know!" << endl;
		return;
	}
	else
	{
		cout << "Oh by the gods... You are in really bad shape young one... Let us help you!" << endl;
		myAdventurer.AddHealth(30);
		cout << "Gained 30 hitpoints from healing: " << endl;
		return;
	}
}

void TheShop(Character& myAdventurer, AllMyLists& weaponList)
{
	while (true)
	{
		system("cls");
		cout << "Welcome to the shop mate, take a look and tell me if you find something you like.\n" << endl;
		string choice;
		vector <Weapon> weaponVector = weaponList.GetWeaponVector();

		for (auto weapon : weaponVector)
			cout << weapon.GetName() << " - Damage: " << weapon.GetDamage() << "\t" << weapon.GetValue() << " gold." << endl;

		cout << "\nAmount of gold: " << myAdventurer.GetGold() << endl;
		cout << "Weapon equipped: " << myAdventurer.GetEquippedWeapon().GetName() << endl;
		cout << "\nEnter the name of desired weapon to purchase or exit to leave the store: " << endl;

		cin.clear();
		cin.sync(); 
		getline(cin,choice); // ENDA SOM INTE FUNKAR ÄR OM ETT VAPEN INTE FINNS I LISTAN, DÅ LOOPAR DEN OM BARA

		if (choice == "exit" || choice == "Exit") { system("cls"); return; }

		for (auto weapon : weaponVector)
		{
			if (choice == weapon.GetName())
			{
				if (myAdventurer.GetGold() < weapon.GetValue())
				{
					system("cls");
					cout << "You cant even afford a " << weapon.GetName() << " ??? "
						"\n... Damn you are poor.." << endl;
					getchar();
					break;
				}
				else if (choice == weapon.GetName() && myAdventurer.GetGold() >= weapon.GetValue() && myAdventurer.GetEquippedWeapon().GetName() != weapon.GetName())
				{
					system("cls");
					myAdventurer.SetEquippedWeapon(weapon);
					myAdventurer.SetGold(myAdventurer.GetGold() - weapon.GetValue());
					cout << "You bought " << myAdventurer.GetEquippedWeapon().GetName() << " for " << myAdventurer.GetEquippedWeapon().GetValue() << " gold." << endl;		
					getchar();
					break;
				}
			}
		}
	}
}

void TheBank(Character& myAdventurer, Bank& bank)
{
	system("cls");
	cout << "Hello there!! Welcome to the best bank in all of whateverThisWorldIsNamed!!\n"
		"..or ... well we are the only bank here but still!! What can we do for you?" << endl;
	while (true)
	{
		int choice;
		cout << "\n1. Deposit gold\t\t\t\tAmount of gold in bank: "<< bank.GetBankBalance() << 
		"\n2. Withdraw gold\t\t\tAdventurer gold on hand: "<< myAdventurer.GetGold() << "\n3. Leave\n-> " << endl;
		cin >> choice;
		CheckIfCinIntInput(choice);
		if (choice == 1)
		{
			cout << "How much would you like to deposit?\n-> " << endl;
			cin >> choice;
			CheckIfCinIntInput(choice);
			if (myAdventurer.GetGold() >= choice && choice > 0)
			{
				system("cls");
				myAdventurer.RemoveGold(choice);
				bank.DepositToBank(choice);
				cout << "You have deposited: " << choice << " gold to the bank." << endl;
			}
			else
			{
				system("cls");
				cout << "You aint got that amount...." << endl;
				_getch();
			}

		}
		else if (choice == 2)
		{
			cout << "How much would you like to Withdraw?\n-> " << endl;
			cin >> choice;
			CheckIfCinIntInput(choice);
			if (bank.GetBankBalance() >= choice && choice > 0)
			{
				system("cls");
				bank.WithdrawFromBank(choice);
				myAdventurer.AddGold(choice);
				cout << "You have withdrawn: " << choice << " gold to from bank." << endl;
			}
			else 
			{
				system("cls");
				cout << "You aint got that amount...." << endl;
				_getch();
			}				
		}
		else if (choice == 3) { return; }
	}
}

void OverWorldMenu(Character& myAdventurer,AllMyLists& allMyLists,Bank& bank) // Här måste jag referera (&) till orginalet av myAdventurer
{
	system("cls");
	while (true)
	{
		int choice;
		cout << "This is the Overworld menu! Enter your choice of action!\n1. Battle Monsters\n2. Show Adventurers stats\n"
			"3. Visit the church\n4. Go to the Shop\n5. Enter the bank\n-> ";
		cin >> choice;
		CheckIfCinIntInput(choice);

		if (choice == 1)
		{			
			StageBeforeBattle(myAdventurer, allMyLists); // Här har jag redan angett referensen på line 157 och behöver ej referera utan bara skriva myAdventurer
		}
		else if (choice == 2)
		{
			PrintAdventurerStats(myAdventurer);
		}
		else if (choice == 3)
		{
			VisitTheChurch(myAdventurer);
		}
		else if (choice == 4)
		{
			TheShop(myAdventurer, allMyLists);
		}
		else if (choice == 5)
		{
			TheBank(myAdventurer, bank);
		}
	}
}
int main()
{
	srand(time(NULL));
	Character myAdventurer = CreateCharacter();

	AllMyLists allMyLists = AllMyLists();
	Bank bank = Bank(0);
	myAdventurer.AddGold(200); // FIXAR LITE CASH test

	OverWorldMenu(myAdventurer, allMyLists, bank); // skickar in ORGINAL adventurer, ingen referens
}