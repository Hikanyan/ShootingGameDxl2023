#pragma once
#include "../../hikanyan_library/game_object.h"
#include "../../hikanyan_library/mono_behaviour.h"

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
        const auto obj = std::make_unique<game_object>();//動的にメモリを確保
        obj->setName("obj");//名前を設定
        obj->add_component<transform>();//transformコンポーネントを追加
        obj->get_transform().position = {100, 100, 0};
        obj->get_transform().rotation = {0, 0, 0};
        obj->get_transform().scale = {1, 1, 1};

        auto* my_object = new game_object();//動的にメモリを確保
        my_object->setName("my_object");//名前を設定
        my_object->add_component<transform>(); // transformコンポーネントを追加
        my_object->get_transform().position = {100, 100, 0};
        my_object->get_transform().rotation = {0, 0, 0};
        my_object->get_transform().scale = {1, 1, 1};

        
    };
   


    // 他のメソッド（Update, FixedUpdate等）もここに追加する
};
