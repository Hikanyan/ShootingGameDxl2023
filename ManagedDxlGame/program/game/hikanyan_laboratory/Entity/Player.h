#pragma once
#include "Character.h"

class Player : public Character
{
public:
    // IDと名前を受け取るコンストラクタ
    Player(std::string name) : Character(std::move(name))
    {
        // プレイヤー固有の初期化処理
    }

    ~Player() override = default;

    // プレイヤー特有のメソッド
    void performAction()
    {
        // プレイヤーのアクションを実行する処理
    }

    // その他のプレイヤー特有の機能をここに追加
};
