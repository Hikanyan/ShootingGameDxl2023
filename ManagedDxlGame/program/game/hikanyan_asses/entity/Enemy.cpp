#include "Enemy.h"


void Enemy::gameStart()
{
};

void Enemy::update(float delta_time)
{
    transform.position.y += 500 * delta_time;
    if (transform.position.y > DXE_WINDOW_HEIGHT * 0.2)
    {
        setIsSurvival(false);
    }
};

void Enemy::draw()
{
    DrawBoxEx(transform.position, transform.scale.x, transform.scale.y, false);
};


void Enemy::setPosition(const tnl::Vector3& position)
{
    transform.position = position;
}
