#pragma once
#include "Component.h"
#include "../dxlib_ext/dxlib_ext.h"
/*
 Rigidbody2Dはオブジェクトの物理的なプロパティを管理します。
 これには、質量、抵抗、重力の影響を受けるかどうかなどが含まれます。
 Rigidbody2Dを持つオブジェクトは、物理エンジンによって動きが制御され、力や衝突に反応します。
*/
enum BodyType
{
    Static,
    Dynamic,
    Kinematic
};

class Rigidbody2D : public Component
{
public:
    BodyType body_type = Dynamic; // 剛体の種類

    bool simulated = true; // ランタイムに、Rigidbody 2D とそれにアタッチされたすべての Collider 2D と Joint 2D を物理的シミュレーションと相互作用させます
    tnl::Vector3 velocity = {0, 0, 0}; // オブジェクトの速度
    bool use_auto_mass = true; // 質量を自動で計算するかどうか
    float mass = 1.0f; // 質量
    bool use_gravity = true; // 重力の影響を受けるかどうか
    float gravity_scale = 1.0f; // 重力の影響の大きさ

    bool freeze_position_x = false; // x軸方向の移動を固定するかどうか
    bool freeze_position_y = false; // y軸方向の移動を固定するかどうか
    bool freeze_position_z = false; // z軸方向の移動を固定するかどうか
    bool freeze_rotation_x = false; // 回転を固定するかどうか
    bool freeze_rotation_y = false; // 回転を固定するかどうか
    bool freeze_rotation_z = false; // 回転を固定するかどうか


    // 物理的な更新処理
    void update_physics(const float delta_time);
};
