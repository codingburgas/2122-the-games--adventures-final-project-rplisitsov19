#include <iostream>
#include "Trapped-Developer-functions.hpp"
using namespace std;

int main()
{
	int playerHp = 25, wpnDmg;
	int act = 0, turn = 1;
	bool state = 1, choice;
	string wpnName, funcName = "";
	setEnemyWpn();
	
	text(act, 0); //0 = not in battle
	act++;
	next();

	while (checkHp(playerHp, wolf.hp) == 0)
	{
		stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.dmg, wolf.name); //first enemy 'Saber Wolf'
		text(act, turn);
		if (state)
		{
			cin >> funcName;
			wolf.hp = attack(1, funcName, playerHp, wolf.hp, stick.dmg, wolf.dmg);
		}
		else
		{
			playerHp = attack(0, funcName, playerHp, wolf.hp, stick.dmg, wolf.dmg);
		}
		state = !state;
		turn++;
		next();
	}
	stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.dmg, wolf.name);
	text(act, 0);
	next();
	turn = 1;
	state = 1;

	cin >> choice;

	if (choice)
	{
		act = 2;
		while (checkHp(playerHp, muson.hp) == 0)
		{
			stats(playerHp, sword.dmg, sword.name, muson.hp, muson.dmg, muson.name); //second enemy B 'Muson'
			text(act, turn);
			if (state)
			{
				cin >> funcName;
				muson.hp = attack(1, funcName, playerHp, muson.hp, sword.dmg, muson.dmg);
			}
			else
			{
				playerHp = attack(0, funcName, playerHp, muson.hp, sword.dmg, muson.dmg);
			}
			state = !state;
			turn++;
			next();
		}
		stats(playerHp, sword.dmg, sword.name, muson.hp, muson.dmg, muson.name);
		text(act, 0);
		wpnDmg = shield.dmg;
		wpnName = shield.name;
	}
	else
	{
		act = 3;
		while (checkHp(playerHp, vent.hp) == 0)
		{
			stats(playerHp, sword.dmg, sword.name, vent.hp, vent.dmg, vent.name); //second enemy A 'Vent'
			text(act, turn);
			if (state)
			{
				cin >> funcName;
				vent.hp = attack(1, funcName, playerHp, vent.hp, sword.dmg, vent.dmg);
			}
			else
			{
				playerHp = attack(0, funcName, playerHp, vent.hp, sword.dmg, vent.dmg);
			}
			state = !state;
			turn++;
			next();
		}
		stats(playerHp, sword.dmg, sword.name, vent.hp, vent.dmg, vent.name);
		text(act, 0);
		wpnDmg = spear.dmg;
		wpnName = spear.name;
	}
	next();
	turn = 1;
	state = 1;
	act = 4;

	while (checkHp(playerHp, prez.hp) == 0)
	{
		stats(playerHp, wpnDmg, wpnName, prez.hp, prez.dmg, prez.name); //boss 'The President'
		text(act, turn);
		if (state)
		{
			cin >> funcName;
			prez.hp = attack(1, funcName, playerHp, prez.hp, wpnDmg, prez.dmg);
		}
		else
		{
			playerHp = attack(0, funcName, playerHp, prez.hp, wpnDmg, prez.dmg);
		}
		state = !state;
		turn++;
		next();
	}
	stats(playerHp, wpnDmg, wpnName, prez.hp, prez.dmg, prez.name);
	text(act, 0);
	next();
	act++;

	text(act, 0);
	next();
}