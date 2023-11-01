#pragma once
#include "component/component.h"
class component;
class behaviour:public component
{
public:
    virtual ~behaviour() = default;
    bool enabled();

};
