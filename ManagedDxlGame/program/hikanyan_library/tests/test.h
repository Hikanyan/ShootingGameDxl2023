#pragma once
#include "../../hikanyan_library/include/mono_behaviour/mono_behaviour.h"
#include "../../hikanyan_library/include/mono_behaviour/game_object.h"
#include "../dxlib_ext/dxlib_ext.h"

class test final : public mono_behaviour
{
public:
    //再起関数を使用して、PlayerがMapを移動できる範囲を表示する

    void start() override
    {
    }

    void update(float delta_time) override
    {
    }

    void draw() override
    {//owner_->get_transform().get_position()
    }

    //再起関数
    static void draw_map(const std::shared_ptr<game_object>& obj)
    {
    }
};
