#include <iostream>
#include <cstdlib>
#include "Trapped-Developer-functions.hpp"
using namespace std;

int main()
{
	int game;
	int playerHp = 25, wpnDmg;
	int act = 0, turn = 1;
	bool state = 1, choice;
	string wpnName, funcName = "";
	funcSet();
	setEnemyWpn();

	while (true)
	{
		cin >> game;
		next();

		text(act, 0);
		act++;
		next();

		while (checkHp(playerHp, wolf.hp) == 0)
		{
			stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.dmg, wolf.name); //first enemy 'Saber Wolf'
			text(act, turn);
			if (state)
			{
				type();
				do {
					cin >> funcName;
					wrongFunc(funcName);
				} while (checkFunc(funcName) > 0);
				system("CLS");
				wolf.hp = damage(1, funcName, playerHp, wolf.hp, stick.dmg, wolf.dmg, act, turn, wolf.name);
			}
			else
			{
				playerHp = damage(0, funcName, playerHp, wolf.hp, stick.dmg, wolf.dmg, act, turn, wolf.name);
			}
			state = !state;
			turn++;
			next();
		}

		if (checkHp(playerHp, 1) != 2)
		{
			stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.dmg, wolf.name);
			text(act, 10);
			next();
			turn = 1;
			state = 1;

			cin >> choice;
			next();
			if (choice)
			{
				act = 2;
				while (checkHp(playerHp, muson.hp) == 0)
				{
					stats(playerHp, sword.dmg, sword.name, muson.hp, muson.dmg, muson.name); //second enemy B 'Muson'
					text(act, turn);
					if (state)
					{
						type();
						do {
							cin >> funcName;
							wrongFunc(funcName);
						} while (checkFunc(funcName) > 0);
						system("CLS");
						muson.hp = damage(1, funcName, playerHp, muson.hp, sword.dmg, muson.dmg, act, turn, muson.name);
					}
					else
					{
						playerHp = damage(0, funcName, playerHp, muson.hp, sword.dmg, muson.dmg, act, turn, muson.name);
					}
					state = !state;
					turn++;
					next();
				}

				if (checkHp(playerHp, 1) != 2)
				{
					stats(playerHp, sword.dmg, sword.name, muson.hp, muson.dmg, muson.name);
					text(act, 10);
					next();
					wpnDmg = shield.dmg;
					wpnName = shield.name;
				}
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
						type();
						do {
							cin >> funcName;
							wrongFunc(funcName);
						} while (checkFunc(funcName) > 0);
						system("CLS");
						vent.hp = damage(1, funcName, playerHp, vent.hp, sword.dmg, vent.dmg, act, turn, vent.name);
					}
					else
					{
						playerHp = damage(0, funcName, playerHp, vent.hp, sword.dmg, vent.dmg, act, turn, vent.name);
					}
					state = !state;
					turn++;
					next();
				}

				if (checkHp(playerHp, 1) != 2)
				{
					stats(playerHp, sword.dmg, sword.name, vent.hp, vent.dmg, vent.name);
					text(act, 10);
					next();
					wpnDmg = spear.dmg;
					wpnName = spear.name;
				}
			}
		}

		if (checkHp(playerHp, 1) != 2)
		{
			turn = 1;
			state = 1;
			act = 4;

			while (checkHp(playerHp, prez.hp) == 0)
			{
				stats(playerHp, wpnDmg, wpnName, prez.hp, prez.dmg, prez.name); //boss 'The President'
				text(act, turn);
				if (state)
				{
					type();
					do {
						cin >> funcName;
						wrongFunc(funcName);
					} while (checkFunc(funcName) > 0);
					system("CLS");
					prez.hp = damage(1, funcName, playerHp, prez.hp, wpnDmg, prez.dmg, act, turn, prez.name);
				}
				else
				{
					playerHp = damage(0, funcName, playerHp, prez.hp, wpnDmg, prez.dmg, act, turn, prez.name);					
				}
				state = !state;
				turn++;
				next();
			}

			if (checkHp(playerHp, 1) != 2)
			{
				stats(playerHp, wpnDmg, wpnName, prez.hp, prez.dmg, prez.name);
				text(act, 10);
				next();
				act++;

				text(act, 0);
				next();
			}
		}

		if (checkHp(playerHp, 1) == 2)
		{
			text(act, 0); //the enemy defeats the player
			next();

			gameOver();
			next();
		}
	}
}