#pragma once
#include <list>
#include "../hikanyan_library/include/system/singleton.h"
#include "../hikanyan_library/include/system/list.h"
#include "../hikanyan_library/scene/scene_base.h"

// シーンを管理するクラス
class scene_manager : public singleton<scene_manager>
{
private:
    // 全てのシーンのリスト
    std::list<std::shared_ptr<scene_base>> all_scenes_;
    std::shared_ptr<scene_base> current_scene_;
    std::shared_ptr<scene_base> next_scene_;


public:
    scene_manager() = default;
    ~scene_manager() = default;

    // 現在のシーンを取得する関数
    [[nodiscard]] const std::shared_ptr<scene_base>& get_current_scene() const { return current_scene_; }
    void set_current_scene(std::shared_ptr<scene_base> scene);

    static void create_scene()
    {
        // シーンを作成します。
    }


    void un_load_scene() const;


    static void game_start();
    static void game_main(float delta_time);
    static void game_end();

private:
    void draw_screen() const;
};
