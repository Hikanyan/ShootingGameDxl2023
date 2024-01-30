#pragma once
#include "Enemy.h"
#include <memory>

#include "EnemyType.h"

class EnemyFactory {
public:
    static std::shared_ptr<Enemy> create_enemy(EnemyType type)
    {
        switch (type) {
        case EnemyType::Slime:
            return std::make_shared<Enemy>("スライム");
        case EnemyType::Dragon:
            return std::make_shared<Enemy>("ドラゴン");
        case EnemyType::Goblin:
            return std::make_shared<Enemy>("ゴブリン");
        case EnemyType::Skeleton:
            return std::make_shared<Enemy>("スケルトン");
        case EnemyType::Zombie:
            return std::make_shared<Enemy>("ゾンビ");
        case EnemyType::Ghost:
            return std::make_shared<Enemy>("ゴースト");
        case EnemyType::Demon:
            return std::make_shared<Enemy>("デーモン");
        case EnemyType::Vampire:
            return std::make_shared<Enemy>("ヴァンパイア");
        case EnemyType::Werewolf:
            return std::make_shared<Enemy>("ウェアウルフ");
        case EnemyType::Golem:
            return std::make_shared<Enemy>("ゴーレム");
        case EnemyType::Orc:
            return std::make_shared<Enemy>("オーク");
        case EnemyType::Troll:
            return std::make_shared<Enemy>("トロール");
        case EnemyType::Ogre:
            return std::make_shared<Enemy>("オーガ");
        case EnemyType::SlimeKing:
            return std::make_shared<Enemy>("スライムキング");
        case EnemyType::DragonKing:
            return std::make_shared<Enemy>("ドラゴンキング");
        case EnemyType::GoblinKing:
            return std::make_shared<Enemy>("ゴブリンキング");
        case EnemyType::SkeletonKing:
            return std::make_shared<Enemy>("スケルトンキング");
        case EnemyType::ZombieKing:
            return std::make_shared<Enemy>("ゾンビキング");
        case EnemyType::GhostKing:
            return std::make_shared<Enemy>("ゴーストキング");
        case EnemyType::DemonKing:
            return std::make_shared<Enemy>("デーモンキング");
        case EnemyType::VampireKing:
            return std::make_shared<Enemy>("ヴァンパイアキング");
        case EnemyType::WerewolfKing:
            return std::make_shared<Enemy>("ウェアウルフキング");
        case EnemyType::GolemKing:
            return std::make_shared<Enemy>("ゴーレムキング");
        default:
            // Unknown やその他の型の場合の処理をここに記述
            // 例: return nullptr; または適切なデフォルト値を返す
            return nullptr;
        }
    }
};

