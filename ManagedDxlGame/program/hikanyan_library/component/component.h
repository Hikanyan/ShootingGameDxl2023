#pragma once
#include "../object.h"
class GameObject; // GameObjectの前方宣言。

class component : public object
{
protected:
    GameObject* owner; // このコンポーネントを所有するGameObjectへのポインタ。

public:
    component() : owner(nullptr)
    {
    }

    virtual ~component()
    {
    }

    // シーン開始時に呼ばれます。
    virtual void Awake()
    {
    }

    // シーン開始時に呼ばれます。
    virtual void Start()
    {
    }

    // 毎フレーム呼ばれます。
    virtual void Update()
    {
    }

    // コンポーネントが有効になった時に呼ばれます。
    virtual void OnEnable()
    {
    }

    // コンポーネントが無効になった時に呼ばれます。
    virtual void OnDisable()
    {
    }

    // コンポーネントが破棄される直前に呼ばれます。
    virtual void OnDestroy()
    {
    }

    // このコンポーネントを所有するGameObjectへの参照を設定します。
    void SetOwner(GameObject* gameObject)
    {
        owner = gameObject;
    }

    // このコンポーネントを所有するGameObjectへの参照を取得します。
    GameObject* GetOwner() const
    {
        return owner;
    }
};
