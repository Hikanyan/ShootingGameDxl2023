#pragma once

class Health
{
public:
    int current_health;
    int max_health;

    Health(int max_health) : current_health(max_health), max_health(max_health)
    {
    }

    void take_damage(int amount)
    {
        current_health -= amount;
        if (current_health < 0)
        {
            current_health = 0;
            // プレイヤーの死亡ロジック
        }
    }

    void heal(int amount)
    {
        current_health += amount;
        if (current_health > max_health)
        {
            current_health = max_health;
        }
    }

    bool is_alive() const
    {
        return current_health > 0;
    }
};
