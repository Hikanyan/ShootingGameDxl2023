#include "box_collider_2d.h"
#include "../game_object.h"

bool box_collider_2d::intersects(const box_collider_2d* other) const {
    tnl::Vector3 ownPosition = owner_->get_transform().get_position();
    tnl::Vector3 otherPosition = other->get_owner()->get_transform().get_position();
    return intersects(*other, ownPosition, otherPosition);
}


