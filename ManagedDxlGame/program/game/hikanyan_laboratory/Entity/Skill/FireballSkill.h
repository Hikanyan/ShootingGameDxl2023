#pragma once
#include "SkillBase.h"

class Character;

class FireballSkill : public SkillBase {
public:
    void execute(Character& character) override {
        // キャラクターがファイアボールを発射する動作を定義
    }
};
