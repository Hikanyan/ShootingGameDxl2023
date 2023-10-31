#pragma once
#include <string>

class object
{
public:
    object() : id(instantiate_id()), name("DefaultName")
    {
    }

    virtual ~object()
    = default;

    explicit object(std::string name) : id(instantiate_id()), name(std::move(name))
    {
    }

    int get_id() const { return id; }
    const std::string& get_name() const { return name; }

    static object* instantiate(const std::string& name)
    {
        return new object(name);
    }

    static void destroy(object* obj)
    {
        delete obj;
    }

protected:
    static int instantiate_id()
    {
        static int nextID = 1;
        return nextID++;
    }

    int id;
    std::string name;
};
