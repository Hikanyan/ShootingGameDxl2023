#pragma once
#include "component/component.h"

//behaviourは有効または無効にできるコンポーネントです。
class behaviour : public component
{
private:
    bool enabled_ = true;

public:
    virtual ~behaviour() = default;

    // enabled() 関数がコンポーネントの状態を返します。
    [[nodiscard]] bool enabled() const { return enabled_; }

    // コンポーネントの状態を設定する関数（例：setEnabled）を追加できます。
    void set_enabled(const bool enabled) { enabled_ = enabled; }
};
