#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include "SceneBase.h"
#include <future>  // 非同期処理に必要
#include <mutex>   // スレッドセーフな操作に必要

class SceneManager
{
private:
    // シーンの名前とシーンのポインタを格納
    std::unordered_map<std::string, std::shared_ptr<SceneBase>> scenes_;
    // アクティブなシーン
    std::shared_ptr<SceneBase> active_scene_;
    // スレッドセーフな操作用のミューテックス
    mutable std::mutex scene_mutex_;
    //今のシーン
    std::string current_scene_;

public:
    SceneManager() = default;

    // シーンの数を取得
    size_t get_scene_count() const
    {
        std::lock_guard lock(scene_mutex_);
        return scenes_.size();
    }

    // 新しいシーンを作成して追加
    void create_scene(const std::string& name)
    {
        std::lock_guard lock(scene_mutex_);
        scenes_[name] = std::make_shared<SceneBase>();
    }

    // アクティブなシーンを取得
    std::shared_ptr<SceneBase> get_active_scene() const
    {
        std::lock_guard lock(scene_mutex_);
        return active_scene_;
    }

    // シーンをロード（同期）
    void load_scene(const std::string& name)
    {
        std::lock_guard lock(scene_mutex_);
        if (const auto it = scenes_.find(name); it != scenes_.end())
        {
            active_scene_ = it->second;
            active_scene_->init(); // 初期化処理
        }
    }

    // シーンを非同期でロード
    std::future<void> load_scene_async(const std::string& name)
    {
        return std::async(std::launch::async, [this, name]
        {
            load_scene(name);
        });
    }

    // アクティブなシーンを設定
    bool set_active_scene(const std::string& name)
    {
        std::lock_guard lock(scene_mutex_);
        if (const auto it = scenes_.find(name); it != scenes_.end())
        {
            active_scene_ = it->second;
            return true;
        }
        return false;
    }

    // シーンを非同期でアンロード
    std::future<void> unload_scene_async(const std::string& name)
    {
        return std::async(std::launch::async, [this, name]
        {
            std::lock_guard lock(scene_mutex_);
            scenes_.erase(name);
            if (active_scene_ && active_scene_->get_name() == name)
            {
                active_scene_ = nullptr;
            }
        });
    }
};
