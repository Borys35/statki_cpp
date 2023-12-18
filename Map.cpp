#include "Map.h"
#include <iostream>
#include "HelperFunctions.h"

// 0 - empty space (only space you can place ships)
// 2 - illegal space next to ship
// 3 - ship
// 7 - missed shot
// 8 - hit

bool Map::is_ship_colliding(Vector2 pos, Vector2 ship)
{
    if (pos.x() + ship.x() > size.x() || pos.y() + ship.y() > size.y()) {
        return true;
    }

    for (int y = pos.y(); y < pos.y() + ship.y(); y++) {
        for (int x = pos.x(); x < pos.x() + ship.x(); x++) {
            if (cells[x][y] != 0) {
                return true;
            }
        }
    }

    return false;
}

Map::Map() {}

void Map::display()
{
    for (int y = 0; y < size.y() + 1; y++) {
        for (int x = 0; x < size.x() + 1; x++) {
            if (x == 0 && y == 0)
                std::cout << "\0";
            else if (y == 0)
                std::cout << x - 1 << ".";
            else if (x == 0)
                std::cout << y - 1 << ".";
            else
                std::cout << HelperFunctions::get_char(cells[x - 1][y - 1]);
            std::cout << "\t";
        }
        std::cout << "\n\n";
    }
}

void Map::generate(Vector2 s)
{
	size.set(s);
    for (int x = 0; x < s.x(); x++) {
        std::vector<int> row;
        for (int y = 0; y < s.y(); y++) {
            row.push_back(0);
        }
        cells.push_back(row);
    }
}

