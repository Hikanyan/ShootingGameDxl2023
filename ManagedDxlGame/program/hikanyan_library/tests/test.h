#pragma once
#include "../../hikanyan_library/include/mono_behaviour/mono_behaviour.h"
#include "../../hikanyan_library/include/mono_behaviour/game_object.h"
#include "../dxlib_ext/dxlib_ext.h"

class test final : public mono_behaviour
{
public:
    void start() override
    {
        debug::log("test{}", this->get_name());
        debug::log("test{},{}", this->get_owner()->get_name(), this->get_owner()->get_tag());
        get_owner()->add_component<box_collider_2d>();
        
        instantiate("test");
        destroy(get_owner());
    }

    void update(float delta_time) override
    {
        DrawStringEx(50, 250, -1, "test");
    }
};
