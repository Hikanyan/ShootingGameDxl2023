#pragma once
#include <memory>

#include "test.h"
#include "../../hikanyan_library/include/mono_behaviour.h"
#include "../../hikanyan_library/include/game_object.h"

class box_collider_2d;
class transform;

//Sceneに配置するときに必要なコンポーネント
class hikanyan_library_test final : public mono_behaviour
{
private:


public:
    hikanyan_library_test()
    {
        // コンストラクタでは何もしない（あるいは別の初期化コードを書く）
    };


    //Unityのinspectorで表示する変数
    void init() override
    {
        //unique_ptrとは、動的に確保したメモリを自動的に解放するためのクラス
        const auto obj = std::make_unique<game_object>(); //動的にメモリを確保
        obj->set_name("obj"); //名前を設定
        obj->add_component<transform>(); //transformコンポーネントを追加
        obj->get_transform().position = {100, 100, 0};
        obj->get_transform().rotation = {0, 0, 0};
        obj->get_transform().scale = {1, 1, 1};
        obj->add_component<box_collider_2d>(); //box_collider_2dコンポーネントを追加

        auto* my_object = new game_object(); //動的にメモリを確保
        my_object->set_name("my_object"); //名前を設定
        my_object->add_component<transform>(); // transformコンポーネントを追加
        my_object->get_transform().position = {100, 100, 0};
        my_object->get_transform().rotation = {0, 0, 0};
        my_object->get_transform().scale = {1, 1, 1};

        auto* my_object2 = new game_object(); //動的にメモリを確保
        my_object2->set_name("test"); //名前を設定
        my_object2->add_component<transform>(); // transformコンポーネントを追加
        my_object2->add_component<test>(); // testコンポーネントを追加
    };


    // 他のメソッド（Update, FixedUpdate等）もここに追加する
};
