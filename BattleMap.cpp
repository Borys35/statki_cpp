#include "BattleMap.h"
#include <iostream>
#include "HelperFunctions.h"

int BattleMap::take_shot(Map mapUnderAttack, Vector2 cord)
{
    int res = 0;
    if (cells[cord.x()][cord.y()] == 0) {
        if (mapUnderAttack.cells[cord.x()][cord.y()] == 3)
        {
            res = 8;
            points++;
        }
        else
        {
            res = 7;
        }
        cells[cord.x()][cord.y()] = res;
    }
    // if res = 0, there is incorrect input. you need to take shot again.
    return res;
}

BattleMap::BattleMap()
{
    isPlayer = false;
}

BattleMap::BattleMap(bool _isPlayer)
{
    isPlayer = _isPlayer;
}

int BattleMap::take_shot(Map mapUnderAttack)
{
    int x = 0, y = 0;

    display();
    std::cout << "Oddaj strzal w przeciwnika\n";
    std::cout << "Podaj kolumne: ";
    std::cin >> x;
    std::cout << "Podaj rzad: ";
    std::cin >> y;

    Vector2 cord = { x,y };

    int result = take_shot(mapUnderAttack, cord);
    return result;
}

int BattleMap::take_shot_ai(Map mapUnderAttack, Vector2& cell)
{
    // find cells you can hit
    std::vector<Vector2> legal_cells;
    for (int y = 0; y < size.y(); y++) {
        for (int x = 0; x < size.x(); x++) {
            Vector2 pos = Vector2(x, y);
            // std::cout << x << ":" << y << "\n";
            if (cells[x][y] == 0) {
                legal_cells.push_back(Vector2(x, y));
            }
        }
    }

    // get random legal cell
    int i = HelperFunctions::random_between_two_numbers(0, legal_cells.size() - 1);

    int result = take_shot(mapUnderAttack, legal_cells[i]);
    cell = legal_cells[i];
    return result;
}

int BattleMap::take_shot_next_to_cell_ai(Map mapUnderAttack, Vector2 cell)
{
    // find cells you can hit
    std::vector<Vector2> legal_cells;

    int y_start = cell.y() - 1 < 0 ? -1 : cell.y() - 1,
        y_end = cell.y() + 1 >= size.y() ? -1 : cell.y() + 1;
    int x_start = cell.x() - 1 < 0 ? -1 : cell.x() - 1,
        x_end = cell.y() + 1 >= size.x() ? -1 : cell.x() + 1;

    if (x_start != -1 && cells[x_start][cell.y()] == 0)
        legal_cells.push_back(Vector2(x_start, cell.y()));
    if (x_end != -1 && cells[x_end][cell.y()] == 0)
        legal_cells.push_back(Vector2(x_end, cell.y()));
    if (y_start != -1 && cells[cell.x()][y_start] == 0)
        legal_cells.push_back(Vector2(cell.x(), y_start));
    if (y_end != -1 && cells[cell.x()][y_end] == 0)
        legal_cells.push_back(Vector2(cell.x(), y_end));

    // get random legal cell
    int i = HelperFunctions::random_between_two_numbers(0, legal_cells.size() - 1);

    int result = take_shot(mapUnderAttack, legal_cells[i]);
    cell = legal_cells[i];
    return result;
}

int BattleMap::take_shot_next_to_cell_ai(Map mapUnderAttack, Vector2 cell, Vector2 direction)
{
    if (direction.x() > 0) {
        if (1 + cell.x() < size.x()) {
            cell = Vector2{ 1 + cell.x(), cell.y() };
        }
        else {
            cell = Vector2{ cell.x() - 1, cell.y() };
        }
    }
    else if (direction.x() < 0) {
        if (cell.x() == 0) {
            cell = Vector2{ cell.x() - 1, cell.y() };
        }
        else {
            cell = Vector2{ cell.x() + 1, cell.y() };
        }
    }
    else if (direction.y() > 0) {
        if (1 + cell.y() < size.y()) {
            cell = Vector2{ cell.x(), 1 + cell.y() };
        }
        else {
            cell = Vector2{ cell.x(), cell.y() - 1 };
        }
    }
    else if (direction.y() < 0) {
        if (cell.y() == 0) {
            cell = Vector2{ cell.x(), cell.y() - 1 };
        }
        else {
            cell = Vector2{ cell.x(), cell.y() + 1 };
        }
    }

    // will return 0 if no cells found
    return take_shot(mapUnderAttack, cell);
}
