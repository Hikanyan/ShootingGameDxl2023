#pragma once
#include "../../hikanyan_library/game_object.h"
#include "../../hikanyan_library/mono_behaviour.h"
class test final :public mono_behaviour
{
public:

    void start()override
    {
        game_object obj;
        obj.add_component<test>();
    };
    void update(float delta_time)override
    {
        
    };
};
