#include "Rigidbody2D.h"

void Rigidbody2D::update_physics(const float delta_time)
{
    switch (body_type)
    {
    case Dynamic:
        // 力や重力の影響を受ける
        if (use_gravity)
        {
            velocity.y += 9.8f * gravity_scale * delta_time;
        }
        // 他の物理的更新...
        break;

    case Static:
        // 何もしない
        break;

    case Kinematic:
        // 自身の動きに基づいて更新（力や衝突の影響は受けない）
        // 例: transformの更新や、特定のパターンでの移動など
        break;
    }
}
