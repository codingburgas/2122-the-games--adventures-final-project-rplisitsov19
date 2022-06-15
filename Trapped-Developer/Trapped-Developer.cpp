#include <iostream>
#include "Trapped-Developer-functions.hpp"
using namespace std;

int main()
{
	int playerHP = 25;
	int win = 0; // win: 0 = no one yet, 1 = player, 2 = enemy
	weapon stick(5, "Stick"), sword(15, "Cutting edge Sword"), spear(10, "Spaghetti Spear"), shield(7, "Salvaged Shield");
	enemy wolf(10, "Saber Wolf"), vent(20, "Vent"), muson(25, "Muson"), prez(30, "The President");
	wolf.wpn = sword.name;
	wolf.dmg = sword.dmg;
	vent.wpn = spear.name;
	vent.dmg = spear.dmg;
	muson.wpn = shield.name;
	muson.dmg = shield.dmg;
	prez.wpn = "Nanomachines";
	prez.dmg = 6;

	intro();
	next();
	while (win == 0)
	{
		stats(playerHP, stick.dmg, stick.name, wolf.hp, wolf.name, wolf.dmg); //first enemy 'Saber Wolf'

	}
	win = 0;
}