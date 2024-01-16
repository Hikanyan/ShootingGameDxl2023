#pragma once
#include "IPlayerController.h"
#include "../Health.h"
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class Collider2D;

class Player : public MonoBehaviour, public IPlayerController
{
public:
    Health health;
    BoxCollider2D collider;
    Rigidbody2D rigidbody;

    // 他のプレイヤー関連の属性とメソッド

    void OnTrrigerEnter2D(Collider2D* other) override
    {
        
    };
};
