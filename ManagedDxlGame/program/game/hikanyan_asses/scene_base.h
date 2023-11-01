﻿#pragma once
#include <memory>
#include <vector>

#include "../../hikanyan_library/game_object.h"

class scene_base
{
protected:
    std::vector<std::shared_ptr<game_object>> game_objects_;
public:
    scene_base() = default;
    virtual ~scene_base() = default;

    virtual void add_game_object(const std::shared_ptr<game_object>& gameObject)
    {
        game_objects_.push_back(gameObject);
    }

    virtual void update(float delta_time)
    {
        for (auto& gameObject : game_objects_)
        {
            gameObject->update(delta_time);
        }
    }

    virtual void draw()
    {
        for (auto& gameObject : game_objects_)
        {
            gameObject->draw();
        }
    }

    virtual void start()
    {
        for (auto& gameObject : game_objects_)
        {
            gameObject->gameStart();
        }
    }
    virtual void Awake()
    {
        for (auto& gameObject : game_objects_)
        {
            gameObject->Awake();
        }
    }

    virtual std::shared_ptr<game_object> FindGameObjectByName(const std::string& name) const {
        for (const auto& game_object_ : game_objects_) {
            if (game_object_->get_name() == name) {
                return game_object_;
            }
        }
        return nullptr;
    }
};
