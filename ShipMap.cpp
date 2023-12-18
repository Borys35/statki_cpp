#include "ShipMap.h"
#include "Map.h"
#include <iostream>
#include "HelperFunctions.h"

bool ShipMap::place_ship(Vector2 ship, Vector2 pos)
{
    int y_start = pos.y() == 0 ? pos.y() : pos.y() - 1;
    int y_end = (pos.y() + ship.y()) == size.y() ? pos.y() + ship.y() : pos.y() + ship.y() + 1;

    int x_start = pos.x() == 0 ? pos.x() : pos.x() - 1;
    int x_end = (pos.x() + ship.x()) == size.x() ? pos.x() + ship.x() : pos.x() + ship.x() + 1;

    for (int y = y_start; y < y_end; y++) {
        for (int x = x_start; x < x_end; x++) {
            if (y == (pos.y() - 1) || y == (pos.y() + ship.y()) ||
                x == (pos.x() - 1) || x == (pos.x() + ship.x()))
                cells[x][y] = 2;
            else
                cells[x][y] = 3;
        }
    }
    return true;
}

bool ShipMap::place_ship(Vector2 ship)
{
    char rotate_char = ' ';
    int x = 0, y = 0;
    display();
    std::cout << "Poloz statek o wymiarach " << ship.x() << "x" << ship.y() << "\n";
    std::cout << "Podaj kolumne: ";
    std::cin >> x;
    std::cout << "Podaj rzad: ";
    std::cin >> y;
    std::cout << "Poloz statek w dol czy w prawo? (d/p): ";
    std::cin >> rotate_char;
    Vector2 pos = Vector2(x, y);

    // Obroc statek
    if (rotate_char == 'd') {
        ship.rotate();
    }

    if (is_ship_colliding(pos, ship)) {
        // Obroc z powrotem
        if (rotate_char == 'd') {
            ship.rotate();
        }
        return false;
    }
    else {
        place_ship(ship, pos);
        return true;
    }
}

void ShipMap::place_ship_ai(Vector2 ship)
{
    // find every legal position (Vector2) and add to vector
    std::vector<Vector2> legal_positions;
    for (int y = 0; y < size.y(); y++) {
        for (int x = 0; x < size.x(); x++) {
            Vector2 pos = Vector2(x, y);
            // std::cout << x << ":" << y << "\n";
            if (!is_ship_colliding(pos, ship))
                legal_positions.push_back(pos);
        }
    }

    // get random legal position
    int i = HelperFunctions::random_between_two_numbers(0, legal_positions.size() - 1);

    // place ship
    place_ship(ship, legal_positions[i]);
}

