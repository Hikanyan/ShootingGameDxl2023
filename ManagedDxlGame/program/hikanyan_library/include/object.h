#pragma once
#include <string>

class object
{
public:
    object() : id(instantiate_id()), name_("DefaultName")
    {
    }

    virtual ~object()
    = default;

    object(std::string name) : id(instantiate_id()), name_(std::move(name))
    {
    }

    int get_id() const { return id; }
    //nameをgetterで取得する
    const std::string& get_name() const { return name_; }
    //nameをsetterで設定する
    void set_name(const std::string& name) { this->name_ = name; }

    static object* instantiate(const std::string& name)
    {
        return new object(name);
    }

    static void destroy(const object* obj)
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
    std::string name_;
};
