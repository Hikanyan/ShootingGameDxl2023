#pragma once
#include "../hikanyan_library/include/mono_behaviour/MonoBehaviour.h"

class Entity : MonoBehaviour
{
public:
    int id; // エンティティの一意のID
    std::string tag; // エンティティのカテゴリーを示すタグ
    bool is_active; // エンティティがアクティブかどうか
    int version; // ID再利用時のバージョン管理用

    
};
