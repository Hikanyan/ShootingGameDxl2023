#pragma once
#include "../../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"
#include "../../hikanyan_library/include/mono_behaviour/GameObject.h"
#include "../dxlib_ext/dxlib_ext.h"

class Test final : public MonoBehaviour
{
public:
    //再起関数を使用して、PlayerがMapを移動できる範囲を表示する

    void init() override
    {
        Debug::log("init{}", owner_->get_name());
    }
    void start() override
    {
        Debug::log("start{}", owner_->get_name());
    }

    void update(float delta_time) override
    {
        owner_->get_transform().set_position(owner_->get_transform().get_position() + tnl::Vector3(1, 0, 0));
        Debug::log("update{}", owner_->get_name());
    }

    void fixed_update(float delta_time) override
    {
        Debug::log("fixed_update{}", owner_->get_name());
    }
    
    void draw() override
    {
        DrawBoxEx(owner_->get_transform().get_position(), owner_->get_transform().get_scale().x,
                  owner_->get_transform().get_scale().y, false);
    }
    void on_enable() override
    {
        Debug::log("on_enable{}", owner_->get_name());
    }
    void on_disable() override
    {
        Debug::log("on_disable{}", owner_->get_name());
    }
};
/*
実行される順番が正常になった。
initobj
startobj
updateobj
fixed_updateobj
updateobj
updateobj
fixed_updateobj
updateobj
updateobj
...
*/