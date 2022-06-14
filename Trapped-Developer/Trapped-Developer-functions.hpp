#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;

int sp1Len, sp2Len; //sp1Len = amount of spaces for first
string preRow[3] = { " __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __\n",
					 "|                                                                                         |\n",
					 "|__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|\n" };
//(text row preset) cout << "|     |\n";

void next()
{
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	system("CLS");
}

string playerStats(int hp, int wpnNum, int row) //hp = health points, wpnNum = weapon number
{
	string wpn, dmg, space1, space2; //dmg = damage, space1 = empty space for first row
	sp1Len = 17;
	sp2Len = 16;
	switch (wpnNum)
	{
	case 0:
		wpn = "Stick";
		dmg = '5';
		break;
	case 1:
		wpn = "Cutting edge Sword";
		dmg = '15';
		sp1Len += 14;
		sp2Len += 14;
		break;
	case 2:
		wpn = "Spaghetti Spear";
		dmg = '10';
		sp1Len += 11;
		sp2Len += 11;
		break;
	case 3:
		wpn = "Salvaged Shield";
		dmg = '7';
		sp1Len += 10;
		sp2Len += 10;
		break;
	}

	if (hp > 9)
	{
		sp2Len--;
	}

	for (int i = 0; i < sp1Len; i++)
	{
		space1[i] = ' ';
	}

	for (int i = 0; i < sp2Len; i++)
	{
		space2[i] = ' ';
	}

	switch (row)
	{
	case 1:
		return "| Name: Dev" + space1 + "|";
		break;
	case 2:
		return "|  Health: " + hp + space2 + "|";
		break;
	case 3:
		return "|  Weapon: " + wpn + " - " + dmg + " damage |";
		break;
	}
}

string enemyStats(int hp, int dmg, string name, int row)
{

}

string preRowFunc(int row, int len, bool type)
{

}

void stats(int playerhp, int playerWpnNum, int enemyhp, int enemydmg, string enemyName)
{
	int rowLen1 = size(playerStats(playerhp, playerWpnNum, 3));
	int rowLen2 = size(enemyStats(enemyhp, enemydmg, enemyName, 1));

	cout << preRowFunc(0, rowLen1, 0) << preRowFunc(0, rowLen2, 1);
	cout << preRowFunc(1, rowLen1, 0) << preRowFunc(1, rowLen2, 1);
	cout << playerStats(playerhp, playerWpnNum, 1) << enemyStats(enemyhp, enemydmg, enemyName, 1) << endl;
	cout << playerStats(playerhp, playerWpnNum, 2) << enemyStats(enemyhp, enemydmg, enemyName, 2) << endl;
	cout << playerStats(playerhp, playerWpnNum, 3) << enemyStats(enemyhp, enemydmg, enemyName, 3) << endl;
	cout << preRowFunc(2, rowLen1, 0) << preRowFunc(2, rowLen2, 1);
}

void intro()
{
	cout << preRow[0] << preRow[1];
	cout << "|  Dev: *yawns* Where am I? It's so dark in here. Hey I can see what I'm saying as text.  |\n";
	cout << "|     Why is it in this font? This is very weird. The last thing I remember is...         |\n";
	cout << "|     *scratces head* falling asleep in front of my computer screen. I must've gotten     |\n";
	cout << "|     tired after all that programming. And what is this thing stuck on my belt?          |\n";
	cout << "|                          CONGRATULATIONS! YOU FOUND A 'Stick'!                          |\n";
	cout << "|  Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name  |\n";
	cout << "|     infront of everything I say is 'Dev'. Is that short for 'Developer'? Am I in my     |\n";
	cout << "|     own game!? Does that mean I will have to fight against...                           |\n";
	cout << preRow[2];
}


