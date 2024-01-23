#pragma once

class PlayerStatus {
public:
    int move_speed;
    int jump_power;
    float gravity_volume;
    int health;
    int damage;
    int score;
    int level;
    int exp;
    int max_exp;
    
    // 列挙型の定義
    enum class MovementState {
        OnGround,
        Jumping
    };

    enum class Direction {
        None,
        Up,
        Down,
        Left,
        Right,
    };

    // メンバ変数としての列挙型の使用
    MovementState movement_state;
    Direction direction;
};
