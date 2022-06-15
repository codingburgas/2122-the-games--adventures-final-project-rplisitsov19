#include <iostream>
#include "Trapped-Developer-functions.hpp"
using namespace std;

int main()
{
	int playerHp = 25;
	int act = 0, turn = 1, state = 1;
	setEnemyWpn();
	
	text(act, 0); //0 = not in battle
	act++;
	next();

	while (checkHp(playerHp, wolf.hp) == 0)
	{
		stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.name, wolf.dmg); //first enemy 'Saber Wolf'
		text(act, turn);
		if (state == 1)
		{
			//attack();
			state++;
		}
		else if (state == 2)
		{
			//enemyAttack();
			state++;
		}
		else
		{
			//defend();
			state = 1;
		}
		turn++;
		next();
	}
	act++;

	while (checkHp(playerHp, vent.hp) == 0)
	{
		stats(playerHp, stick.dmg, stick.name, vent.hp, vent.name, vent.dmg); //first enemy 'Saber Wolf'
		text(act, turn);
		if (state == 1)
		{
			//attack();
			state++;
		}
		else if (state == 2)
		{
			//enemyAttack();
			state++;
		}
		else
		{
			//defend();
			state = 1;
		}
		turn++;
		next();
	}
	act++;

	while (checkHp(playerHp, muson.hp) == 0)
	{
		stats(playerHp, stick.dmg, stick.name, muson.hp, muson.name, muson.dmg); //first enemy 'Saber Wolf'
		text(act, turn);
		if (state == 1)
		{
			//attack();
			state++;
		}
		else if (state == 2)
		{
			//enemyAttack();
			state++;
		}
		else
		{
			//defend();
			state = 1;
		}
		turn++;
		next();
	}
	act++;

	while (checkHp(playerHp, prez.hp) == 0)
	{
		stats(playerHp, stick.dmg, stick.name, prez.hp, prez.name, prez.dmg); //first enemy 'Saber Wolf'
		text(act, turn);
		if (state == 1)
		{
			//attack();
			state++;
		}
		else if (state == 2)
		{
			//enemyAttack();
			state++;
		}
		else
		{
			//defend();
			state = 1;
		}
		turn++;
		next();
	}
	act++;
}