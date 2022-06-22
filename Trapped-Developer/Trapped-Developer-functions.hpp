#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
using namespace std;

bool state;
int act, turn, playerHp, enemyHp, playerDmg, enemyDmg, turnDmg;
string func;
string preRow[3] = { "  __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __",
					 " |                                                                                         |",
					 " |__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|" };

struct function
{
	string name;
	bool b = 0;
}att[20];
void funcSet()
{
	att[0].name = "Hit", att[1].name = "Slash", att[2].name = "Attack", att[3].name = "Bonk", att[4].name = "Swing", att[5].name = "Charge", att[6].name = "Punch";
	att[7].name = "Kick", att[8].name = "Throw", att[9].name = "Stab", att[10].name = "Slice", att[11].name = "Cut", att[12].name = "Zandatsu", att[13].name = "Whip";
	att[14].name = "Explosion", att[15].name = "Push", att[16].name = "Thurst", att[17].name = "Spin", att[18].name = "Bolognese", att[19].name = "Slam";
}

struct weapon
{
	weapon(int dmg, string name)
	{
		weapon::dmg = dmg;
		weapon::name = name;
	}
	int dmg;
	string name;
}stick(5, "Stick"), sword(12, "Cutting edge Sword"), spear(10, "Spaghetti Spear"), shield(7, "Salvaged Shield");;
struct enemy
{
	enemy(int hp, string name)
	{		
		enemy::hp = hp;
		enemy::name = name;
	}
	int hp;
	string name;
	string wpn;
	int dmg;
}wolf(10, "Saber Wolf"), vent(20, "Vent"), muson(25, "Muson"), prez(30, "The President");
void setEnemyWpn()
{
	wolf.wpn = sword.name;
	wolf.dmg = sword.dmg;
	vent.wpn = spear.name;
	vent.dmg = spear.dmg;
	muson.wpn = shield.name;
	muson.dmg = shield.dmg;
	prez.wpn = "Nanomachines";
	prez.dmg = 6;
}

void next()
{
	cout << " ";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	system("CLS");
}

string playerStats(int hp, string wpn, int dmg, int row) //hp = health points, wpnNum = weapon number
{
	if (hp < 0)
	{
		hp = 0;
	}
	string hpText(1, char(hp) + 48);
	string dmgText(1, char(dmg) + 48);
	string space1, space2; //dmg = damage, space1 = empty space for first row
	int sp1Len = 19, sp2Len = 10; //sp1Len = amount of spaces for first

	if (wpn == "Cutting edge Sword")
	{
		sp1Len += 14;
		sp2Len += 14;
	}
	else if (wpn == "Spaghetti Spear")
	{
		sp1Len += 11;
		sp2Len += 11;
	}
	else if (wpn == "Salvaged Shield")
	{
		sp1Len += 10;
		sp2Len += 10;
	}

	switch (row)
	{
	case 1:
		for (int i = 0; i < sp1Len; i++)
		{
			space1 += ' ';
		}
		return " | Dev" + space1 + "|";
		break;
	case 2:	
		if (hp > 9)
		{
			sp2Len--;
			string hp1(1, char(hp % 10) + 48), hp2(1, char(floor(hp / 10) + 48));
			hpText = hp2 + hp1;
		}
		for (int i = 0; i < sp2Len; i++)
		{
			space2 += ' ';
		}
		return " |  Health: " + hpText + "HP"+ space2 + "|";
		break;
	case 3:
		if (dmg > 9)
		{
			string dmg1(1, char(dmg % 10) + 48), dmg2(1, char(floor(dmg / 10) + 48));
			dmgText = dmg2 + dmg1;
		}
		return " |  Weapon: " + wpn + " - " + dmgText + "DMG |";
		break;
	}
}
string enemyStats(int hp, string name, int dmg, int row)
{
	if (hp < 0)
	{
		hp = 0;
	}
	string hpText(1, char(hp) + 48);
	string dmgText(1, char(dmg) + 48);
	string space1, space2;
	int sp1Len = 1, sp2Len = 1;

	if (name == "Saber Wolf")
	{
		sp1Len += 3;
	}
	else if (name == "Vent")
	{
		sp1Len += 9;
	}
	else if (name == "Muson")
	{
		sp1Len += 8;
	}

	if (dmg > 9)
	{
		sp1Len++;
		sp2Len++;
	}

	switch (row)
	{
	case 1:
		for (int i = 0; i < sp1Len; i++)
		{
			space1 += ' ';
		}
		return "| " + name + space1 + " |";
		break;
	case 2:
		if (hp > 9)
		{
			sp2Len--;
			string hp1(1, char(hp % 10) + 48), hp2(1, char(floor(hp / 10) + 48));
			hpText = hp2 + hp1;
		}
		for (int i = 0; i < sp2Len; i++)
		{
			space2 += ' ';
		}
		return "|   Health: " + hpText + "HP" + space2 + " |";
		break;
	case 3:
		if (dmg > 9)
		{
			string dmg1(1, char(dmg % 10) + 48), dmg2(1, char(floor(dmg / 10) + 48));
			dmgText = dmg2 + dmg1;
		}
		return "|   Attack: " + dmgText + "DMG" + " |";
		break;
	}
}
string preRowFunc(int row, int len, char c, bool side)
{
	string line = "";
	for (int i = 0; i < len; i++)
	{
		line += c;
	}

	if (row == 0)
	{
		line = " " + line + " ";
	}
	else
	{
		line = "|" + line + "|";
	}

	if (side)
	{
		return " " + line;
	}
	else
	{
		return line;
	}
}
void stats(int playerhp, int wpnDmg, string wpnName, int enemyhp, int enemydmg, string enemyName)
{
	int rowLen1 = size(playerStats(playerhp, wpnName, wpnDmg, 3));
	int rowLen2 = size(enemyStats(enemyhp, enemyName, enemydmg, 3));
	int gapSpace = size(preRow[1]) - (rowLen1 + rowLen2);
	rowLen1 -= 3;
	rowLen2 -= 2;
	string gap = "";
	for (int i = 0; i < gapSpace; i++)
	{
		gap += ' ';
	}

	cout << preRowFunc(0, rowLen1, '_', 1) << gap << preRowFunc(0, rowLen2, '_', 0) << endl;
	cout << preRowFunc(1, rowLen1, ' ', 1) << gap << preRowFunc(1, rowLen2, ' ', 0) << endl;
	cout << playerStats(playerhp, wpnName, wpnDmg, 1) << gap << enemyStats(enemyhp, enemyName, enemydmg, 1) << endl;
	cout << playerStats(playerhp, wpnName, wpnDmg, 2) << gap << enemyStats(enemyhp, enemyName, enemydmg, 2) << endl;
	cout << playerStats(playerhp, wpnName, wpnDmg, 3) << gap << enemyStats(enemyhp, enemyName, enemydmg, 3) << endl;
	cout << preRowFunc(2, rowLen1, '_', 1) << gap << preRowFunc(2, rowLen2, '_', 0) << endl;
}

