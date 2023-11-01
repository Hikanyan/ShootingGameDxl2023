#pragma once
#include "../../hikanyan_library/game_object.h"
#include "../../hikanyan_library/mono_behaviour.h"
class test:public mono_behaviour
{
public:

    void start()override;
    void update()override;
};
