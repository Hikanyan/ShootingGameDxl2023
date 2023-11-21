#pragma once
#include "Behaviour.h"
#include "Debug.h"
#include "GameObject.h"
#include "..\..\scene\SceneManager.h"

class MonoBehaviour : public Behaviour
{
protected:
    MonoBehaviour() = default;

public:
    ~MonoBehaviour() override = default;

    // イベントメソッド
    void init() override
    {
    }

    void awake() override
    {
    }

    void start() override
    {
    }

    void draw() override
    {
    }

    void update(float delta_time) override
    {
    }

    void fixed_update(float fixed_delta_time) override
    {
    }

    void on_enable() override
    {
    }

    void on_disable() override
    {
    }

    // ゲームオブジェクトのインスタンス化
    virtual void instantiate(const std::string& name)
    {
        const auto raw_game_object = std::shared_ptr(instantiate<GameObject>(name));
        SceneManager::getInstance()->get_current_scene()->add_game_object(raw_game_object);
    }

    // オブジェクトの破棄
    virtual void destroy(GameObject* obj)
    {
        if (!obj) return; // null チェック

        // シーンマネージャーから該当する game_object を削除する
        SceneManager::getInstance()->get_current_scene()->remove_game_object(std::shared_ptr<GameObject>(obj));
        // game_object が shared_ptr によって管理されているため、
        // shared_ptr がスコープを外れると自動的に破棄されます。
    }
    

    // ログメソッド（必要に応じて修正または削除）
    static void log(const std::string& message)
    {
        Debug::log(message);
    }

    static void log_warning(const std::string& message)
    {
        Debug::log_warning(message);
    }

    static void log_error(const std::string& message)
    {
        Debug::log_error(message);
    }
};
