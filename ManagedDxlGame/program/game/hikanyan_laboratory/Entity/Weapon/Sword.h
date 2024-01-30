#pragma once
#include "WeaponBase.h"

class Sword : public WeaponBase
{
public:
    void use(Character& character) override
    {
        // 剣を振る動作を定義
    }
};
