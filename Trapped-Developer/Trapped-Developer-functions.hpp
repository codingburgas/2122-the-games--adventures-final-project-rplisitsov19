#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;

void intro()
{
	cout << " __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __\n";
	cout << "|                                                                                                                                   |\n";
	cout << "| Dev: *yawns* Where am I? It's so dark in here. Hey I can see what I'm saying as text. Why is it in this font? This is very weird. |\n";
	cout << "|     The last thing I remember is... *scratces head* falling asleep in front of my computer screen.                                |\n";
	cout << "|     I must've gotten tired after all that programming. And what is this thing stuck on my belt?                                   |\n";
	cout << "|                                      CONGRATULATIONS! YOU FOUND A 'Scrappy Sword'!                                                |\n";
	cout << "| Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name infront of everything I say is 'Dev'.       |\n";
	cout << "|     Is that short for 'Developer'? Am I in my own game!?                                                                          |\n";
	cout << "|__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|\n";
}

void next()
{
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	system("CLS");
}