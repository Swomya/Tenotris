
#include "game.hpp"
#undef main 

int main(int argc, char **argv)
{
    
    Game *game = Game::getInstance();
    if (game->initialize())
    {
        while (!game->isGameExiting())
        {
            game->run();
        }
        game->exit();
    }
    return 0;
}