void text(int actMain, int turnMain)
{
	act = actMain;
	turn = turnMain;

	cout << preRow[0] << endl << preRow[1] << endl;
	switch (act)
	{
	case 0:
		cout << " |  Dev: *yawns* Where am I? It's so dark in here. Hey I can see what I'm saying as text.  |\n";
		cout << " |     Why is it in this font? This is very weird. The last thing I remember is...         |\n";
		cout << " |     *scratces head* falling asleep in front of my computer screen. I must've gotten     |\n";
		cout << " |     tired after all that programming. And what is this thing stuck on my belt?          |\n";
		cout << " |                          CONGRATULATIONS! YOU FOUND A 'Stick'!                          |\n";
		cout << " |  Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name  |\n";
		cout << " |     infront of everything I say is 'Dev'. Is that short for 'Developer'? Am I in my     |\n";
		cout << " |     own game!? Does that mean I will have to fight against...                           |\n";
		break;
	case 1:
		switch (turn)
		{
		case 0:
			//finishing blow, you managed to defeat the enemy
			break;

		case 1:
			//oh no it's a monster you have to attack
			break;

		case 2:

			break;

		default:

			break;
		}
	case 2:

		switch (turn)
		{
		case 0:
			//finishing blow, you managed to defeat the enemy
			break;

		case 1:
			//oh no it's a monster you have to attack
			break;

		case 2:

			break;

		default:

			break;
		}
	case 3:
		switch (turn)
		{
		case 0:
			//finishing blow, you managed to defeat the enemy
			break;

		case 1:
			//oh no it's a monster you have to attack
			break;

		case 2:

			break;

		default:

			break;
		}
	case 4:
		switch (turn)
		{
		case 0:
			//finishing blow, you managed to defeat the enemy
			break;

		case 1:
			//oh no it's a monster you have to attack
			break;

		case 2:

			break;

		default:

			break;
		}
	case 5:
		//epilogue
		break;
	}
	cout << preRow[2] << endl;
}

