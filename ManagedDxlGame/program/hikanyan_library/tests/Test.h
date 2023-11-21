#pragma once
#include "../../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"
#include "../../hikanyan_library/include/mono_behaviour/GameObject.h"
#include "../dxlib_ext/dxlib_ext.h"

class Test final : public MonoBehaviour
{
public:
    //再起関数を使用して、PlayerがMapを移動できる範囲を表示する

    void start() override
    {
        owner_->get_transform().set_position(tnl::Vector3(0, 0, 0));
        auto obj = instantiate<GameObject>();
        obj->add_component<Transform>();
    }

    void update(float delta_time) override
    {
    }

    void draw() override
    {
    }
};
