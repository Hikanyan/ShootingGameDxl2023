#pragma once

class Character;

class WeaponBase
{
public:
    virtual ~WeaponBase() = default;
    virtual void use(Character& character) = 0;
};
