#include <iostream>
#include "Trapped-Developer-functions.hpp"
using namespace std;
int main()
{
	int playerHP = 20;
	int enemyHP, enemyDMG; // DMG = damage
	int win = 0; // win: 0 = no one yet, 1 = player, 2 = enemy

	intro();
	next();

	enemyHP = 10;
	enemyDMG = 10;
	while (win == 0)
	{
		stats(playerHP, 0, enemyHP, enemyDMG, "Saber Wolf"); // 0 = player's first weapon 'Stick', Saber Wolf = first enemy name


	}
	win = 0;
}