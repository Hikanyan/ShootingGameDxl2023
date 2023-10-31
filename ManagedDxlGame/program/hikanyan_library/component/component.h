#pragma once
#include "../object.h"
class game_object; // GameObjectの前方宣言。

class component : public object
{
protected:
    game_object* owner; // このコンポーネントを所有するGameObjectへのポインタ。

public:
    component() : owner(nullptr)
    {
    }

    ~component() override
    = default;

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

    // 毎フレーム呼ばれます。
    virtual void update()
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

    // コンポーネントが破棄される直前に呼ばれます。
    virtual void on_destroy()
    {
    }

    // このコンポーネントを所有するGameObjectへの参照を設定します。
    virtual void set_owner(game_object* gameObject)
    {
        owner = gameObject;
    }

    // このコンポーネントを所有するGameObjectへの参照を取得します。
    [[nodiscard]] virtual game_object* get_owner() const
    {
        return owner;
    }
};
