#include "PlayerController.h"
#include "PlayerStatus.h"


void PlayerController::check_input()
{
    // キーボードやマウスの入力をチェック WASDキーで移動、スペースキーでジャンプ
    if (tnl::Input::IsKeyDown(eKeys::KB_W))
    {
        player_status_->direction = PlayerStatus::Direction::Up;
    }
    if (tnl::Input::IsKeyDown(eKeys::KB_A) && canMove())
    {
        player_status_->direction = PlayerStatus::Direction::Left;
    }
    if (tnl::Input::IsKeyDown(eKeys::KB_S))
    {
        player_status_->direction = PlayerStatus::Direction::Down;
    }
    if (tnl::Input::IsKeyDown(eKeys::KB_D) && canMove())
    {
        player_status_->direction = PlayerStatus::Direction::Right;
    }
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) && canMove())
    {
        player_status_->movement_state = PlayerStatus::MovementState::Jumping;
    }
    else
    {
        player_status_->movement_state = PlayerStatus::MovementState::OnGround;
    }
}

void PlayerController::update_player_state(float delta_time)
{
    // プレイヤーの速度や方向などの基本的な状態を更新
    // 例: 重力の影響を考慮して、プレイヤーの垂直速度を更新
    if (player_status_->movement_state != PlayerStatus::MovementState::OnGround)
    {
        // ジャンプ中や落下中の場合、重力を適用
        player_velocity.y += gravity * delta_time;
    }

    // プレイヤーの位置を更新
    owner_->get_transform().get_position().x += owner_->add_component<Rigidbody2D>()->velocity.x * delta_time;
    owner_->get_transform().get_position().y += player_velocity.y * delta_time;

    // その他の状態更新処理...
}

void PlayerController::execute_actions(float delta_time)
{
    // 移動、ジャンプ、攻撃などのアクションを実行
    switch (player_status_->direction)
    {
    case PlayerStatus::Direction::Left:
        // 左に移動
        moveLeft();
        break;
    case PlayerStatus::Direction::Right:
        // 右に移動
        moveRight();
        break;
    // その他の方向に応じたアクション...
    }

    if (player_status_->movement_state == PlayerStatus::MovementState::Jumping)
    {
        // ジャンプ処理
        jump();
    }

    // その他のアクション処理...
}


bool PlayerController::canMove()
{
    if (PlayerStatus::Direction::Left == player_status_->direction)
    {
        return (owner_->get_transform().get_position().x -
            (owner_->get_transform().get_scale().x / 2) > 0);
    }
    if (PlayerStatus::Direction::Right == player_status_->direction)
    {
        return (owner_->get_transform().get_position().x +
            (owner_->get_transform().get_scale().x / 2) < DXE_WINDOW_WIDTH);
    }
    if (PlayerStatus::Direction::Up == player_status_->direction)
    {
        return (owner_->get_transform().get_position().y -
            (owner_->get_transform().get_scale().y / 2) > 0);
    }
    if (PlayerStatus::Direction::Down == player_status_->direction)
    {
        return (owner_->get_transform().get_position().y +
            (owner_->get_transform().get_scale().y / 2) < DXE_WINDOW_HEIGHT);
    }
    if (PlayerStatus::MovementState::OnGround == player_status_->movement_state)
    {
        return true;
    }
}
