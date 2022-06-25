#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
using namespace std;

bool state;
int act, turn, playerHp, enemyHp, playerDmg, enemyDmg, turnDmg;
string func = "", enemyName = "", textRow = "";
string preRow[3] = { "  __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __",
					 " |                                                                                         |",
					 " |__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|" };

struct function
{
	string name;
	bool b = 0;
	int wpn[4] = { 0, 0, 0, 0 };
}att[20];
void funcSet()
{
	att[0].name = "Hit", att[1].name = "Slash", att[2].name = "Attack", att[3].name = "Bonk", att[4].name = "Swing", att[5].name = "Charge", att[6].name = "Punch";
	att[7].name = "Kick", att[8].name = "Throw", att[9].name = "Stab", att[10].name = "Slice", att[11].name = "Cut", att[12].name = "Zandatsu", att[13].name = "Whip";
	att[14].name = "I'm fucking invincible!", att[15].name = "Push", att[16].name = "Thurst", att[17].name = "Spin", att[18].name = "Bolognese", att[19].name = "Slam";
	for (int i = 0; i < 8; i++)
	{
		att[i].wpn[0] = 5, att[i].wpn[1] = 12, att[i].wpn[2] = 10, att[i].wpn[3] = 7;
	}
	att[8].wpn[0] = 5, att[8].wpn[1] = 10;
	att[9].wpn[0] = 5, att[9].wpn[1] = 10, att[9].wpn[2] = 12;
	att[10].wpn[0] = 12, att[11].wpn[0] = 12, att[12].wpn[0] = 12, att[17].wpn[0] = 12;
	att[13].wpn[0] = 10, att[18].wpn[0] = 10;
	att[14].wpn[0] = 7, att[15].wpn[0] = 7, att[16].wpn[0] = 7, att[19].wpn[0] = 7;
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
}Wolf(15, "Saber Wolf"), Etrangere(20, "Etrangere"), Memesoon(25, "Memesoon"), Prez(30, "The President");
void setEnemyWpn()
{
	Wolf.wpn = sword.name;
	Wolf.dmg = sword.dmg;
	Etrangere.wpn = spear.name;
	Etrangere.dmg = spear.dmg;
	Memesoon.wpn = shield.name;
	Memesoon.dmg = shield.dmg;
	Prez.wpn = "Nanomachines";
	Prez.dmg = 6;
}

void next()
{
	cout << " ";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	system("CLS");
}

