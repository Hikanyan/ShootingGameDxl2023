#pragma once
#include "component/component.h"

// behaviour は有効または無効にできるコンポーネントです。
class behaviour : public component
{
private:
    bool enabled_ = true; // このコンポーネントが現在有効かどうかを示すフラグ

public:
    ~behaviour() override = default;

    // コンポーネントが有効かどうかを返します。
    [[nodiscard]] bool enabled() const { return enabled_; }

    // コンポーネントの有効/無効状態を設定します。
    void set_enabled(const bool enabled) { enabled_ = enabled; }
};
