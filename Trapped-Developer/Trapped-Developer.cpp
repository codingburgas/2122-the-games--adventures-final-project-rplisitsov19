#include "Trapped-Developer-functions.hpp"
int main()
{
	bool game;
	int playerHp = 25, wpnDmg;
	int act = 0, turn = 1;
	bool state = 1, choice;
	string wpnName, funcName = "";
	funcSet();
	setEnemyWpn();

	while (true)
	{
		trappedDev();
		cin >> game;
		next();

		rustGear();
		next();

		text(act, 0);
		act++;
		next();

		while (checkHp(playerHp, wolf.hp) == 0)
		{
			stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.dmg, wolf.name, act, turn, state); //first enemy 'Saber Wolf'
			text(act, turn);
			if (state)
			{
				type();
				do {
					getline(cin, funcName);
					wrongFunc(funcName);
				} while (checkFunc(funcName) > 0);
				system("CLS");
				wolf.hp = newHp(funcName);
			}
			else
			{
				playerHp = newHp(funcName);
				next();
			}
			state = !state;
			turn++;			
		}

		if (checkHp(playerHp, 1) != 2)
		{
			if (!game)
			{
				playerHp = 25;
			}
			stats(playerHp, stick.dmg, stick.name, wolf.hp, wolf.dmg, wolf.name, act, turn, state);
			text(act, 10);
			turn = 1;
			state = 1;
			next();

			choose();
			cin >> choice;
			next();
			if (choice)
			{
				act = 2;
				while (checkHp(playerHp, muson.hp) == 0)
				{
					stats(playerHp, sword.dmg, sword.name, muson.hp, muson.dmg, muson.name, act, turn, state); //second enemy B 'Muson'
					text(act, turn);
					if (state)
					{
						type();
						do {
							getline(cin, funcName);
							wrongFunc(funcName);
						} while (checkFunc(funcName) > 0);
						system("CLS");
						muson.hp = newHp(funcName);
					}
					else
					{
						playerHp = newHp(funcName);
					}
					state = !state;
					turn++;
					next();
				}

				if (checkHp(playerHp, 1) != 2)
				{
					stats(playerHp, sword.dmg, sword.name, muson.hp, muson.dmg, muson.name, act, turn, state);
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
					stats(playerHp, sword.dmg, sword.name, vent.hp, vent.dmg, vent.name, act, turn, state); //second enemy A 'Vent'
					text(act, turn);
					if (state)
					{
						type();
						do {
							getline(cin, funcName);
							wrongFunc(funcName);
						} while (checkFunc(funcName) > 0);
						system("CLS");
						vent.hp = newHp(funcName);
					}
					else
					{
						playerHp = newHp(funcName);
					}
					state = !state;
					turn++;
					next();
				}

				if (checkHp(playerHp, 1) != 2)
				{
					stats(playerHp, sword.dmg, sword.name, vent.hp, vent.dmg, vent.name, act, turn, state);
					text(act, 10);
					next();
					wpnDmg = spear.dmg;
					wpnName = spear.name;
				}
			}
		}

		if (checkHp(playerHp, 1) != 2)
		{
			if (!game)
			{
				playerHp = 25;
			}
			turn = 1;
			state = 1;
			act = 4;

			while (checkHp(playerHp, prez.hp) == 0)
			{
				stats(playerHp, wpnDmg, wpnName, prez.hp, prez.dmg, prez.name, act, turn, state); //boss 'The President'
				text(act, turn);
				if (state)
				{
					type();
					do {
						getline(cin, funcName);
						wrongFunc(funcName);
					} while (checkFunc(funcName) > 0);
					system("CLS");
					prez.hp = newHp(funcName);
				}
				else
				{
					playerHp = newHp(funcName);					
				}
				state = !state;
				turn++;
				next();
			}

			if (checkHp(playerHp, 1) != 2)
			{
				stats(playerHp, wpnDmg, wpnName, prez.hp, prez.dmg, prez.name, act, turn, state);
				text(act, 10);
				next();
				act++;

				text(act, 0);
				next();
				credits();
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