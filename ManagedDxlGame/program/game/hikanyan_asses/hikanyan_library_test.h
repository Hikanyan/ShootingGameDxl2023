#pragma once
#include "../../hikanyan_library/game_object.h"
#include "../../hikanyan_library/mono_behaviour.h"

class hikanyan_library_test : public mono_behaviour
{
private:
    game_object my_object; // クラスのメンバとして定義

public:
    hikanyan_library_test()
    {
        // コンストラクタでは何もしない（あるいは別の初期化コードを書く）
    };

    void start() override
    {
        my_object.add_component<transform>(); // transformコンポーネントを追加
        my_object.get_transform().position = {100, 100, 0};
        my_object.get_transform().rotation = {0, 0, 0};
        my_object.get_transform().scale = {1, 1, 1};
    };

    // 他のメソッド（Update, FixedUpdate等）もここに追加する
};
