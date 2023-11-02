#include "game_manager.h"

void game_manager::game_start() {
    // ここではsingletonのインスタンスを通じてcurrent_scene_にアクセスします
    if (game_manager::getInstance()->current_scene_) {
        game_manager::getInstance()->current_scene_->init();
        game_manager::getInstance()->current_scene_->awake();
        game_manager::getInstance()->current_scene_->start();
    }
    //entity_controller::getInstance()->gameStart();
}

void game_manager::game_main(float delta_time) {
    // ここでもsingletonのインスタンスを通じてcurrent_scene_にアクセスします
    if (game_manager::getInstance()->current_scene_) {
        game_manager::getInstance()->current_scene_->update(delta_time);
    }
    game_manager::getInstance()->draw_screen();
    //entity_controller::getInstance()->update(delta_time);
    //entity_controller::getInstance()->draw();
}

void game_manager::game_end() {
    // そしてここでもsingletonのインスタンスを使用します
    if (game_manager::getInstance()->current_scene_) {
        game_manager::getInstance()->current_scene_->on_destroy();
    }
}
