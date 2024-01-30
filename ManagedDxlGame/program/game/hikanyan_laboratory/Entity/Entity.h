#pragma once
#include <string>

#include "../../../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class Entity : public MonoBehaviour
{
private:
    std::string entity_name_;
    bool entity_is_active_;

public:
    Entity( std::string name) : entity_name_(std::move(name)), entity_is_active_(true)
    {
    }

    const std::string& get_name() const override { return entity_name_; }
    void set_name(const std::string& new_name) override { entity_name_ = new_name; }

    [[nodiscard]] bool get_is_active() const { return entity_is_active_; }
    void set_is_active(const bool active) { entity_is_active_ = active; }
};
