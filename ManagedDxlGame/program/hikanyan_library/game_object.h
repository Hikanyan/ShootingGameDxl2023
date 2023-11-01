#pragma once
#include "object.h"
#include "../dxlib_ext/dxlib_ext.h"
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <ranges>
#include <stdexcept>

#include "component/transform.h"
#include "component/box_collider_2d.h"

// 前方宣言（他のコンポーネントがある場合はここに追加）
class component;
class transform;
class box_collider_2d;

class game_object : public object
{
public:
    game_object() = default;
    ~game_object() override = default;

    // タグのgetter/setter
    std::string tag() const
    {
        return tagValue;
    }

    void set_tag(const std::string& value)
    {
        tagValue = value;
    }

    // コンポーネントを取得する
    template <typename T>
    T* get_component() const
    {
        if (const auto it = components.find(std::type_index(typeid(T))); it != components.end())
        {
            return dynamic_cast<T*>(it->second.get());
        }
        return nullptr;
    }

    // コンポーネントを追加する
    template <typename T, typename... Args>
    T* add_component(Args&&... args)
    {
        auto newComponent = std::make_unique<T>(std::forward<Args>(args)...);
        T* componentPtr = newComponent.get();
        components[std::type_index(typeid(T))] = std::move(newComponent);
        // ここでコンポーネントの初期化を行う（もし必要なら）
        return componentPtr;
    }

    // コンポーネントを削除する
    template <typename T>
    void remove_component()
    {
        if (const auto it = components.find(std::type_index(typeid(T)));
            it != components.end())
        {
            components.erase(it);
        }
    }


    // 特定のコンポーネントへのアクセスメソッド
    transform& get_transform() const
    {
        return *get_component_required<transform>("Transform component not found.");
    }

    // 特定のコンポーネントへのアクセスメソッド
    box_collider_2d& get_collider() const
    {
        return *get_component_required<box_collider_2d>("BoxCollider2D component not found.");
    }

private:
    std::unordered_map<std::type_index, std::unique_ptr<component>> components; // コンポーネントの辞書
    std::string tagValue;

    // 必須コンポーネントを取得するヘルパーメソッド
    template <typename T>
    T* get_component_required(const char* error_message) const
    {
        auto* comp = get_component<T>();
        if (!comp) // コンポーネントが見つからなかった場合はエラーを投げる
        {
            throw std::runtime_error(error_message);
        }
        return comp;
    }

public:
    // コンポーネントの初期化
    void init()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->init();
        }
    }

    // シーン開始時に一度だけ呼ばれる
    void awake()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->awake();
        }
    }

    // 最初のフレームの更新前に一度だけ呼ばれる
    void start()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->start();
        }
    }

    // 毎フレーム呼ばれる更新処理
    void update()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->update();
        }
    }

    // 定期的な時間間隔で呼ばれる更新処理
    void fixed_update()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->fixed_update();
        }
    }

    // コンポーネントが有効になった時に呼ばれる
    void on_enable()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->on_enable();
        }
    }

    // コンポーネントが無効になった時に呼ばれる
    void on_disable()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->on_disable();
        }
    }

    // コンポーネントが破棄される直前に呼ばれる
    void on_destroy()
    {
        for (const auto& comp : components | std::views::values)
        {
            comp->on_destroy();
        }
    }
};
