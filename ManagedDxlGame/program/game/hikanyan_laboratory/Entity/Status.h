#pragma once

class Status
{
private:
    int hp_; //体力
    int attack_; //攻撃力
    int defence_; //防御力
    float cool_time_; //クールタイム
    float range_; //射程距離
    float bullet_speed_; //弾速
    float effect_time_; //効果時間
    int bullet_num_; //弾数
    int penetration_; //貫通力
    float move_speed_; //移動速度
    float growth_speed_; //成長速度
    int luck_; //運

public:
    // コンストラクタ
    Status()
        : hp_(100), attack_(10), defence_(10), cool_time_(1.0f), range_(5.0f),
          bullet_speed_(1.0f), effect_time_(3.0f), bullet_num_(1), penetration_(1),
          move_speed_(1.0f), growth_speed_(1.0f), luck_(1)
    {
    }

    // ゲッターとセッター
    [[nodiscard]] int get_hp() const { return hp_; }
    void set_hp(const int value) { hp_ = value; }

    [[nodiscard]] int get_attack() const { return attack_; }
    void set_attack(const int value) { attack_ = value; }

    [[nodiscard]] int get_defence() const { return defence_; }
    void set_defence(const int value) { defence_ = value; }

    [[nodiscard]] float get_cool_time() const { return cool_time_; }
    void set_cool_time(const float value) { cool_time_ = value; }

    [[nodiscard]] float get_range() const { return range_; }
    void set_range(const float value) { range_ = value; }

    [[nodiscard]] float get_bullet_speed() const { return bullet_speed_; }
    void set_bullet_speed(const float value) { bullet_speed_ = value; }

    [[nodiscard]] float get_effect_time() const { return effect_time_; }
    void set_effect_time(const float value) { effect_time_ = value; }

    [[nodiscard]] int get_bullet_num() const { return bullet_num_; }
    void set_bullet_num(const int value) { bullet_num_ = value; }

    [[nodiscard]] int get_penetration() const { return penetration_; }
    void set_penetration(const int value) { penetration_ = value; }

    [[nodiscard]] float get_move_speed() const { return move_speed_; }
    void set_move_speed(const float value) { move_speed_ = value; }

    [[nodiscard]] float get_growth_speed() const { return growth_speed_; }
    void set_growth_speed(const float value) { growth_speed_ = value; }

    [[nodiscard]] int get_luck() const { return luck_; }
    void set_luck(const int value) { luck_ = value; }
};
