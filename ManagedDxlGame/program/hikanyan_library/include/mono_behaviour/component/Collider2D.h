#pragma once
#include "Component.h"

enum colliderType
{
    None,
    Box,
    Circle,
    Polygon,
    Edge,
    Capsule,
    Composite,
    Custom
};

class Collider2D : public Component {
public:
    // コライダーが有効かどうか
    bool enabled;

    // コライダーのタイプ
    colliderType type;

    // コンストラクタ
    Collider2D() : enabled(true), type(None) {}

    // 当たり判定処理（抽象メソッド）
    virtual bool Intersects(const Collider2D& other) const = 0;

    // コライダーの更新処理（必要に応じて）
    virtual void Update() {}

    // その他、各コライダータイプ特有のメソッドやプロパティ
};
