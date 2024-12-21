#pragma once
#include "Component.h"
#include "../dxlib_ext/dxlib_ext.h"

class Transform : public Component
{
private:
    tnl::Vector3 position_{0, 0, 0};
    tnl::Vector3 rotation_{0, 0, 0};
    tnl::Vector3 scale_{1, 1, 1};

public:
    // デフォルトコンストラクタ
    Transform() = default;

    // コンストラクタ（初期値を設定）
    Transform(const tnl::Vector3& position, const tnl::Vector3& rotation = {0, 0, 0}, const tnl::Vector3& scale = {1, 1, 1})
        : position_(position), rotation_(rotation), scale_(scale) {}

    // コピーコンストラクタと代入演算子
    Transform(const Transform&) = default;
    Transform& operator=(const Transform&) = default;

    // 移動コンストラクタと代入演算子
    Transform(Transform&&) noexcept = default;
    Transform& operator=(Transform&&) noexcept = default;

    // position プロパティ
    const tnl::Vector3& get_position() const { return position_; }
    void set_position(const tnl::Vector3& value) { position_ = value; }

    // rotation プロパティ
    const tnl::Vector3& get_rotation() const { return rotation_; }
    void set_rotation(const tnl::Vector3& value) { rotation_ = value; }

    // scale プロパティ
    const tnl::Vector3& get_scale() const { return scale_; }
    void set_scale(const tnl::Vector3& value) { scale_ = value; }

    // トランスフォーム全体を設定する
    void set_transform(const tnl::Vector3& position, const tnl::Vector3& rotation, const tnl::Vector3& scale)
    {
        position_ = position;
        rotation_ = rotation;
        scale_ = scale;
    }

    // トランスフォーム全体を取得する
    std::tuple<tnl::Vector3, tnl::Vector3, tnl::Vector3> get_transform() const
    {
        return {position_, rotation_, scale_};
    }

    // 移動メソッド
    void translate(const tnl::Vector3& delta)
    {
        position_ += delta;
    }

    // 回転メソッド
    void rotate(const tnl::Vector3& delta)
    {
        rotation_ += delta;
    }

    // スケール変更メソッド
    void scale(const tnl::Vector3& factor)
    {
        scale_ *= factor;
    }
};
