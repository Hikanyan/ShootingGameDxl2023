#pragma once
#include <vector>
#include <memory>
#include "Entity.h"
#include "Status.h"
#include "Weapon/WeaponBase.h"
#include "Skill/SkillBase.h"

class Character : public Entity
{
private:
    WeaponBase* weapon_; // 現在装備している武器
    Status status_; // キャラクターのステータス
    std::vector<std::shared_ptr<SkillBase>> skills_; // スキルのリスト

public:
    Character(std::string name)
        : Entity(std::move(name)), weapon_(nullptr)
    {
        // Character の初期化処理
    }

    void move()
    {
        // 移動処理
    }

    void receive_damage(const int damage)
    {
        // ダメージを受ける処理
        status_.set_hp(status_.get_hp() - damage);
    }

    void attack()
    {
        // 攻撃処理
        if (weapon_)
        {
            weapon_->use(*this);
        }
    }

    void equip_weapon(WeaponBase* weapon)
    {
        weapon_ = weapon;
    }

    void use_weapon()
    {
        if (weapon_)
        {
            weapon_->use(*this);
        }
    }

    void use_skill(const std::shared_ptr<SkillBase>& skill)
    {
        if (skill)
        {
            skill->execute(*this);
        }
    }

    [[nodiscard]] const Status& get_status() const
    {
        return status_;
    }

    void add_skill(const std::shared_ptr<SkillBase>& skill)
    {
        skills_.push_back(skill);
    }
};
