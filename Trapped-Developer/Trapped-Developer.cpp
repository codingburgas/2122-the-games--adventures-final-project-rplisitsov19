#include <iostream>
#include "Trapped-Developer-functions.hpp"
using namespace std;
int main()
{
	int playerHP = 25;
	int enemyHP, enemyDMG; // DMG = damage
	int win = 0; // win: 0 = no one yet, 1 = player, 2 = enemy
	weapon stick(5, "Stick"), sword(15, "Cutting edge Sword"), spear(10, "Spaghetti Spear"), shield(7, "Salvaged Shield"); //Cutting edge Sword, Spaghetti Spear, Salvaged Shield

	intro();
	next();

	enemyHP = 10;
	while (win == 0)
	{
		stats(playerHP, 0, enemyHP, 10, 1); // 0 = player's first weapon 'Stick', 10 = enemy attack points, 1 = first enemy 'Saber Wolf'

	}
	win = 0;
}