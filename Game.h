#pragma once
#include "Vector2.h"
#include "ShipMap.h"
#include "BattleMap.h"

class Game
{
public:
	Game();
	int pointsToWin = 0;
	bool start();
	void prepare();
	void start_battle();
	bool check_if_win(BattleMap battleMap);
	ShipMap playerMap;
	ShipMap enemyMap;
	BattleMap playerBattleMap;
	BattleMap enemyBattleMap;
};

