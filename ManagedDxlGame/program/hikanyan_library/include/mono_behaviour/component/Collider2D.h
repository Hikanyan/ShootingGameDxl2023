#pragma once
#include "Component.h"
#include "tnl_vector3.h"

enum colliderType
{
    None,
    Box,
    Circle,
    PolygonCollider,
    Edge,
    Capsule,
    Composite,
    Custom
};

class Collider2D : public Component
{
protected:
    GameObject* owner_ = nullptr; // コンポーネントを所持しているゲームオブジェクト

public:
    // コライダーが有効かどうか
    bool enabled;

    // コライダーのタイプ
    colliderType type;

    // コライダーの位置
    tnl::Vector3 position{0, 0, 0}; // 位置
    tnl::Vector3 size{1, 1, 1}; // コライダーのサイズ
    tnl::Vector3 offset{0, 0, 0}; // 中心からのオフセット

    // コンストラクタ
    Collider2D() : enabled(true), type(None)
    {
    }

    // 当たり判定処理（抽象メソッド）
    virtual bool intersects(const Collider2D& other) const = 0;

    // 衝突時のイベント処理
    virtual void OnTriggerEnter2D(Collider2D* other)
    {
    }

    virtual void OnCollisionEnter2D(Collider2D* other)
    {
    }

    // 形状特有の属性とメソッド（派生クラスで定義）
};
