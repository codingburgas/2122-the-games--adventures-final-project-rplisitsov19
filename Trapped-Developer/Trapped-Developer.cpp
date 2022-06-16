#include <iostream>
#include "Trapped-Developer-functions.hpp"
using namespace std;

int main()
{
	int playerHp = 25, wpnDmg;
	int act = 0, turn = 1;
	bool state = 0, choice;
	string wpnName;
	setEnemyWpn();
	
	text(act, 0); //0 = not in battle
	act++;
	next();

	while (checkHp(playerHp, wolf.hp) == 0)
	{
		stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.name, wolf.dmg); //first enemy 'Saber Wolf'
		text(act, turn);
		attack(state);
		state = !state;
		turn++;
		next();
	}
	act++;

	cin >> choice;

	if (choice)
	{
		while (checkHp(playerHp, muson.hp) == 0)
		{
			stats(playerHp, sword.dmg, sword.name, muson.hp, muson.name, muson.dmg); //second enemy B 'Muson'
			text(act, turn);
			attack(state);
			state = !state;
			turn++;
			next();
		}
		act++;
		wpnDmg = shield.dmg;
		wpnName = shield.name;
	}
	else
	{
		while (checkHp(playerHp, vent.hp) == 0)
		{
			stats(playerHp, sword.dmg, sword.name, vent.hp, vent.name, vent.dmg); //second enemy A 'Vent'
			text(act, turn);
			attack(state);
			state = !state;
			turn++;
			next();
		}
		act++;
		wpnDmg = spear.dmg;
		wpnName = spear.name;
	}

	while (checkHp(playerHp, prez.hp) == 0)
	{
		stats(playerHp, wpnDmg, wpnName, prez.hp, prez.name, prez.dmg); //boss 'The President'
		text(act, turn);
		attack(state);
		state = !state;
		turn++;
		next();
	}
	act++;

	text(act, 0);
	next();
}