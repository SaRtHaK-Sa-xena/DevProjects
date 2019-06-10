#pragma once

#include <string>
//Classes
class TeamBlue
{
private:
	int health;
	int attack = rand() % 10;
public:
	int B_GetHealth();
	void B_SetHealth(int h);

	int B_GetAttack();
	int B_SetAttack(int a);
};
class TeamRed
{
private:
	int health;
	int attack = rand() % 10;
public:
	int R_GetHealth();
	void R_SetHealth(int h);

	int R_GetAttack();
	int R_SetAttack(int a);
};