int checkHp(int player, int enemyhp)
{
	if (enemyhp <= 0)
	{
		return 1;
	}
	else if (player <= 0)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

bool andIf(int actFunc)
{
	if ((state && act == actFunc) || state == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkFunc(string funcMain)
{
	for (int i = 0; i < 20; i++)
	{
		if (att[i].name == funcMain)
		{
			return att[i].b;
			break;
		}
		else if (i == 19)
		{
			return 2;
		}
	}
}
int funcExe()
{
	int bonusDmg = 0;
	int entityDmg = 0;
	if (state)
	{
		entityDmg = playerDmg;
	}
	else
	{
		entityDmg = enemyDmg;
	}

	if (func == "Hit" || func == "Slash" || func == "Attack" || func == "Bonk" || func == "Swing")
	{
		if (state && func == "Hit")
		{
			att[0].b++;
		}
		else if (state && func == "Slash")
		{
			att[1].b++;
		}
		else if (state && func == "Attack")
		{
			att[2].b++;
		}
		else if (state && func == "Bonk")
		{
			att[3].b++;
		}
		else if (state && func == "Swing")
		{
			att[4].b++;
		}
		turnDmg = entityDmg;
	}
	else if (func == "Charge" || func == "Punch")
	{
		if (state && func == "Charge")
		{
			att[5].b++;
		}
		else if (state && func == "Punch")
		{
			att[6].b++;
		}
		turnDmg = 9;
	}
	else if (func == "Kick")
	{
		if (state)
		{
			att[7].b++;
		}
		turnDmg = 10;
	}
	else if (func == "Throw" && (andIf(1) || andIf(4)))
	{
		if (state)
		{
			att[8].b++;
		}
		turnDmg = 2 * entityDmg;
	}
	else if (func == "Stab" && (andIf(1) || andIf(2) || andIf(3) || playerDmg == 10))
	{		
		if (andIf(1))
		{
			bonusDmg = 2;
		}
		else if (playerDmg == 15 || enemyDmg == 15)
		{
			bonusDmg = -5;
		}
		else if (playerDmg == 10 || enemyDmg == 10)
		{
			bonusDmg = 5;
		}

		if (state)
		{
			att[9].b++;
		}
		turnDmg = entityDmg + bonusDmg;
	}
	else if ((func == "Slice" || func == "Cut") && (andIf(2) || andIf(3)))
	{
		if (state && func == "Slice")
		{
			att[10].b++;
		}
		else if (state && func == "Cut")
		{
			att[11].b++;
		}
		turnDmg = entityDmg + 2;
	}
	else if (func == "Zandatsu" && (andIf(2) || andIf(3)))
	{
		turnDmg = 100;
	}
	else if (func == "Whip" && (playerDmg == 10 || enemyDmg == 10))
	{
		if (state)
		{
			att[13].b++;
		}
		turnDmg = entityDmg + 7;
	}
	else if ((func == "I am fucking invincible" || func == "I'm fucking invincible") && playerDmg == 7)
	{
		turnDmg = 100;
	}
	else if ((func == "Push" || func == "Thrust") && (playerDmg == 7 || enemyDmg == 7))
	{
		if (state && func == "Push")
		{
			att[15].b++;
		}
		else if (state && func == "Thrust")
		{
			att[16].b++;
		}
		turnDmg = entityDmg * 2;
	}
	else if ((func == "Spin" || func == "Spin Attack") && (playerDmg == 15 || enemyDmg == 15))
	{
		if (state)
		{
			att[17].b++;
		}
		turnDmg = entityDmg * 2;
	}
	else if (func == "Spaghetti Bolognese" && playerDmg == 10)
	{
		if (state)
		{
			att[18].b++;
		}
		turnDmg = 100;
	}
	else if (func == "Slam" && (playerDmg == 7 || enemyDmg == 7))
	{
		if (state)
		{
			att[19].b++;
		}
		turnDmg = entityDmg + 4;
	}

	return turnDmg;
}
int enemyAttack()
{
	switch (act)
	{
	case 1:
		switch (turn)
		{
		case 1:
			func = "Hit";
			return funcExe();
			break;
		case 2:
			func = "Slash";
			return funcExe();
			break;
		case 3:
			func = "Cut";
			return funcExe();
			break;
		}
	case 2:
		switch (turn)
		{
		case 1:
			func = "Slash";
			return funcExe();
			break;
		case 2:
			func = "Slam";
			return funcExe();
			break;
		case 3:
			func = "Slam";
			return funcExe();
			break;
		}
	case 3:
		switch (turn)
		{
		case 1:
			func = "Slash";
			return funcExe();
			break;
		case 2:
			func = "Stab";
			return funcExe();
			break;
		case 3:
			func = "Stab";
			return funcExe();
			break;
		}
	case 4:
		switch (turn)
		{
		case 1:
			func = "Punch";
			return funcExe();
			break;
		case 2:
			func = "Kick";
			return funcExe();
			break;
		case 3:
			func = "Bonk";
			return funcExe();
			break;
		}
	}
}
int damage(bool stateMain, string funcMain, int playerHpMain, int enemyHpMain, int playerDmgMain, int enemyDmgMain, int actMain, int turnMain)
{
	state = stateMain;
	func = funcMain;
	playerDmg = playerDmgMain;
	enemyDmg = enemyDmgMain;
	playerHp = playerHpMain;
	enemyHp = enemyHpMain;
	act = actMain;
	turn = turnMain;

	if (state)
	{
		return enemyHp - funcExe();
	}
	else
	{
		return playerHp - enemyAttack();
	}
}

void type()
{
	cout << "\n *type a function to attack, start each word (if multiple) with a capital letter* \n ";
}
void wrongFunc(string funcName)
{
	if (checkFunc(funcName) == 2)
	{
		cout << " This is an illogical function! I have to type a logical one. ";
	}
	else if (checkFunc(funcName) == 1)
	{
		cout << " I have already used this function and I can't use it again! I have to think of another function.\n  *some functions have more than one name* ";
	}
}

void funcThrow()
{

}

void gameOver()
{
	cout << preRow[0] << endl << preRow[1] << endl << preRow[1] << endl;
	cout << " |                                        GAME OVER                                        |\n";
	cout << preRow[1] << endl << preRow[2] << endl;
}