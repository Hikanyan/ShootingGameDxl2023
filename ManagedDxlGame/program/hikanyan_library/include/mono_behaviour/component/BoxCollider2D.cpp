#include "BoxCollider2D.h"
#include "../GameObject.h"

bool BoxCollider2D::intersects(const Collider2D* other) const
{
    const tnl::Vector3 own_position = owner_->get_transform().get_position();
    const tnl::Vector3 other_position = other->get_owner()->get_transform().get_position();
    return intersects(*other, own_position, other_position);
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
