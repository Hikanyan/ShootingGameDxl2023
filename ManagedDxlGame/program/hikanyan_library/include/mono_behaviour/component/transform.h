#pragma once
#include "component.h"
#include "../dxlib_ext/dxlib_ext.h"

class transform : public component
{
public:
    tnl::Vector3 position{0, 0, 0};
    tnl::Vector3 rotation{0, 0, 0};
    tnl::Vector3 scale{1, 1, 1};

    transform()
    {
    }

    tnl::Vector3 get_position() const
    {
        return position;
    }

    void set_position(const tnl::Vector3& value)
    {
        position = value;
    }

    tnl::Vector3 get_rotation() const
    {
        return rotation;
    }

    void set_rotation(const tnl::Vector3& value)
    {
        rotation = value;
    }

    tnl::Vector3 get_scale() const
    {
        return scale;
    }

    void set_scale(const tnl::Vector3& value)
    {
        scale = value;
    }
};
