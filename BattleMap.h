#pragma once
#include "Map.h"
class BattleMap :
    public Map
{
    int take_shot(Map mapUnderAttack, Vector2 cord);

public:
    BattleMap();
    BattleMap(bool _isPlayer);
    bool isPlayer;
    int points = 0;
    int take_shot(Map mapUnderAttack);
    int take_shot_ai(Map mapUnderAttack, Vector2& cell);
    int take_shot_next_to_cell_ai(Map mapUnderAttack, Vector2 cell);
    int take_shot_next_to_cell_ai(Map mapUnderAttack, Vector2 cell, Vector2 direction);
};

