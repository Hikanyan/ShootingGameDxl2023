#pragma once
#include "../Object.h"

class GameObject;

class Component : public Object
{
protected:
    GameObject* owner_; // このコンポーネントを所有するGameObjectへのポインタ。
    bool is_enabled_; // コンポーネントの有効/無効状態を示すフラグ。
public:
    Component() : owner_(nullptr), is_enabled_(true)
    {
    }

    ~Component() override = default;

    [[nodiscard]] virtual bool is_enabled() const { return is_enabled_; }
    virtual void set_enabled(const bool enabled) { is_enabled_ = enabled; }

    // このコンポーネントを所有するGameObjectへの参照を設定します。
    virtual void set_owner(GameObject* game_object) { owner_ = game_object; }

    // このコンポーネントを所有するGameObjectへの参照を取得します。
    [[nodiscard]] virtual GameObject* get_owner() const { return owner_; }

    // 初期化処理を行います。
    virtual void init()
    {
    }

    // シーン開始時に呼ばれます。
    virtual void awake()
    {
    }

    // シーン開始時に呼ばれます。
    virtual void start()
    {
    }

    // 描画処理を行います。
    virtual void draw()
    {
    }

    // 毎フレーム呼ばれます。
    virtual void update(float delta_time)
    {
    }

    // 一定秒数ごとに呼ばれます。
    virtual void fixed_update(float fixed_delta_time)
    {
    }

    // コンポーネントが有効になった時に呼ばれます。
    virtual void on_enable()
    {
    }

    // コンポーネントが無効になった時に呼ばれます。
    virtual void on_disable()
    {
    }
};
