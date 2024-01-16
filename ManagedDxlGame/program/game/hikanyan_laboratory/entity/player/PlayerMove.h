#pragma once
#include "IPlayerController.h"
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class PlayerMove : public MonoBehaviour, public IPlayerController
{
public:
    void update(float delta_time) override
    {
        // 移動ロジックを実装
    }
};
