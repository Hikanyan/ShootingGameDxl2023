#include "sample_scene.h"

#include "../tests/test.h"


void sample_scene::init()
{
    obj_->set_name("obj"); //名前を設定
    obj_->add_component<test>();
    obj_->init();
}

void sample_scene::awake()
{
    obj_->awake();
}

void sample_scene::start()
{
    obj_->start();
}

void sample_scene::update(float delta_time)
{
    obj_->update(delta_time);
}

void sample_scene::fixed_update(float delta_time)
{
    obj_->fixed_update(delta_time);
}

void sample_scene::draw()
{
    obj_->draw();
}

void sample_scene::on_enable()
{
    obj_->on_enable();
}

void sample_scene::on_disable()
{
    obj_->on_disable();
}
void sample_scene::instantiate()
{
    obj_->instantiate();
}

void sample_scene::destroy()
{
    obj_->destroy();
}
