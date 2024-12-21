#include "BoxCollider2D.h"
#include "../GameObject.h"

bool BoxCollider2D::intersects(const Collider2D* other) const
{
    const auto own_transform_weak = owner_->get_transform();
    if (const auto own_transform = own_transform_weak.lock())
    {
        // 相手の Transform を取得
        const auto other_transform_weak = other->get_owner()->get_transform();
        if (const auto other_transform = other_transform_weak.lock())
        {
            const tnl::Vector3 own_position = own_transform->get_position();
            const tnl::Vector3 other_position = other_transform->get_position();

            // 位置情報を基に衝突判定
            return intersects(*other, own_position, other_position);
        }
    }
}

bool BoxCollider2D::intersects(const Collider2D& other, const tnl::Vector3& position,
                               const tnl::Vector3& otherPosition) const
{
    const tnl::Vector3 half_size = size / 2;
    const tnl::Vector3 other_half_size = other.size / 2;

    if (position.x + half_size.x + offset.x < otherPosition.x - other_half_size.x + other.offset.x) return false;
    if (position.x - half_size.x + offset.x > otherPosition.x + other_half_size.x + other.offset.x) return false;
    if (position.y + half_size.y + offset.y < otherPosition.y - other_half_size.y + other.offset.y) return false;
    if (position.y - half_size.y + offset.y > otherPosition.y + other_half_size.y + other.offset.y) return false;
    if (position.z + half_size.z + offset.z < otherPosition.z - other_half_size.z + other.offset.z) return false;
    if (position.z - half_size.z + offset.z > otherPosition.z + other_half_size.z + other.offset.z) return false;

    return true;
}
