#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
using namespace std;

bool state;
int act, turn, playerHp, enemyHp, playerDmg, enemyDmg, turnDmg;
string func = "", enemyN = "", rowAttack = "";
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
}wolf(15, "Saber Wolf"), vent(20, "Vent"), muson(25, "Muson"), prez(30, "The President");
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
		return " |  Health: " + hpText + "HP" + space2 + "|";
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
	int rowLen = rowLen1 + rowLen2;
	int gapSpace = size(preRow[1]) - rowLen;
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

string empty()
{
	return "\n\n\n\n\n\n";
}
string spaceFunc(string textRow)
{
	string output;
	for (int i = 0; i < size(preRow[1]) - size(textRow) - 1; i++)
	{
		output += " ";
	}
	output += "|\n";
	return output;
}
string textAttack()
{
	string dmgText(1, char(turnDmg) + 48);
	string part;

	if (turnDmg > 9)
	{
		string dmg1(1, char(turnDmg % 10) + 48), dmg2(1, char(floor(turnDmg / 10) + 48));
		dmgText = dmg2 + dmg1;
	}

	if (turn % 2 == 0)
	{
		part = " | DEV USED '";
	}
	else
	{
		part = " | THE ENEMY USED '";
	}
	part = part + func + "' FOR " + dmgText + " DAMAGE.";
	return part + spaceFunc(part);
}
void text(int actMain, int turnMain)
{
	act = actMain;
	turn = turnMain;

	if (turn == 0)
	{
		cout << empty();
	}
	cout << preRow[0] << endl << preRow[1] << endl;
	switch (act)
	{
	case 0:
		cout << " |  Dev: *yawns* Where am I? It seems I am on some kind of rope bridge Hey I can see what  |\n";
		cout << " |     I'm saying as text. Why is it in this font? This is very weird. The last thing      |\n";
		cout << " |     I remember is... *scratces head* falling asleep in front of my computer screen.     |\n";
		cout << " |     I must've gotten tired after all that programming. And what is this thing stuck     |\n";
		cout << " |     to my belt?                                                                         |\n";
		cout << " | CONGRATULATIONS! YOU FOUND A 'Stick'!                                                   |\n";
		cout << " |  Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name  |\n";
		cout << " |     infront of everything I say is 'Dev'. Is that short for 'Developer'? Am I in my     |\n";
		cout << " |     own game!? Does that mean I will have to fight against...                           |\n";
		break;
	case 1:
		if (turn == 0)
		{
			//the enemy defeated you + finishing blow
		}
		else if (turn == 10)
		{
			//you managed to defeat the enemy + finishing blow
		}
		else if (turn == 1)
		{
			//oh no it's a monster you have to attack
		}
		else if (turn % 2 == 0)
		{
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				rowAttack = " |  Saber Wolf: I will show you what superior intelligence can do!";
				break;
			case 2:
				rowAttack = " |  Saber Wolf: Someone on your intelligence level can never do anything to me!";
				break;
			case 3:
				rowAttack = " |  Saber Wolf: This is it for you, monkey!";
				break;
			}
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		break;
	case 2:
		if (turn == 0)
		{
			//the enemy defeated you + finishing blow
		}
		else if (turn == 10)
		{
			//you managed to defeat the enemy + finishing blow
		}
		else if (turn == 1)
		{
			//oh no it's a monster you have to attack
		}
		else if (turn % 2 == 0)
		{
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				rowAttack = " |  This world and all its living people are memes, something you won't be soon!";
				break;
			case 2:
				rowAttack = " |  Free will is the ability to create memes, so take this meme to your grave!";
				break;
			case 3:
				rowAttack = " |  Too bad you'll die before passing down any memes.";
				break;
			}
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		break;
	case 3:
		if (turn == 0)
		{
			//the enemy defeated you + finishing blow
		}
		else if (turn == 10)
		{
			//you managed to defeat the enemy + finishing blow
		}
		else if (turn == 1)
		{
			//oh no it's a monster you have to attack
		}
		else if (turn % 2 == 0)
		{
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				rowAttack = " |  Come, le mec!";
				break;
			case 2:
				rowAttack = " |  I will tear you apart!";
				break;
			case 3:
				rowAttack = " |  Good night!";
				break;
			}
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		break;
	case 4:
		if (turn == 0)
		{
			//the enemy defeated you + finishing blow
		}
		else if (turn == 10)
		{
			//you managed to defeat the enemy + finishing blow
		}
		else if (turn == 1)
		{
			//oh no it's a monster you have to attack
		}
		else if (turn % 2 == 0)
		{
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				rowAttack = " |  Played college ball, ya know";
				break;
			case 2:
				rowAttack = " |  Don't mess with this president!";
				break;
			case 3:
				rowAttack = " |  Taste the power of nanomachines!";
				break;
			}
			cout << rowAttack << spaceFunc(rowAttack) << textAttack();
		}
		break;
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
		rowAttack = " |  Dev: Take this!";
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
		rowAttack = " |  Dev: I don't want to hurt you!";
		turnDmg = 9;
	}
	else if (func == "Kick")
	{
		if (state)
		{
			att[7].b++;
			rowAttack = " |  Dev: *kiai*";
		}		
		turnDmg = 10;
	}
	else if (func == "Throw" && (andIf(1) || andIf(4)))
	{
		if (state)
		{
			att[8].b++;
			rowAttack = " |  Dev: Snipe!";
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
			rowAttack = " |  Dev: *poke*";
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
		rowAttack = " |  Dev: Slice and dice!";
		turnDmg = entityDmg + 2;
	}
	else if (func == "Zandatsu" && (andIf(2) || andIf(3)))
	{
		rowAttack = " |  Dev: I think it's time for Jack to let 'er rip!";
		turnDmg = 100;
	}
	else if (func == "Whip" && (playerDmg == 10 || enemyDmg == 10))
	{
		if (state)
		{
			att[13].b++;
			rowAttack = " |  Dev: Die!";
		}
		turnDmg = entityDmg + 7;
	}
	else if ((func == "I am fucking invincible" || func == "I'm fucking invincible") && playerDmg == 7)
	{
		func = "Explosion";
		rowAttack = " |  Dev: I'm fucking invincible!";
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
		rowAttack = " |  Dev: Dodge this!";
		turnDmg = entityDmg * 2;
	}
	else if ((func == "Spin" || func == "Spin Attack") && (playerDmg == 15 || enemyDmg == 15))
	{
		if (state)
		{
			att[17].b++;
			rowAttack = " |  Dev: Beyblade time!";
		}
		turnDmg = entityDmg * 2;
	}
	else if (func == "Spaghetti Bolognese" && playerDmg == 10)
	{
		if (state)
		{
			att[18].b++;
			rowAttack = " |  Dev: I'm going to turn you into human spaghetti bolognese!";
		}
		turnDmg = 100;
	}
	else if (func == "Slam" && (playerDmg == 7 || enemyDmg == 7))
	{
		if (state)
		{
			att[19].b++;
			rowAttack = " |  Dev: AoE for the win!";
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
int damage(bool stateMain, string funcMain, int playerHpMain, int enemyHpMain, int playerDmgMain, int enemyDmgMain, int actMain, int turnMain, string enemyNameMain)
{
	state = stateMain;
	func = funcMain;
	playerDmg = playerDmgMain;
	enemyDmg = enemyDmgMain;
	playerHp = playerHpMain;
	enemyHp = enemyHpMain;
	act = actMain;
	turn = turnMain;
	enemyN = enemyNameMain;

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

void gameOver()
{
	cout << empty() << preRow[0] << endl;
	cout << " |              _____   ___    __  ___   ____       ____   _   __   ____   ___             |\n";
	cout << " |             / ___/  / _ |  /  |/  /  / __/      / __ \\ | | / /  / __/  / _ \\            |\n";
	cout << " |            / (_ /  / __ | / /|_/ /  / _/       / /_/ / | |/ /  / _/   / , _/            |\n";
	cout << " |            \\___/  /_/ |_|/_/  /_/  /___/       \\____/  |___/  /___/  /_/|_|             |\n";
	cout << preRow[2] << endl;
}