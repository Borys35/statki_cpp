#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

#define SLEEP_DURATION 1500

bool Game::check_if_win(BattleMap battleMap)
{
    system("cls");
    if (battleMap.points >= pointsToWin) {
        if (battleMap.isPlayer) {
            std::cout << " __          __                    _           _ \n"
                " \\ \\        / /                   | |         | |\n"
                "  \\ \\  /\\  / /   _  __ _ _ __ __ _| | ___  ___| |\n"
                "   \\ \\/  \\/ / | | |/ _` | '__/ _` | |/ _ \\/ __| |\n"
                "    \\  /\\  /| |_| | (_| | | | (_| | |  __/\\__ \\_|\n"
                "     \\/  \\/  \\__, |\\__, |_|  \\__,_|_|\\___||___(_)\n"
                "              __/ | __/ |                        \n"
                "             |___/ |___/                         \n";
        }
        else {
            std::cout << "  _____                              _                 \n"
                " |  __ \\                            | |                \n"
                " | |__) | __ _______  __ _ _ __ __ _| | ___  ___       \n"
                " |  ___/ '__|_  / _ \\/ _` | '__/ _` | |/ _ \\/ __|      \n"
                " | |   | |   / /  __/ (_| | | | (_| | |  __/\\__ \\_ _ _ \n"
                " |_|   |_|  /___\\___|\\__, |_|  \\__,_|_|\\___||___(_|_|_)\n"
                "                      __/ |                               \n"
                "                     |___/                                \n";
        }
        return true;
    }

    return false;
}

Game::Game()
{
    enemyBattleMap = BattleMap(false);
    playerBattleMap = BattleMap(true);
}

bool Game::start()
{
    srand(time(NULL));

    char opt = ' ';

    std::cout << "Statki\n";
    std::cout << "Wybierz mape\n";
    std::cout << "[1] 5x5\n";
    std::cout << "[2] 7x7\n";
    std::cout << "[3] 10x10\n";
    std::cout << "[4] 3x3\n";

    std::cin >> opt;
    Vector2 map_size = Vector2(0,0);

    switch (opt) {
    case '1':
        map_size.set(5, 5);
        break;
    case '2':
        map_size.set(7, 7);
        break;
    case '3':
        map_size.set(10, 10);
        break;
    case '4':
        map_size.set(3, 3);
        break;
    default:
        return false;
    }

    playerMap.generate(map_size);
    enemyMap.generate(map_size);
    playerBattleMap.generate(map_size);
    enemyBattleMap.generate(map_size);

    system("cls");
    return true;
}

void Game::prepare()
{
    int max_ship_size = (1 + playerMap.size.x()) / 2;
    for (int i = max_ship_size; i > 0; i--) {
        pointsToWin += i;
        Vector2 currShip = Vector2(i, 1);
        if (!playerMap.place_ship(currShip)) {
            i++;
        }
        else {
            enemyMap.place_ship_ai(currShip);
        }
    }
}

void Game::start_battle()
{
    std::cout << "Zacznij gre wybierajac dowolny przycisk";
    _getch();
    system("cls");
    while (true) {
        int res = 0;
        // gracz strzela dopoki nie chybi
        do {
            if (res == 8)
                std::cout << "TRAFILES! ";
            std::cout << "TWOJA TURA:\n";
            res = playerBattleMap.take_shot(enemyMap);
            system("cls");
            // sprawdzic czy gracz wygral po strzale
            if (check_if_win(playerBattleMap))
                return;
        } while (res != 7);
        res = 0;
        Vector2* ai_last_cell = new Vector2{ -1, -1 };
        Vector2* ai_direction = new Vector2{ -1, -1 };
        do {
            std::cout << "TURA PRZECIWNIKA:\n";
            enemyBattleMap.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));
            system("cls");
            std::cout << "PRZECIWNIK STRZELIL:\n";
            if (res == 8) {
                Vector2 alc = *ai_last_cell;
                // jezeli komputer trafil poprzedni strzal, strzela jeszcze raz
                // komputer wybiera tylko sasiednie pola
                res = enemyBattleMap.take_shot_next_to_cell_ai(playerMap, *ai_last_cell);
                if (check_if_win(enemyBattleMap))
                    return;

                // jezeli komputer znowu trafil, strzela w pola w jednym rzedzie lub kolumnie
                if (res == 8) {
                    while (res == 8) {
                        // komputer strzela dopoki nie chybi

                        enemyBattleMap.display();
                        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));
                        system("cls");

                        int x_diff = ai_last_cell->x() - alc.x();
                        int y_diff = ai_last_cell->y() - alc.y();
                        res = enemyBattleMap.take_shot_next_to_cell_ai(playerMap, *ai_last_cell, Vector2{ x_diff, y_diff });
                        if (check_if_win(enemyBattleMap))
                            return;
                    }
                }
            } 
            else {
                res = enemyBattleMap.take_shot_ai(playerMap, *ai_last_cell);
                if (check_if_win(enemyBattleMap))
                    return;
            }
            enemyBattleMap.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));
            system("cls");
        } while (res != 7);
    }
}