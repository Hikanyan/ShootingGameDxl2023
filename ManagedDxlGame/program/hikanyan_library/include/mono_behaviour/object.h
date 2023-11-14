#pragma once
#include <memory>
#include <string>

class object
{
public:
    object() : id_(instantiate_id()), name_("DefaultName")
    {
    }

    explicit object(std::string name) : id_(instantiate_id()), name_(std::move(name))
    {
    }

    //objectは通常、参照によって管理されます。
    //一つのオブジェクトが複数の場所から参照されることがありますが、その実体は一つだけです。
    //他のオブジェクトとの関連を持つ可能性があるため、オブジェクトの意図せずなコピーを防ぐために重要です。

    virtual ~object() = default; //デストラクタ
    object(const object& other) = delete; // コピー禁止
    object& operator=(const object& other) = delete; // コピー代入禁止
    object(object&& other) noexcept = default; // ムーブコンストラクタ
    object& operator=(object&& other) noexcept = default; // ムーブ代入

    int get_id() const { return id_; }
    void set_id(int id) { id_ = id; }

    const std::string& get_name() const { return name_; }
    void set_name(const std::string& name) { name_ = name; }

    static int instantiate_id()
    {
        static int nextID = 0;
        return ++nextID; // IDは1から始まる
    }

    // 新しい object のインスタンスを作成する静的メソッド
    template <typename T, typename... Args>
    static std::shared_ptr<T> instantiate(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    static void destroy(const object* obj)
    {
        delete obj;
    }

private:
    int id_;
    std::string name_;
};

// 以下はオブジェクトの破棄を安全に行うためのスマートポインタのラッパーです。
//C++のRAII(Resource Acquisition Is Initialization)の原則に従い、リソースの管理を自動化します。
template <typename T>
class object_ptr
{
public:
    explicit object_ptr(T* obj = nullptr) : ptr_(obj)
    {
    }

    // コピー構築子と代入演算子を禁止
    object_ptr(const object_ptr& other) = delete;
    object_ptr& operator=(const object_ptr& other) = delete;

    // ムーブ構築子
    object_ptr(object_ptr&& other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    // ムーブ代入演算子
    object_ptr& operator=(object_ptr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    ~object_ptr()
    {
        delete ptr_;
    }

    T* operator->() { return ptr_; }
    const T* operator->() const { return ptr_; }

    T* get() { return ptr_; }
    const T* get() const { return ptr_; }

private:
    T* ptr_;
};
