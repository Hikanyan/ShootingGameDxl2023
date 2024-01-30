#pragma once
#include "../include/mono_behaviour/GameObject.h"
#include <memory>
#include <list>
#include <functional>
#include <vector>

class GameObjectManager
{
private:
    // ゲームオブジェクトのリスト
    std::list<std::shared_ptr<GameObject>> game_objects_;
    int next_id_ = 0; // 次に割り当てるID
    int generate_next_id()
    {
        return next_id_++; // 次のIDを生成し、次回のためにインクリメント
    }

public:
    // ゲームオブジェクトを追加する
    void add_game_object(const std::shared_ptr<GameObject>& game_object)
    {
        game_object->set_id(generate_next_id());
        game_objects_.push_back(game_object);
    }

    // ゲームオブジェクトを削除する
    void remove_game_object(const std::shared_ptr<GameObject>& game_object)
    {
        game_objects_.remove(game_object);
    }

    // ゲームオブジェクトを名前で検索する
    [[nodiscard]] std::shared_ptr<GameObject> find_game_object_by_name(const std::string& name) const
    {
        const auto it = std::ranges::find_if(game_objects_,
                                             [&name](const std::shared_ptr<GameObject>& obj)
                                             {
                                                 return obj->get_name() == name;
                                             });
        return (it != game_objects_.end()) ? *it : nullptr;
    }

    //  ゲームオブジェクトをタグで検索する
    [[nodiscard]] std::vector<std::shared_ptr<GameObject>> find_game_objects_by_tag(const std::string& tag) const
    {
        std::vector<std::shared_ptr<GameObject>> foundObjects;
        for (const auto& game_object : game_objects_)
        {
            if (game_object->get_tag() == tag)
            {
                foundObjects.push_back(game_object);
            }
        }
        return foundObjects;
    }

    // ゲームオブジェクトを条件で検索する
    [[nodiscard]] std::vector<std::shared_ptr<GameObject>> find_game_objects_by_condition(
        const std::function<bool(const std::shared_ptr<GameObject>&)>& condition) const
    {
        std::vector<std::shared_ptr<GameObject>> foundObjects;
        for (const auto& game_object : game_objects_)
        {
            if (condition(game_object))
            {
                foundObjects.push_back(game_object);
            }
        }
        return foundObjects;
    }

    // ゲームオブジェクトを全て取得する
    [[nodiscard]] std::vector<std::shared_ptr<GameObject>> get_game_objects() const
    {
        std::vector<std::shared_ptr<GameObject>> foundObjects;
        for (const auto& game_object : game_objects_)
        {
            foundObjects.push_back(game_object);
        }
        return foundObjects;
    }

    // すべてのゲームオブジェクトに対して指定されたアクションを実行する
    void for_each_game_object(const std::function<void(std::shared_ptr<GameObject>)>& action) const
    {
        for (auto& gameObject : game_objects_)
        {
            action(gameObject);
        }
    }

    // ゲームオブジェクトのリストをクリアする
    void clear_game_objects()
    {
        game_objects_.clear();
    }
};
