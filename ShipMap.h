#pragma once
#include "Map.h"
class ShipMap :
    public Map
{

	bool place_ship(Vector2 ship, Vector2 pos);

public:
	bool place_ship(Vector2 ship);
	void place_ship_ai(Vector2 ship);
};

