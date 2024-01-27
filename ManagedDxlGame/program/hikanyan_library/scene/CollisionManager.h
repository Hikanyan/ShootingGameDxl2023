#pragma once
#include <vector>
#include <memory>
#include "../hikanyan_library/include/mono_behaviour/component/Collider2D.h"

class CollisionManager
{
private:
    std::vector<std::shared_ptr<Collider2D>> colliders_;

public:
    void addCollider(const std::shared_ptr<Collider2D>& collider)
    {
        colliders_.push_back(collider);
    }

    void removeCollider(const std::shared_ptr<Collider2D>& collider)
    {
        colliders_.erase(std::remove(colliders_.begin(), colliders_.end(), collider), colliders_.end());
    }

    void checkCollisions()
    {
        for (size_t i = 0; i < colliders_.size(); ++i)
        {
            for (size_t j = i + 1; j < colliders_.size(); ++j)
            {
                if (colliders_[i]->intersects(*colliders_[j]))
                {
                    // 衝突が検出された場合の処理
                    colliders_[i]->OnTriggerEnter2D(colliders_[j].get());
                    colliders_[j]->OnTriggerEnter2D(colliders_[i].get());

                    //この間に跳ね返るなどの物理的処理を与える

                    colliders_[i]->OnCollisionEnter2D(colliders_[j].get());
                    colliders_[j]->OnCollisionEnter2D(colliders_[i].get());
                }
            }
        }
    }
};
