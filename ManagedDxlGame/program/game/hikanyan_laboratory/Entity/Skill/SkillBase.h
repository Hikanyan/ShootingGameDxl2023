#pragma once

class Character; // Character クラスの前方宣言

class SkillBase {
public:
    virtual ~SkillBase() = default; // バーチャルデストラクタ

    // 純粋仮想関数として `execute` メソッドを定義
    virtual void execute(Character& character) = 0;
};
