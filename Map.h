#pragma once
#include <vector>
#include "Vector2.h"

class Map
{
protected:
	bool is_ship_colliding(Vector2 pos, Vector2 ship);

public:
	std::vector<std::vector<int>> cells;
	Map();
	Vector2 size;
	void generate(Vector2 s);
	void display();
};

