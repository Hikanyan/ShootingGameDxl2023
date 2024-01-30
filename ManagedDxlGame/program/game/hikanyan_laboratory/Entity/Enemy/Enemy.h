#pragma once
#include <string>
#include "../Character.h"


class Enemy : public Character
{
public:
    Enemy(std::string name) : Character(std::move(name))
    {
        // Enemy 固有の初期化処理
    }

    ~Enemy() override = default;

    // Enemy特有の行動や能力を定義
    void perform_enemy_action()
    {
        // 敵の行動を定義
    }

    // その他のEnemy特有の機能をここに追加
};
