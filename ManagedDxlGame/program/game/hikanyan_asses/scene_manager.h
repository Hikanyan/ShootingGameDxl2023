#pragma once
#include "system/singleton.h"
#include "../hikanyan_library/scene/scene_base.h"
#include "../dxlib_ext/dxlib_ext.h"

class scene_manager : public singleton<scene_manager>
{
private:
    std::unique_ptr<scene_base> current_scene_;

public:
    scene_manager() = default;
    ~scene_manager() = default;

    void set_current_scene(std::unique_ptr<scene_base> scene)
    {
        // 古いシーンのリソースを解放する前に、必要なクリーンアップを行います。
        if (current_scene_) {
            current_scene_->destroy();
        }

        // 新しいシーンに置き換えます。
        current_scene_ = std::move(scene);
    
        // 新しいシーンの初期化処理を行います。
        if (current_scene_) {
            current_scene_->init();
            current_scene_->awake();
        }
    }


    static void game_start();
    static void game_main(float delta_time);
    static void game_end();

private:
    void draw_screen() const;
};
