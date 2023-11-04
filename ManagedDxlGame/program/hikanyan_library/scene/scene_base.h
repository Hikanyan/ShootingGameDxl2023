#pragma once
#include <memory>
#include <vector>
#include "../../hikanyan_library/include/game_object.h"

class scene_base
{
protected:
    std::list<std::shared_ptr<game_object>> game_objects_;
    // 任意の処理をゲームオブジェクトに対して行う関数
    void for_each_game_object(const std::function<void(std::shared_ptr<game_object>)>& action) const //関数の引数に関数を渡す
    {
        for (auto& game_object_ : game_objects_)
        {
            if (game_object_)
            {
                action(game_object_);
            }
        }
    }

public:
    scene_base() = default;
    virtual ~scene_base() = default;

    // ゲームオブジェクトを追加する関数
    virtual void add_game_object(const std::shared_ptr<game_object>& game_object)
    {
        game_objects_.push_back(game_object);
    }

    // ゲームオブジェクトを削除する関数
    virtual void remove_game_object(const std::shared_ptr<game_object>& game_object)
    {
        game_objects_.remove(game_object);
    }


    virtual void init()
    {
        for_each_game_object([](const std::shared_ptr<game_object>& obj)
        {
            obj->init();
        });
    }

    virtual void awake()
    {
        for_each_game_object([](const std::shared_ptr<game_object>& obj)
        {
            obj->awake();
        });
    }

    virtual void start()
    {
        for_each_game_object([](const std::shared_ptr<game_object>& obj)
        {
            obj->start();
        });
    }

    virtual void draw()
    {
        for_each_game_object([](const std::shared_ptr<game_object>& obj)
        {
            obj->draw();
        });
    }

    virtual void update(float delta_time)
    {
        for_each_game_object([delta_time](const std::shared_ptr<game_object>& obj)
        {
            obj->update(delta_time);
        });
    }

    virtual void fixed_update(float fixed_delta_time)
    {
        for_each_game_object([fixed_delta_time](const std::shared_ptr<game_object>& obj)
        {
            obj->fixed_update(fixed_delta_time);
        });
    }

    virtual void on_enable()
    {
        for_each_game_object([](const std::shared_ptr<game_object>& obj)
        {
            obj->on_enable();
        });
    }

    virtual void on_disable()
    {
        for_each_game_object([](const std::shared_ptr<game_object>& obj)
        {
            obj->on_disable();
        });
    }

    // // ゲームオブジェクトをインスタンス化する関数
    // virtual void instantiate(const std::string& name)
    // {
    //     // 新しいgame_objectインスタンスを作成
    //     const auto raw_game_object = object::instantiate(name); // ここで返される object* を取得します。
    //     const auto new_game_object = std::make_shared<game_object>(raw_game_object);
    //     // 新しいインスタンスをリストに追加
    //     add_game_object(new_game_object);
    // }

    // ゲームオブジェクトを破棄する関数
    virtual void scene_destroy()
    {
        for_each_game_object([this](const std::shared_ptr<game_object>& obj)
        {
            object::destroy(obj.get());
            game_objects_.remove(obj);
        });
    }

    // ゲームオブジェクトを名前で検索する関数
    virtual std::shared_ptr<game_object> find_game_object_by_name(const std::string& name) const
    {
        for (const auto& game_object_ : game_objects_)
        {
            if (game_object_ && game_object_->get_name() == name)
            {
                // getName を使用する
                return game_object_;
            }
        }
        return nullptr;
    }

    // 任意の条件を満たすゲームオブジェクトを見つける関数
    std::vector<std::shared_ptr<game_object>> find_game_objects_by_condition(
        const std::function<bool(const std::shared_ptr<game_object>&)>& condition) const
    {
        std::vector<std::shared_ptr<game_object>> found_objects;
        for (const auto& game_object_ : game_objects_)
        {
            if (game_object_ && condition(game_object_))
            {
                found_objects.push_back(game_object_);
            }
        }
        return found_objects;
    }
};
