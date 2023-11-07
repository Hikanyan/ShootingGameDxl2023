#include "box_collider_2d.h"
#include "../game_object.h"

bool box_collider_2d::intersects(const box_collider_2d* other) const {
    const tnl::Vector3 own_position = owner_->get_transform().get_position();
    const tnl::Vector3 other_position = other->get_owner()->get_transform().get_position();
    return intersects(*other, own_position, other_position);
}


