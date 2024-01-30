#pragma once
#include <memory>
#include <string>


class GameObjectManager; // GameObjectManagerクラスの前方宣言

class Object
{
public:
    Object() : id_(-1), name_("DefaultName")
    {
    } // デフォルトコンストラクタ
    explicit Object(std::string name) : id_(-1), name_(std::move(name))
    {
    } // 名前指定コンストラクタ

    virtual ~Object() = default; // デストラクタ

    // コピー禁止
    Object(const Object& other) = delete;
    Object& operator=(const Object& other) = delete;

    // ムーブコンストラクタとムーブ代入
    Object(Object&& other) noexcept = default;
    Object& operator=(Object&& other) noexcept = default;

    // IDと名前のゲッター
    [[nodiscard]] virtual int get_id() const { return id_; }
    [[nodiscard]] virtual const std::string& get_name() const { return name_; }

    // 名前のセッター
    virtual void set_name(const std::string& name) { name_ = name; }

    // 新しい object のインスタンスを作成する静的メソッド
    template <typename T, typename... Args>
    static std::shared_ptr<T> instantiate(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    static void destroy(const Object* obj)
    {
        delete obj;
    }

private:
    int id_; // オブジェクトの一意識別子
    std::string name_; // オブジェクトの名前

    // IDのセッター（GameObjectManagerのみがアクセス可能）
    virtual void set_id(const int new_id) { id_ = new_id; }
    friend class GameObjectManager; // GameObjectManagerをフレンドクラスとして指定
};


// 以下はオブジェクトの破棄を安全に行うためのスマートポインタのラッパーです。
//C++のRAII(Resource Acquisition Is Initialization)の原則に従い、リソースの管理を自動化します。
// スマートポインタで良くない...?w

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
