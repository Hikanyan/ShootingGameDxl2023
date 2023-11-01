#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "component.h"

class game_object;

class box_collider_2d : public component
{
private:
    game_object* owner_ = nullptr; // コンポーネントを所持しているゲームオブジェクト
public:
    tnl::Vector3 size{1, 1, 1}; // コライダーのサイズ
    tnl::Vector3 offset{0, 0, 0}; // 中心からのオフセット

    bool intersects(const box_collider_2d* other) const;

    bool intersects(const box_collider_2d& other, const tnl::Vector3& position, const tnl::Vector3& otherPosition) const
    {
        tnl::Vector3 half_size = size / 2;
        tnl::Vector3 other_half_size = other.size / 2;

        if (position.x + half_size.x + offset.x < otherPosition.x - other_half_size.x + other.offset.x) return false;
        if (position.x - half_size.x + offset.x > otherPosition.x + other_half_size.x + other.offset.x) return false;
        if (position.y + half_size.y + offset.y < otherPosition.y - other_half_size.y + other.offset.y) return false;
        if (position.y - half_size.y + offset.y > otherPosition.y + other_half_size.y + other.offset.y) return false;
        if (position.z + half_size.z + offset.z < otherPosition.z - other_half_size.z + other.offset.z) return false;
        if (position.z - half_size.z + offset.z > otherPosition.z + other_half_size.z + other.offset.z) return false;

        return true;
    }

    virtual void OnTriggerEnter2D(box_collider_2d* other)
    {
    };

    virtual void OnCollisionEnter2D(box_collider_2d* other)
    {
    };


    game_object* get_owner() const
    {
        return owner_;
    }

    void set_owner(game_object* owning_object)
    {
        owner_ = owning_object;
    }
};
