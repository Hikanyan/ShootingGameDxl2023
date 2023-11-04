#pragma once
#include "scene_base.h"

class sample_scene final : public scene_base
{
public:
    sample_scene() = default;
    virtual ~sample_scene() override = default;

    // シーン固有の初期化
    void init() override;
    void awake() override;
    void start() override;
    void update(float delta_time) override;
    void fixed_update(float delta_time) override;
    void draw() override;
    void on_enable() override;
    void on_disable() override;
    void instantiate() override;
    void destroy() override;

private:
    //オブジェクトをコンストラクタで生成する

    //落ちることがあるので、スマートポインタを使う
    std::shared_ptr<game_object> obj_ = std::make_shared<game_object>(); //動的にメモリを確保
};
