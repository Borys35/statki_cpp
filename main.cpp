#include <iostream>
#include <conio.h>
#include <vector>
#include "Game.h"

int main()
{
    Game game = Game();
    
    if (!game.start())
        return 0;

    game.prepare();

    game.start_battle();
}