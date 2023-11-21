#include "SceneManager.h"

void scene_manager::set_current_scene(std::shared_ptr<SceneBase> scene)
{
    // 古いシーンのリソースを解放する前に、必要なクリーンアップを行います。
    un_load_scene();
    // 新しいシーンに置き換えます。
    current_scene_ = std::move(scene);
}

void scene_manager::un_load_scene() const
{
    // 現在のシーンをアンロードし、リソースを解放します。
    if (current_scene_)
    {
        current_scene_->scene_destroy();
    }
}

void scene_manager::game_start()
{
    // ここではsingletonのインスタンスを通じてcurrent_scene_にアクセスします
    if (scene_manager::getInstance()->current_scene_)
    {
        scene_manager::getInstance()->current_scene_->init();
        scene_manager::getInstance()->current_scene_->awake();
        scene_manager::getInstance()->current_scene_->start();
    }
    //entity_controller::getInstance()->gameStart();
}

void scene_manager::game_main(float delta_time)
{
    // ここでもsingletonのインスタンスを通じてcurrent_scene_にアクセスします
    if (scene_manager::getInstance()->current_scene_)
    {
        scene_manager::getInstance()->current_scene_->update(delta_time);
    }
    scene_manager::getInstance()->draw_screen();
    //entity_controller::getInstance()->update(delta_time);
    //entity_controller::getInstance()->draw();
}

void scene_manager::game_end()
{
}

void scene_manager::draw_screen() const
{
    //test用
    DrawStringEx(50, 50, -1, "ねこ");
    DrawStringEx(DXE_WINDOW_WIDTH / 2 - 80, DXE_WINDOW_HEIGHT * 0.2, -1, "シューティングゲーム");

    if (current_scene_)
    {
        current_scene_->draw();
    }
}
