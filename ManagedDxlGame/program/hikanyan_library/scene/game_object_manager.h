#pragma once
#include <memory>
#include <vector>
#include "../include/game_object.h"

class game_object_manager
{
private:
    std::vector<std::unique_ptr<game_object>> objects_;

    // 共通の関数ポインタ型を定義します。
    using game_object_function = void (game_object::*)();

    // 共通処理を実行するテンプレート関数
    void for_each_game_object(game_object_function function) const
    {
        for (auto& obj : objects_) {
            (obj.get()->*function)(); // 関数ポインタをデリファレンスしてオブジェクトに対して呼び出します。
        }
    }
public:


    
    void init() { for_each_game_object(&game_object::init); }
    void awake() { for_each_game_object(&game_object::awake); }
    void start() { for_each_game_object(&game_object::start); }
    void update(float deltaTime) const
    {
        for (auto& obj : objects_) {
            obj->update(deltaTime);
        }
    }
    void fixed_update(float deltaTime) const
    {
        for (auto& obj : objects_) {
            obj->update(deltaTime);
        }
    }
    void draw() { for_each_game_object(&game_object::draw); }
    void on_enable() { for_each_game_object(&game_object::on_enable); }
    void on_disable() { for_each_game_object(&game_object::on_disable); }
    void on_destroy() {
        for_each_game_object(&game_object::destroy);
        objects_.clear();
    }

    template <typename T, typename... Args>
    T* instantiate(Args&&... args) {
        T* obj = new T(std::forward<Args>(args)...);
        objects_.emplace_back(obj);
        return obj;
    }
};
