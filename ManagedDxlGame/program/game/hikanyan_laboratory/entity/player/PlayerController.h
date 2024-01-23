#pragma once
#include "IPlayerController.h"
#include "PlayerStatus.h"
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class PlayerController : public MonoBehaviour, public IPlayerController
{
private:
    PlayerStatus* player_status_ = new PlayerStatus();
    void check_input() override;
    void update_player_state(float delta_time) override;
    void execute_actions(float delta_time) override;
    bool canMove();
};
