﻿#include "TitleScene.h"
#include "../hikanyan_library/include/mono_behaviour/component/Text.h"
#include "../UserInterface/InputManager.h"

void TitleScene::init()
{
    // 新しいGameObjectインスタンスを作成し、初期設定を行う
    title_text_ui_object_ = new_game_object("title_text_ui_object");
    title_text_ui_object_->get_transform().set_position(
        tnl::Vector3(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT * 0.2, 0));
    title_text_ui_object_->add_component<Text>();
    title_text_ui_object_->get_component<Text>()->set_alignment(Text::TextAlignment::Center);
    title_text_ui_object_->get_component<Text>()->set_text("タイトルシーンシーンシーンシーンシーンシーンシーンシーンシーンシーンシーンシーンシーンシーンシーンシーン");
    input_enter_object_ = new_game_object("input_enter_object");
    input_enter_object_->add_component<InputManager>();
    Debug::log(std::to_string(title_text_ui_object_->get_id()));
    Debug::log(std::to_string(input_enter_object_->get_id()));

    SceneBase::init();
}

void TitleScene::awake()
{
    SceneBase::awake();
}

void TitleScene::start()
{
    SceneBase::start();
}

void TitleScene::update(const float delta_time)
{
    SceneBase::update(delta_time);
}

void TitleScene::fixed_update(const float delta_time)
{
    SceneBase::fixed_update(delta_time);
}

void TitleScene::draw()
{
    SceneBase::draw();
}

void TitleScene::on_enable()
{
    SceneBase::on_enable();
}

void TitleScene::on_disable()
{
    SceneBase::on_disable();
}
