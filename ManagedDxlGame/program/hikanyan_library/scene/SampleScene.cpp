#include "SampleScene.h"

#include "../tests/Test.h"

SampleScene::SampleScene()
{
	// GameObjectを追加し、初期設定を行う
	obj_ = std::make_shared<GameObject>();
	SceneBase::add_game_object(obj_);
	obj_->set_name("obj");
	obj_->add_component<Transform>();
	obj_->get_transform().set_position(tnl::Vector3(100, 100, 0));
	obj_->get_transform().set_scale(tnl::Vector3(100, 100, 0));
	obj_->add_component<Test>();
}
void SampleScene::init()
{
	SceneBase::init();
}

void SampleScene::awake()
{
	SceneBase::awake();
}

void SampleScene::start()
{
	SceneBase::start();
}

void SampleScene::update(float delta_time)
{
	SceneBase::update(delta_time);
}

void SampleScene::fixed_update(float delta_time)
{
	SceneBase::fixed_update(delta_time);
}

void SampleScene::draw()
{
	SceneBase::draw();
}

void SampleScene::on_enable()
{
	SceneBase::on_enable();
	Debug::log("update{}", obj_->get_name());
}

void SampleScene::on_disable()
{
	SceneBase::on_disable();
	Debug::log("update{}", obj_->get_name());
}
