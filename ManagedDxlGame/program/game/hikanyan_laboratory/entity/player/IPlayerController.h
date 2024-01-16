#pragma once
#include "Player.h"

class IPlayerController {
public:
    virtual ~IPlayerController() = default;
    virtual void check_input();
    virtual void update_player_state(float delta_time);
    virtual void execute_actions(float delta_time);
};
