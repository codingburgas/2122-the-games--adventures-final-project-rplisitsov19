#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string>
using namespace std;

string preRow[3] = { " __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __",
					 "|                                                                                         |",
					 "|__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|" };
//(text row preset) cout << "|     |\n";

void next()
{
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	system("CLS");
}

string playerStats(int hp, int wpnNum, int row) //hp = health points, wpnNum = weapon number
{
	string hpText(1, char(hp) + 48);
	string wpn, dmg, space1, space2; //dmg = damage, space1 = empty space for first row
	int sp1Len = 19, sp2Len = 10; //sp1Len = amount of spaces for first
	switch (wpnNum)
	{
	case 0:
		wpn = "Stick";
		dmg = "5";
		break;
	case 1:
		wpn = "Cutting edge Sword";
		dmg = "15";
		sp1Len += 14;
		sp2Len += 14;
		break;
	case 2:
		wpn = "Spaghetti Spear";
		dmg = "10";
		sp1Len += 11;
		sp2Len += 11;
		break;
	case 3:
		wpn = "Salvaged Shield";
		dmg = "7";
		sp1Len += 10;
		sp2Len += 10;
		break;
	}

	switch (row)
	{
	case 1:
		for (int i = 0; i < sp1Len; i++)
		{
			space1 += ' ';
		}
		return "| Dev" + space1 + "|";
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
		return "|  Health: " + hpText + "HP"+ space2 + "|";
		break;
	case 3:
		return "|  Weapon: " + wpn + " - " + dmg + "DMG |";
		break;
	}
}
string enemyStats(int hp, int dmg, int enemy, int row)
{
	string hpText(1, char(hp) + 48);
	string dmgText(1, char(dmg) + 48);
	string name, space1, space2;
	int sp1Len = 2, sp2Len = 1;
	switch (enemy)
	{
	case 1:
		name = "Saber Wolf";
		sp1Len += 2;
		break;
	case 2:
		name = "Vent";
		sp1Len += 8;
		break;
	case 3:
		name = "Muson";
		sp1Len += 7;
		break;
	case 4:
		name = "The President";
		break;
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
		if (hp > 9)
		{
			string dmg1(1, char(hp % 10) + 48), dmg2(1, char(floor(hp / 10) + 48));
			dmgText = dmg2 + dmg1;
		}
		return "|   Attack: " + dmgText + "DMG" + " |";
		break;
	}
}
string preRowFunc(int row, int len, char c)
{
	string line = "";
	for (int i = 0; i < len; i++)
	{
		line += c;
	}

	if (row == 0)
	{
		return " " + line + " ";
	}
	else
	{
		return "|" + line + "|";
	}
}

void stats(int playerhp, int playerWpnNum, int enemyhp, int enemydmg, int enemyName)
{
	int rowLen1 = size(playerStats(playerhp, playerWpnNum, 3));
	int rowLen2 = size(enemyStats(enemyhp, enemydmg, enemyName, 3));
	int gapSpace = size(preRow[1]) - (rowLen1 + rowLen2);
	rowLen1 -= 2;
	rowLen2 -= 2;
	string gap = "";
	for (int i = 0; i < gapSpace; i++)
	{
		gap += ' ';
	}

	cout << preRowFunc(0, rowLen1, '_') << gap << preRowFunc(0, rowLen2, '_') << endl;
	cout << preRowFunc(1, rowLen1, ' ') << gap << preRowFunc(1, rowLen2, ' ') << endl;
	cout << playerStats(playerhp, playerWpnNum, 1) << gap << enemyStats(enemyhp, enemydmg, enemyName, 1) << endl;
	cout << playerStats(playerhp, playerWpnNum, 2) << gap << enemyStats(enemyhp, enemydmg, enemyName, 2) << endl;
	cout << playerStats(playerhp, playerWpnNum, 3) << gap << enemyStats(enemyhp, enemydmg, enemyName, 3) << endl;
	cout << preRowFunc(2, rowLen1, '_') << gap << preRowFunc(2, rowLen2, '_') << endl;
}

void intro()
{
	cout << preRow[0] << endl << preRow[1] << endl;
	cout << "|  Dev: *yawns* Where am I? It's so dark in here. Hey I can see what I'm saying as text.  |\n";
	cout << "|     Why is it in this font? This is very weird. The last thing I remember is...         |\n";
	cout << "|     *scratces head* falling asleep in front of my computer screen. I must've gotten     |\n";
	cout << "|     tired after all that programming. And what is this thing stuck on my belt?          |\n";
	cout << "|                          CONGRATULATIONS! YOU FOUND A 'Stick'!                          |\n";
	cout << "|  Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name  |\n";
	cout << "|     infront of everything I say is 'Dev'. Is that short for 'Developer'? Am I in my     |\n";
	cout << "|     own game!? Does that mean I will have to fight against...                           |\n";
	cout << preRow[2] << endl;
}


