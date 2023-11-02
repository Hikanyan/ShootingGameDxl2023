#pragma once
#include "system/singleton.h"
#include "../hikanyan_library/scene/scene_base.h"
#include "../dxlib_ext/dxlib_ext.h"

class game_manager : public singleton<game_manager> {
private:
    std::unique_ptr<scene_base> current_scene_;

public:
    game_manager() = default;
    ~game_manager() = default;

    void set_current_scene(std::unique_ptr<scene_base> scene) {
        current_scene_ = std::move(scene);
    }


    static void game_start();
    static void game_main(float delta_time);
    static void game_end();

private:
    void draw_screen() const {
        // 画面にテキストやオブジェクトを描画する処理
        DrawStringEx(50, 50, -1, "ねこ");
        DrawStringEx(DXE_WINDOW_WIDTH / 2 - 80, DXE_WINDOW_HEIGHT * 0.2, -1, "シューティングゲーム");
        
        // 現在のシーンの描画
        if (current_scene_) {
            current_scene_->draw();
        }
    }
};
