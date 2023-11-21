#include "SceneManager.h"

void SceneManager::create_scene(const std::string& name) {
    std::lock_guard<std::mutex> lock(scene_mutex_);
    scenes_[name] = std::make_shared<SceneBase>();
}

void SceneManager::add_scene(const std::string& name, std::shared_ptr<SceneBase> scene) {
    std::lock_guard<std::mutex> lock(scene_mutex_);
    scenes_[name] = std::move(scene);
}

std::shared_ptr<SceneBase> SceneManager::get_active_scene() const {
    std::lock_guard<std::mutex> lock(scene_mutex_);
    return active_scene_;
}

void SceneManager::load_scene(const std::string& name) {
    std::lock_guard<std::mutex> lock(scene_mutex_);
    if (const auto it = scenes_.find(name); it != scenes_.end()) {
        active_scene_ = it->second;
        active_scene_->init();  // 初期化処理
    }
}

std::future<void> SceneManager::load_scene_async(const std::string& name) {
    return std::async(std::launch::async, [this, name] {
        load_scene(name);
    });
}

bool SceneManager::set_active_scene(const std::string& name) {
    std::lock_guard<std::mutex> lock(scene_mutex_);
    if (const auto it = scenes_.find(name); it != scenes_.end()) {
        active_scene_ = it->second;
        return true;
    }
    return false;
}

std::future<void> SceneManager::unload_scene_async(const std::string& name) {
    return std::async(std::launch::async, [this, name] {
        std::lock_guard<std::mutex> lock(scene_mutex_);
        scenes_.erase(name);
        if (active_scene_ && active_scene_->get_name() == name) {
            active_scene_ = nullptr;
        }
    });
}

void SceneManager::set_current_scene(std::shared_ptr<SceneBase> scene) {
    un_load_scene();
    active_scene_ = std::move(scene);
}

std::shared_ptr<SceneBase> SceneManager::get_current_scene() const
{
    return active_scene_;
}

void SceneManager::un_load_scene() const {
    if (active_scene_) {
        active_scene_->scene_destroy();
    }
}

void SceneManager::game_start() {
    if (SceneManager::getInstance()->active_scene_) {
        SceneManager::getInstance()->active_scene_->init();
        SceneManager::getInstance()->active_scene_->awake();
        SceneManager::getInstance()->active_scene_->start();
    }
}

void SceneManager::game_main(float delta_time) {
    if (SceneManager::getInstance()->active_scene_) {
        SceneManager::getInstance()->active_scene_->update(delta_time);
    }
    draw_screen();
}

void SceneManager::game_end() {
    // ゲーム終了時の処理
}

void SceneManager::draw_screen() const {
    if (active_scene_) {
        active_scene_->draw();
    }
}