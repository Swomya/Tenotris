#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SDL.h>

enum class Action
{
    stay_idle, back, move_up, move_down, move_left, move_right, select, drop, rotate, hold, pause
};


class InputManager
{
public:
    InputManager ();
    void clearEventQueue ();
    Action getAction ();
    bool isGameExiting ();
    bool pollAction ();
    void setExit ();
private:
    bool quit_game;
    Action action;
};

#endif