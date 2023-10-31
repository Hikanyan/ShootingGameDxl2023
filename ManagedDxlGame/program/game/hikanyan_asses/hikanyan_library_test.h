#pragma once
#include "../../hikanyan_library/game_object.h"
#include "../../hikanyan_library/mono_behaviour.h"


//このクラスは、Sceneに配置されたGameObjectにアタッチされるコンポーネントです。
class hikanyan_library_test final : public mono_behaviour
{
private:
    game_object my_object; // クラスのメンバとして定義

public:
    void init() override
    {
        my_object = game_object("my_object");
        my_object.add_component<transform>(); // transformコンポーネントを追加
        my_object.get_transform().position = {100, 100, 0};
        my_object.get_transform().rotation = {0, 0, 0};
        my_object.get_transform().scale = {1, 1, 1};
        my_object.add_component<box_collider_2d>(); // box_collider_2dコンポーネントを追加
    };

    // 他のメソッド（Update, FixedUpdate等）もここに追加する
};
