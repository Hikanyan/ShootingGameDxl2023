#pragma once
#include "IPlayerController.h"
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class PlayerController : public MonoBehaviour, public IPlayerController
{
public:
    void update(float delta_time) override;

private:
    void check_input() override;
    void update_player_state(float delta_time) override;
    void execute_actions(float delta_time) override;
};
