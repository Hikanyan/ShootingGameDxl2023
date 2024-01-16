#include "PlayerController.h"
void PlayerController::update(const float delta_time)
{
    // フレーム間の時間差

    // 入力を確認
    check_input();

    // プレイヤーの状態を更新
    update_player_state(delta_time);

    // 必要に応じてアクションを実行
    execute_actions(delta_time);
}

void PlayerController::check_input()
{
    // キーボードやマウスの入力をチェック
}

void PlayerController::update_player_state(float delta_time)
{
    // プレイヤーの状態を更新
}

void PlayerController::execute_actions(float delta_time)
{
    // アクション（移動、ジャンプ、攻撃など）を実行
}
