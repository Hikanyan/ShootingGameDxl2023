#pragma once
#include "WeaponBase.h"

class Gun : public WeaponBase
{
public:
    void use(Character& character) override
    {
        // 銃を発射する動作を定義
    }
};
