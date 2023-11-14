﻿#include "sample_scene.h"

#include "../tests/test.h"


void sample_scene::init()
{
    add_game_object(obj_); //オブジェクトを追加
    obj_->set_name("obj"); //名前を設定
    obj_->add_component<transform>(); //コンポーネントを追加
    obj_->get_transform().set_position(tnl::Vector3(100, 100, 0));
    obj_->add_component<test>();
    debug::log("init{}", obj_->get_name());
}

void sample_scene::awake()
{
    debug::log("awake{}", obj_->get_name());
}

void sample_scene::start()
{
    debug::log("start{}", obj_->get_name());
}

void sample_scene::update(float delta_time)
{
    debug::log("update{}", obj_->get_name());
}

void sample_scene::fixed_update(float delta_time)
{
    debug::log("update{}", obj_->get_name());
}

void sample_scene::draw()
{
    debug::log("update{}", obj_->get_name());
}

void sample_scene::on_enable()
{
    debug::log("update{}", obj_->get_name());
}

void sample_scene::on_disable()
{
    debug::log("update{}", obj_->get_name());
}