int hp0(int hp)
{
	if (hp <= 0)
	{
		return 0;
	}
	else
	{
		return hp;
	}
}
string playerStats(int hp, string wpn, int dmg, int row) //hp = health points, wpnNum = weapon number
{
	hp = hp0(hp);
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
	hp = hp0(hp);
	string hpText(1, char(hp) + 48);
	string dmgText(1, char(dmg) + 48);
	string space1, space2, wpn, part;
	int sp1Len, sp2Len;

	if (name == "Saber Wolf")
	{
		wpn = Wolf.wpn;
	}
	else if (name == "Etrangere")
	{
		wpn = Etrangere.wpn;
	}
	else if (name == "Memesoon")
	{
		wpn = Memesoon.wpn;
	}
	else
	{
		wpn = Prez.wpn;
	}

	switch (row)
	{
	case 1:
		part = "| " + name;
		sp1Len = (size(enemyStats(hp, name, dmg, 3)) - size(part) - 2);
		for (int i = 0; i < sp1Len; i++)
		{
			space1 += ' ';
		}
		return part + space1 + " |";
		break;
	case 2:
		if (hp > 9)
		{
			string hp1(1, char(hp % 10) + 48), hp2(1, char(floor(hp / 10) + 48));
			hpText = hp2 + hp1;
		}		
		part = "|  Health: " + hpText + "HP";
		sp2Len = (size(enemyStats(hp, name, dmg, 3)) - size(part) - 2);
		for (int i = 0; i < sp2Len; i++)
		{
			space2 += ' ';
		}
		return part + space2 + " |";
		break;
	case 3:
		if (dmg > 9)
		{
			string dmg1(1, char(dmg % 10) + 48), dmg2(1, char(floor(dmg / 10) + 48));
			dmgText = dmg2 + dmg1;
		}
		return "|  Weapon: " + wpn + " - " + dmgText + "DMG" + " |";
		break;
	}
}
string preRowFunc(int row, int len, bool side)
{
	string line = "";
	for (int i = 0; i < len; i++)
	{
		line += "_";
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
void stats(int playerHpMain, int playerDmgMain, string wpnName, int enemyHpMain, int enemyDmgMain, string enemyNameMain, int actMain, int turnMain, bool stateMain)
{
	playerDmg = playerDmgMain;
	enemyDmg = enemyDmgMain;
	playerHp = playerHpMain;
	enemyHp = enemyHpMain;
	act = actMain;
	turn = turnMain;
	enemyName = enemyNameMain;
	state = stateMain;

	int rowLen1 = size(playerStats(playerHp, wpnName, playerDmg, 3));
	int rowLen2 = size(enemyStats(enemyHp, enemyName, enemyDmg, 3));
	int rowLen = rowLen1 + rowLen2;
	int gapSpace = size(preRow[1]) - rowLen;
	rowLen1 -= 3;
	rowLen2 -= 2;
	string gap = "";
	for (int i = 0; i < gapSpace; i++)
	{
		gap += ' ';
	}

	cout << preRowFunc(0, rowLen1, 1) << gap << preRowFunc(0, rowLen2, 0) << endl;
	cout << playerStats(playerHp, wpnName, playerDmg, 1) << gap << enemyStats(enemyHp, enemyName, enemyDmg, 1) << endl;
	cout << playerStats(playerHp, wpnName, playerDmg, 2) << gap << enemyStats(enemyHp, enemyName, enemyDmg, 2) << endl;
	cout << playerStats(playerHp, wpnName, playerDmg, 3) << gap << enemyStats(enemyHp, enemyName, enemyDmg, 3) << endl;
	cout << preRowFunc(2, rowLen1, 1) << gap << preRowFunc(2, rowLen2, 0) << endl;
}

string empty()
{
	return "\n\n\n\n\n\n";
}
string spaceFunc(string row)
{
	string output;
	for (int i = 1; i <= size(preRow[1]) - size(row) - 1; i++)
	{
		output += " ";
	}
	output += "|\n";
	return output;
}
string textAttack()
{
	string dmgText(1, char(turnDmg) + 48);
	string part, part2, hp;
	if (turnDmg > 9)
	{
		string dmg1(1, char(turnDmg % 10) + 48), dmg2(1, char(floor(turnDmg / 10) + 48));
		dmgText = dmg2 + dmg1;
	}

	if (turn % 2 == 0)
	{
		part = " |  THE PLAYER USED '";
		string hp3(1, char(hp0(enemyHp)) + 48);
		if (enemyHp > 9)
		{
			string hp1(1, char(enemyHp % 10) + 48), hp2(1, char(floor(enemyHp / 10) + 48));
			hp3 = hp2 + hp1;
		}
		hp = hp3;
		part2 = " |  THE ENEMY'S HEALTH DROPPED DOWN TO ";
	}
	else
	{
		part = " |  THE ENEMY USED '";
		string hp3(1, char(hp0(playerHp)) + 48);
		if (playerHp > 9)
		{
			string hp1(1, char(playerHp % 10) + 48), hp2(1, char(floor(playerHp / 10) + 48));
			hp3 = hp2 + hp1;
		}
		hp = hp3;
		part2 = " |  THE PLAYER'S HEALTH DROPPED DOWN TO ";
	}
	part = part + func + "' FOR " + dmgText + " DAMAGE.";
	part2 = part2 + hp + "HP.";
	return preRow[1] + "\n" + part + spaceFunc(part) + preRow[1] + "\n" + part2 + spaceFunc(part2);
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
		cout << " | Dev: *yawns* Where am I? It seems I am on some kind of a rope bridge. Hey I can see what|\n";
		cout << " |      I'm saying as text. Why is it in this font? This is very weird. The last thing     |\n";
		cout << " |      I remember is... *scratces head* falling asleep in front of my computer screen.    |\n";
		cout << " |      I must've gotten tired after all that programming. And what is this thing stuck    |\n";
		cout << " |      to my belt?                                                                        |\n";
		cout << preRow[1] << endl;
		cout << " |  CONGRATULATIONS! YOU FOUND A 'Stick'!                                                  |\n";
		cout << preRow[1] << endl;
		cout << " | Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name   |\n";
		cout << " |      infront of everything I say is 'Dev'. Is that short for 'Developer'? Am I in my    |\n";
		cout << " |      own game!? Does that mean I will have to fight against...                          |\n";
		break;
	case 1:
		if (turn == 0)
		{
			textRow = " | Saber Wolf: Typical human, dissapointing.";
			cout << preRow[1] << endl << textRow << spaceFunc(textRow);
		}
		else if (turn == 10)
		{
			cout << textRow << spaceFunc(textRow) << textAttack() << preRow[1] << endl;
			textRow = " | Saber Wolf: Cannot... proceed...";
			cout << textRow << spaceFunc(textRow) << preRow[1] << endl;
			textRow = " |  CONGRATULATIONS! YOU DEFEATED 'Saber Wolf'!";
			cout << textRow << spaceFunc(textRow) << preRow[1] << endl;
			textRow = " |  CONGRATULATIONS! YOU FOUND 'Cutting edge Sword' IN ITS BLOODY CORPSE!";
			cout << textRow << spaceFunc(textRow) << preRow[1] << endl;
		}
		else if (turn == 1)
		{
			textRow = " | Dev: ... Saber Wolf!";
			cout << textRow << spaceFunc(textRow);
			textRow = " | Saber Wolf: Greetings, human. I am bionical IF prototype IQ-184i.";
			cout << textRow << spaceFunc(textRow);
			textRow = " |             I possess IQ far beyond that of a human.";
			cout << textRow << spaceFunc(textRow);
			textRow = " | Dev: If you're so smart then: What's the meaning of life?";
			cout << textRow << spaceFunc(textRow);
			textRow = " | Saber Wolf: I am here to kill you, not to make small talk.";
			cout << textRow << spaceFunc(textRow);
		}
		else if (turn % 2 == 0)
		{
			cout << textRow << spaceFunc(textRow) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				textRow = " | Saber Wolf: I will show you what superior intelligence can do!";
				break;
			case 2:
				textRow = " | Saber Wolf: Exterminate!";
				break;
			case 3:
				textRow = " | Saber Wolf: Someone on your intelligence level can never do anything to me!";
				break;
			case 4:
				textRow = " | Saber Wolf: This is it for you, monkey!";
				break;
			}
			cout << textRow << spaceFunc(textRow) << textAttack();
		}
		break;
	case 2:
		if (turn == 0)
		{
			textRow = " | Memesoon: Too bad you'll die before passing down any memes.";
			cout << textRow << spaceFunc(textRow);
		}
		else if (turn == 10)
		{
			cout << textRow << spaceFunc(textRow) << textAttack() << preRow[1] << endl;
			textRow = " | Memesoon: At least I passed down my memes to you...";
			cout << textRow << spaceFunc(textRow);
			textRow = " | Dev: Yeah, yeah, I know, order of the universe and all that.";
			cout << textRow << spaceFunc(textRow);
		}
		else if (turn == 1)
		{
			//oh no it's a monster you have to attack
		}
		else if (turn % 2 == 0)
		{
			cout << textRow << spaceFunc(textRow) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				textRow = " | Memesoon: This world and all its living people are memes, something you won't be soon!";
				break;
			case 2:
				textRow = " | Memesoon: Free will is the ability to create memes, so take this meme to your grave!";
				break;
			case 3:
				textRow = " | Memesoon: ";
				break;
			}
			cout << textRow << spaceFunc(textRow) << textAttack();
		}
		break;
	case 3:
if (turn == 0)
{
	//the enemy defeated you + finishing blow
}
else if (turn == 10)
{
	cout << textRow << spaceFunc(textRow) << textAttack() << preRow[1] << endl;
	//you managed to defeat the enemy + finishing blow
}
else if (turn == 1)
{
	//oh no it's a monster you have to attack
}
else if (turn % 2 == 0)
{
	cout << textRow << spaceFunc(textRow) << textAttack();
}
else
{
	switch (turn / 2)
	{
	case 1:
		textRow = " | Come, le mec!";
		break;
	case 2:
		textRow = " | I will tear you apart!";
		break;
	case 3:
		textRow = " | Good night!";
		break;
	}
	cout << textRow << spaceFunc(textRow) << textAttack();
}
break;
	case 4:
		if (turn == 0)
		{
			//the enemy defeated you + finishing blow
		}
		else if (turn == 10)
		{
			cout << textRow << spaceFunc(textRow) << textAttack() << preRow[1] << endl;
			//you managed to defeat the enemy + finishing blow
		}
		else if (turn == 1)
		{
			//oh no it's a monster you have to attack
		}
		else if (turn % 2 == 0)
		{
			cout << textRow << spaceFunc(textRow) << textAttack();
		}
		else
		{
			switch (turn / 2)
			{
			case 1:
				textRow = " | Played college ball, ya know";
				break;
			case 2:
				textRow = " | Don't mess with this president!";
				break;
			case 3:
				textRow = " | Taste the power of nanomachines!";
				break;
			}
			cout << textRow << spaceFunc(textRow) << textAttack();
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

int checkFunc(string funcMain)
{
	bool b = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((att[i].wpn[j] == playerDmg) && state)
			{
				b = 1;
			}
		}
		if ((att[i].name == funcMain) && b)
		{
			return att[i].b;
			break;
		}
		else if (i == 19)
		{
			return 2;
		}
		b = 0;
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
		textRow = " | Dev: Take this!";
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
		textRow = " | Dev: I don't want to hurt you!";
		turnDmg = 9;
	}
	else if (func == "Kick")
	{
		if (state)
		{
			att[7].b++;
			textRow = " | Dev: *kiai*";
		}		
		turnDmg = 10;
	}
	else if (func == "Throw" && (playerDmg == 5 || entityDmg == 10))
	{
		if (state)
		{
			att[8].b++;
			textRow = " | Dev: Snipe!";
		}
		turnDmg = 2 * entityDmg;
	}
	else if (func == "Stab" && (playerDmg == 5 || entityDmg == 12 || entityDmg == 10))
	{
		if (playerDmg == 5)
		{
			bonusDmg = 2;
		}
		else if (entityDmg == 12)
		{
			bonusDmg = -5;
		}
		else if (entityDmg == 10)
		{
			bonusDmg = 5;
		}

		if (state)
		{
			att[9].b++;
			textRow = " | Dev: *poke*";
		}
		turnDmg = entityDmg + bonusDmg;
	}
	else if ((func == "Slice" || func == "Cut") && playerDmg == 12)
	{
		if (state && func == "Slice")
		{
			att[10].b++;
		}
		else if (state && func == "Cut")
		{
			att[11].b++;
		}
		textRow = " | Dev: Slice and dice!";
		turnDmg = entityDmg + 2;
	}
	else if (func == "Zandatsu" && playerDmg == 12)
	{
		textRow = " | Dev: I think it's time for Jack... to let 'er rip!";
		turnDmg = 99;
	}
	else if (func == "Whip" && entityDmg == 10)
	{
		if (state)
		{
			att[13].b++;
			textRow = " | Dev: Die!";
		}
		turnDmg = entityDmg + 7;
	}
	else if (func == "I'm fucking invincible!" && playerDmg == 7)
	{
		func = "Explosion";
		textRow = " | Dev: I'm fucking invincible!";
		turnDmg = 99;
	}
	else if ((func == "Push" || func == "Thrust") && entityDmg == 7)
	{
		if (state && func == "Push")
		{
			att[15].b++;
		}
		else if (state && func == "Thrust")
		{
			att[16].b++;
		}
		textRow = " | Dev: Dodge this!";
		turnDmg = entityDmg * 2;
	}
	else if (func == "Spin" && entityDmg == 12)
	{
		if (state)
		{
			att[17].b++;
			textRow = " | Dev: Beyblade time!";
		}
		turnDmg = entityDmg * 2;
	}
	else if (func == "Spaghetti Bolognese" && playerDmg == 10)
	{
		if (state)
		{
			att[18].b++;
			textRow = " | Dev: I'm going to turn you into human spaghetti bolognese!";
		}
		turnDmg = 99;
	}
	else if (func == "Slam" && entityDmg == 7)
	{
		if (state)
		{
			att[19].b++;
			textRow = " | Dev: AoE for the win!";
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
		switch (turn / 2)
		{
		case 1:
			func = "Miss";
			turnDmg = 0;
			return turnDmg;
			break;
		case 2:
			func = "Hit";
			return funcExe();
			break;
		case 3:
			func = "Slash";
			return funcExe();
			break;
		case 4:
			func = "Cut";
			return funcExe();
			break;
		}
	case 2:
		switch (turn / 2)
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
		switch (turn / 2)
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
		switch (turn / 2)
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
int newHp(string funcMain)
{
	func = funcMain;

	if (state)
	{
		enemyHp -= funcExe();
		return enemyHp;
	}
	else
	{
		playerHp -= enemyAttack();
		return playerHp;
	}
}

void choose()
{
	textRow = " | Dev: Damn, I didn't know I had made him this hard. I have to balance him later.";
	cout << textRow << spaceFunc(textRow);
	textRow = " |      ";
	cout << "\n *type 0 or 1, depending on which path you want to take. 0 for left and 1 for right.*\n ";
}
void type()
{
	cout << "\n *type a function to attack, start each word (if multiple) with a capital letter* \n ";
}
void wrongFunc(string funcName)
{
	if (checkFunc(funcName) == 2)
	{
		cout << "\n This is an illogical function! I have to type a logical one.\n ";
	}
	else if (checkFunc(funcName) == 1)
	{
		cout << "\n I have already used this function and I can't use it again! I have to think of another function.\n  *some functions have more than one name*\n ";
	}
}

void trappedDev()
{
	cout << "\n\n";
	cout << "               _  _|                                |      _ \\                    |\n";
	cout << "                 |   __| _` |  _ \\   _ \\   _ \\   _` |     |   |  _ \\ \\ \\   / _ \\  |   _ \\   _ \\   _ \\   __|\n";
	cout << "                 |  |   (   | |   | |   |  __/  (   |     |   |  __/  \\ * /  __/  |  (   | |   |  __/  |\n";
	cout << "                _| _|  \\__,_| .__/  .__/ \\___| \\__,_|    ____/ \\___|   \\_/ \\___| _| \\___/  .__/ \\___| _|\n";
	cout << "                             _|    _|                                                     _|\n";
	cout << "\n\n";
	cout << " SELECT A GAME MODE:\n\n";
	cout << "  0. Video game journalist\n";
	cout << "  1. Normal\n\n ";
}
void rustGear()
{
	cout << "\n";
	cout << "     ____             __    ______                 _____       ___     __   _    __\n";
	cout << "    / __ \\__  _______/ /_  / ____/__  ____ ______ / ___/____  / (_)___/ /  | |  / /__  ____  ____ ____ _____  ________\n";
	cout << "   / /_/ / / / / ___/ __/ / / __/ _ \\/ __ `/ ___/ \\__ \\/ __ \\/ / / __  (_) | | / / _ \\/ __ \\/ __ `/ _ \\/ __ \\/ ___/ _ \\ \n";
	cout << "  / _, _/ /_/ (__  ) /_  / /_/ /  __/ /_/ / /    ___/ / /_/ / / / /_/ /    | |/ /  __/ / / / /_/ /  __/ / / / /__/  __/\n";
	cout << " /_/ |_|\\__,_/____/\\__/  \\____/\\___/\\__,_/_/    /____/\\____/_/_/\\__,_(_)   |___/\\___/_/ /_/\\__, /\\___/_/ /_/\\___/\\___/\n";
	cout << "                                                                                          /____/\n";
	cout << "\n\n";
	cout << "                                             *press Enter to enter the game*\n";
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
void credits()
{

}