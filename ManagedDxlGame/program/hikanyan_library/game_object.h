#pragma once
#include "object.h"
#include "../dxlib_ext/dxlib_ext.h"
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "component/transform.h"
#include "component/box_collider_2d.h"

class component;
class transform;
class box_collider_2d;

class game_object : public object
{
public:
    std::string tag() const
    {
        return tagValue;
    }

    void setTag(const std::string& value)
    {
        tagValue = value;
    }

    // コンポーネントを取得する
    template <typename T>
    T* GetComponent() const
    {
        auto it = components.find(std::type_index(typeid(T)));
        return it != components.end() ? dynamic_cast<T*>(it->second.get()) : nullptr;
    }

    // コンポーネントを追加する
    template <typename T, typename... Args>
    T* AddComponent(Args&&... args)
    {
        std::unique_ptr<component> newComponent(new T(std::forward<Args>(args)...));
        T* componentPtr = dynamic_cast<T*>(newComponent.get());
        components[std::type_index(typeid(T))] = std::move(newComponent);
        return componentPtr;
    }

    // コンポーネントを削除する
    template <typename T>
    void RemoveComponent()
    {
        auto it = components.find(std::type_index(typeid(T)));
        if (it != components.end())
        {
            components.erase(it);
        }
    }

protected:
    std::unordered_map<std::type_index, std::unique_ptr<component>> components; //コンポーネントの辞書
    std::string tagValue;

private:
    transform* transform_ = nullptr;
    box_collider_2d* collider_ = nullptr;

public:
    transform& get_transform()
    {
        return *transform_; // このクラスが 'transform_' メンバを持っていると仮定
    }

    box_collider_2d& get_collider()
    {
        return *collider_; // このクラスが 'collider_' メンバを持っていると仮定
    }
};
