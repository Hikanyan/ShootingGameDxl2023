#include "Player.h"

#include "entity_controller.h"


void Player::gameStart()
{
}

void Player::draw()
{
    DrawBoxEx(transform.position, transform.scale.x, transform.scale.y, false);
    
}

void Player::update(float delta_time)
{
    if (transform.position.x - (transform.scale.x / 2) > 0 && tnl::Input::IsKeyDown(eKeys::KB_A))
    {
        transform.position.x -= _speed;
    }

    if (transform.position.x + (transform.scale.x / 2) < DXE_WINDOW_WIDTH && tnl::Input::IsKeyDown(eKeys::KB_D))
    {
        transform.position.x += _speed;
    }
    if(tnl::Input::IsKeyDown(eKeys::KB_SPACE))
    {
        entity_controller::getInstance()->bulletInstance(transform.position);
    }
}

void Player::OnTriggerEnter2D(Entity* other)
{
    if (other->getTag() == "bullet")
    {
        setIsSurvival(false);
    }
}