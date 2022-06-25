#include "Trapped-Developer-functions.hpp"
int main()
{
	while (true)
	{
		bool game;
		int playerHp = 25, wpnDmg;
		int act = 0, turn = 1;
		bool state = 1, choice;
		string wpnName, funcName = "";
		funcSet();
		setEnemy();

		trappedDev();
		cin >> game;
		next();

		rustGear();
		next();

		text(act, 0);
		act++;
		next();

		while (checkHp(playerHp, Wolf.hp) == 0)
		{
			stats(playerHp, stick.dmg, stick.name, Wolf.hp, Wolf.dmg, Wolf.name, act, turn, state); //first enemy 'Saber Wolf'
			text(act, turn);
			if (state)
			{
				type();
				do {
					getline(cin, funcName);
					wrongFunc(funcName);
				} while (checkFunc(funcName) > 0);
				system("CLS");
				Wolf.hp = newHp(funcName);
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
			stats(playerHp, stick.dmg, stick.name, Wolf.hp, Wolf.dmg, Wolf.name, act, turn, state);
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
				while (checkHp(playerHp, Memesoon.hp) == 0)
				{
					stats(playerHp, sword.dmg, sword.name, Memesoon.hp, Memesoon.dmg, Memesoon.name, act, turn, state); //second enemy B 'Memesoon'
					text(act, turn);
					if (state)
					{
						type();
						do {
							getline(cin, funcName);
							wrongFunc(funcName);
						} while (checkFunc(funcName) > 0);
						system("CLS");
						Memesoon.hp = newHp(funcName);
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
					stats(playerHp, sword.dmg, sword.name, Memesoon.hp, Memesoon.dmg, Memesoon.name, act, turn, state);
					text(act, 10);
					next();
					wpnDmg = shield.dmg;
					wpnName = shield.name;
				}
			}
			else
			{
				act = 3;
				while (checkHp(playerHp, Etrangere.hp) == 0)
				{
					stats(playerHp, sword.dmg, sword.name, Etrangere.hp, Etrangere.dmg, Etrangere.name, act, turn, state); //second enemy A 'Etrangere'
					text(act, turn);
					if (state)
					{
						type();
						do {
							getline(cin, funcName);
							wrongFunc(funcName);
						} while (checkFunc(funcName) > 0);
						system("CLS");
						Etrangere.hp = newHp(funcName);
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
					stats(playerHp, sword.dmg, sword.name, Etrangere.hp, Etrangere.dmg, Etrangere.name, act, turn, state);
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

			while (checkHp(playerHp, Prez.hp) == 0)
			{
				stats(playerHp, wpnDmg, wpnName, Prez.hp, Prez.dmg, Prez.name, act, turn, state); //boss 'The President'
				text(act, turn);
				if (state)
				{
					type();
					do {
						getline(cin, funcName);
						wrongFunc(funcName);
					} while (checkFunc(funcName) > 0);
					system("CLS");
					Prez.hp = newHp(funcName);
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
				stats(playerHp, wpnDmg, wpnName, Prez.hp, Prez.dmg, Prez.name, act, turn, state);
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
			//text(act, 0); //the enemy defeats the player
			//next();

			gameOver();
			next();
		}
	}
}