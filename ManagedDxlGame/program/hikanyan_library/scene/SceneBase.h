#pragma once
#include <memory>
#include <vector>
#include "../../hikanyan_library/include/mono_behaviour/GameObject.h"
#include "CollisionManager.h"
#include "GameObjectManager.h"

class SceneBase
{
protected:
    // シーンの名前
    std::string name_;
    // ゲームオブジェクトを管理するマネージャー
    GameObjectManager game_object_manager_;
    // 衝突管理
    CollisionManager collision_manager_;

public:
    SceneBase() = default;
    virtual ~SceneBase() = default;

    // シーン名を設定する
    void set_name(const std::string& name)
    {
        name_ = name;
    }

    // シーン名を取得する
    const std::string& get_name() const
    {
        return name_;
    }

    // 新しいゲームオブジェクトを作成する
    virtual std::shared_ptr<GameObject> new_game_object(const std::string& name)
    {
        std::shared_ptr<GameObject> game_object = std::make_shared<GameObject>();
        game_object->set_name(name);
        game_object->add_component<Transform>();
        game_object_manager_.add_game_object(game_object);
        return game_object;
    }

    // ゲームオブジェクトを追加する
    virtual void add_game_object(const std::shared_ptr<GameObject>& game_object)
    {
        game_object_manager_.add_game_object(game_object);
        if (const auto collider = game_object->get_component<Collider2D>().lock())
        {
            collision_manager_.add_collider(collider);
        }
    }

    // ゲームオブジェクトを削除する
    virtual void remove_game_object(const std::shared_ptr<GameObject>& game_object)
    {
        game_object_manager_.remove_game_object(game_object);
        if (auto collider = game_object->get_component<Collider2D>().lock()) // 直接ロックして有効性を確認
        {
            collision_manager_.remove_collider(collider);
        }
    }

    // 初期化処理
    virtual void init()
    {
        game_object_manager_.for_each_game_object([](const std::shared_ptr<GameObject>& obj)
        {
            obj->init();
        });
    }

    // 起動処理
    virtual void awake()
    {
        game_object_manager_.for_each_game_object([](const std::shared_ptr<GameObject>& obj)
        {
            obj->awake();
        });
    }

    // 開始処理
    virtual void start()
    {
        game_object_manager_.for_each_game_object([](const std::shared_ptr<GameObject>& obj)
        {
            obj->start();
        });
    }

    // 描画処理
    virtual void draw()
    {
        game_object_manager_.for_each_game_object([](const std::shared_ptr<GameObject>& obj)
        {
            obj->draw();
        });
    }

    // 更新処理
    virtual void update(float delta_time)
    {
        game_object_manager_.for_each_game_object([delta_time](const std::shared_ptr<GameObject>& obj)
        {
            obj->update(delta_time);
        });
        collision_manager_.check_collisions();
    }

    // 定期的な更新処理
    virtual void fixed_update(float fixed_delta_time)
    {
        game_object_manager_.for_each_game_object([fixed_delta_time](const std::shared_ptr<GameObject>& obj)
        {
            obj->fixed_update(fixed_delta_time);
        });
    }

    // 有効化処理
    virtual void on_enable()
    {
        game_object_manager_.for_each_game_object([](const std::shared_ptr<GameObject>& obj)
        {
            obj->on_enable();
        });
    }

    // 無効化処理
    virtual void on_disable()
    {
        game_object_manager_.for_each_game_object([](const std::shared_ptr<GameObject>& obj)
        {
            obj->on_disable();
        });
    }

    // ゲームオブジェクトのインスタンス化
    template <typename... Args>
    std::shared_ptr<GameObject> instantiate(Args&&... args)
    {
        auto obj = Object::instantiate<GameObject>(std::forward<Args>(args)...);
        game_object_manager_.add_game_object(obj);
        return obj;
    }

    // シーンの破棄
    void scene_destroy()
    {
        game_object_manager_.clear_game_objects();
    }

    // 名前に基づいてゲームオブジェクトを検索する
    std::shared_ptr<GameObject> find_game_object_by_name(const std::string& name) const
    {
        return game_object_manager_.find_game_object_by_name(name);
    }

    // タグに基づいてゲームオブジェクトを検索する
    std::vector<std::shared_ptr<GameObject>> find_game_objects_by_tag(const std::string& tag) const
    {
        return game_object_manager_.find_game_objects_by_tag(tag);
    }

    // 条件に基づいてゲームオブジェクトを検索する
    std::vector<std::shared_ptr<GameObject>> find_game_objects_by_condition(
        const std::function<bool(const std::shared_ptr<GameObject>&)>& condition) const
    {
        return game_object_manager_.find_game_objects_by_condition(condition);
    }
};
