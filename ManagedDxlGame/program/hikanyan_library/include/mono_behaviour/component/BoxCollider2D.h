#pragma once
#include "Collider2D.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "Component.h"

class GameObject;
/*
これは特定のオブジェクトに関連付けられた四角形の当たり判定領域を表します。
BoxCollider2Dは、物体が他の物体とどのように衝突するかを定義します。
サイズや位置などのプロパティを持つことができます。
*/
class BoxCollider2D final : public Collider2D
{
public:
    bool intersects(const Collider2D* other) const;
    bool intersects(const Collider2D& other, const tnl::Vector3& position, const tnl::Vector3& otherPosition) const;

    virtual void OnTriggerEnter2D(BoxCollider2D* other)
    {
    };

    virtual void OnCollisionEnter2D(BoxCollider2D* other)
    {
    };
};
