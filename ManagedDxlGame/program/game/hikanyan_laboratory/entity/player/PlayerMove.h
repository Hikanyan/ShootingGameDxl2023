#pragma once
#include "IPlayerController.h"
#include "PlayerStatus.h"
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class PlayerMove : public MonoBehaviour, public IPlayerController
{
public:
    void start() override;

private:
    PlayerStatus player_status_;
    Player player_;
    void Left();
    void Right();
    void Up();
    void Down();
    void Jump();
};
