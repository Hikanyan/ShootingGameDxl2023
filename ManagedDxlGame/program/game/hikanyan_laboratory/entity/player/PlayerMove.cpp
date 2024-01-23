#include "PlayerMove.h"

void PlayerMove::start()
{
    // プレイヤーのステータスを取得
    
}


void PlayerMove::Left()
{
    // プレイヤーを左に移動させる処理
    owner_->get_transform().set_position(
        owner_->get_transform().get_position()
        + tnl::Vector3(-player_status_->move_speed, 0, 0));
}

void PlayerMove::Right()
{
    // プレイヤーを右に移動させる処理
    owner_->get_transform().set_position(
        owner_->get_transform().get_position()
        + tnl::Vector3(player_status_->move_speed, 0, 0));
}

void PlayerMove::Up()
{
    // プレイヤーを上に移動させる処理
    owner_->get_transform().set_position(
        owner_->get_transform().get_position()
        + tnl::Vector3(0, -player_status_->move_speed, 0));
}

void PlayerMove::Down()
{
    // プレイヤーを下に移動させる処理
    owner_->get_transform().set_position(
        owner_->get_transform().get_position()
        + tnl::Vector3(0, player_status_->move_speed, 0));
}

void PlayerMove::Jump()
{
    // ジャンプの処理
    if (player_status_->movement_state == PlayerStatus::MovementState::OnGround)
    {
        owner_->add_component<Rigidbody2D>()->velocity.y = -8.0f;
        isOnGround = false;
    }
}
