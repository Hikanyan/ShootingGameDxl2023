#pragma once
#include <memory>
#include <vector>
#include "../../hikanyan_library/game_object.h"

class scene_base {
protected:
    std::vector<std::shared_ptr<game_object>> game_objects_;

public:
    scene_base() = default;
    virtual ~scene_base() = default;

    virtual void add_game_object(const std::shared_ptr<game_object>& gameObject) {
        game_objects_.push_back(gameObject);
    }

    virtual void update(float delta_time) {
        for (auto& game_object_ : game_objects_) {
            if (game_object_) {  // nullptrでないことを確認
                game_object_->update(delta_time);
            }
        }
    }

    virtual void draw() {
        for (auto& game_object_ : game_objects_) {
            if (game_object_) {
                game_object_->draw();
            }
        }
    }

    virtual void start() {
        for (auto& game_object_ : game_objects_) {
            if (game_object_) {
                game_object_->start();
            }
        }
    }

    virtual void awake() {
        for (auto& game_object_ : game_objects_) {
            if (game_object_) {
                game_object_->awake();
            }
        }
    }

    
    virtual std::shared_ptr<game_object> find_game_object_by_name(const std::string& name) const {
        for (const auto& game_object_ : game_objects_) {
            if (game_object_ && game_object_->get_name() == name) {  // getName を使用する
                return game_object_;
            }
        }
        return nullptr;
    }
};
