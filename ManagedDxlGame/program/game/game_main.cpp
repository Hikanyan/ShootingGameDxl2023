#include <time.h>
#include <string>
#include <numbers>
#include <functional>
#include "../dxlib_ext/dxlib_ext.h"
#include "game_main.h"

#include "..\hikanyan_library\scene\SceneManager.h"
#include "../hikanyan_library/scene/SampleScene.h"

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void game_start()
{
    srand(time(0));
    SetBackgroundColor(32, 32, 32);
    scene_manager::getInstance()->set_current_scene(std::make_unique<SampleScene>());
    scene_manager::getInstance()->game_start();
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void game_main(float delta_time)
{
    DrawFpsIndicator({10, DXE_WINDOW_HEIGHT - 10, 0}, delta_time);
    scene_manager::getInstance()->game_main(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void game_end()
{
    scene_manager::getInstance()->game_end();
}
