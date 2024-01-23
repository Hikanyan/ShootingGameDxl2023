#pragma once
#include "IPlayerController.h"
#include "../Health.h"
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class Player : public MonoBehaviour, public IPlayerController
{
public:
    Health health;
    Rigidbody2D* rigid_body; // Rigidbody2Dへのポインタを使用

    // 他のプレイヤー関連の属性とメソッド
    void start() override
    {
        rigid_body = owner_->get_component<Rigidbody2D>();
    }

    void OnTriggerEnter2D(Collider2D* other) // メソッド名を修正
    {
        // otherのlogを出力
        Debug::log(other->get_name());
    };
};
