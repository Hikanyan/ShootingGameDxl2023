﻿#pragma once
#include "../../hikanyan_library/include/mono_behaviour.h"
#include "../../hikanyan_library/include/game_object.h"

class test final : public mono_behaviour
{
public:
    void start() override
    {
        game_object obj;
        obj.add_component<test>();
    };

    void update(float delta_time) override
    {
    };
};
