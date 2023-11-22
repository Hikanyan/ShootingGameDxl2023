#pragma once
#include "component/Component.h"

// Behaviour は有効または無効にできるコンポーネントです。
class Behaviour : public Component
{
public:
    ~Behaviour() override = default;
    
};
