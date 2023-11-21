#pragma once
#include "Entity.h"
#include "../hikanyan_library/include/system/Singleton.h"
#include "..\..\..\hikanyan_library\include\system\MyList.h"

class entity_controller : public Singleton<entity_controller>
{
private:
    void initialize();
    int num_enemies = 10;
public:
    void gameStart();
    void draw();
    void update(float delta_time);
    void bulletInstance(tnl::Vector3 position);
    void enemyInstance(tnl::Vector3 position);
    MyList<Entity*> entityList;
};
