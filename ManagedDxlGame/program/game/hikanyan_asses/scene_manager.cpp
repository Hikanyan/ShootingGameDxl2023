#include "scene_manager.h"

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
    // そしてここでもsingletonのインスタンスを使用します
    if (scene_manager::getInstance()->current_scene_)
    {
        scene_manager::getInstance()->current_scene_->destroy();
    }
}

void scene_manager::draw_screen() const
{
    DrawStringEx(50, 50, -1, "ねこ");
    DrawStringEx(DXE_WINDOW_WIDTH / 2 - 80, DXE_WINDOW_HEIGHT * 0.2, -1, "シューティングゲーム");

    if (current_scene_)
    {
        current_scene_->draw();
    }
}
