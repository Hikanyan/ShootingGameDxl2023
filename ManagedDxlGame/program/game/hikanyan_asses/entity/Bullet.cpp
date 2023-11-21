#include "Bullet.h"


void Bullet::draw()
{
    DrawBoxEx(transform.position, transform.scale.x, transform.scale.y, false);
}

void Bullet::gameStart()
{
}

void Bullet::update(float delta_time)
{
    transform.position.y -= 500 * delta_time;
    if(transform.position.y <100)
    {
        setIsSurvival(false);
    }
}
void Bullet::setPosition(const tnl::Vector3& position)
{
    transform.position = position;
}