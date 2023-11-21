#pragma once
#include "component/Component.h"
#include <coroutine>
#include <future>

enum class EventType;
class Coroutine;

// Behaviour は有効または無効にできるコンポーネントです。
class Behaviour : public Component
{
public:
    ~Behaviour() override = default;

    // 特定のライフサイクルイベントのための仮想メソッド
    virtual void on_collision_enter()
    {
    }

    virtual void on_mouse_over()
    {
    }

    // コルーチンのサポート
    virtual Coroutine start_coroutine(...);

    // イベントハンドラの追加
    virtual void handle_event(EventType event);
};

class Coroutine
{
public:
    struct promise_type
    {
        Coroutine get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }

        void unhandled_exception()
        {
        }

        void return_void()
        {
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;
};

enum class EventType
{
    CollisionEnter,
    MouseOver,
};
