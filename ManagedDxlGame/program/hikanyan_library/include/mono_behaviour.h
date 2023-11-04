#pragma once
#include "behaviour.h"
#include "debug.h"
#include "game_object.h"
#include "../game/hikanyan_asses/scene_manager.h"

/*単一行動するオブジェクトクラス
 *MonoBehaviour は、すべての ひかにゃん スクリプトの派生元となる基本クラスです。
 *オブジェクトにアタッチされたスクリプトは、そのオブジェクトの機能を制御します。
 *TODO Task,Invoke,Coroutineの実装
*/
class mono_behaviour : public behaviour
{
protected:
    // 保護されたコンストラクタを使用して直接インスタンス化を防ぐ
    mono_behaviour() = default;

public:
    virtual ~mono_behaviour() = default;


    // イベントメソッド

    // 初期化処理を行います。
    virtual void init(){}
    // シーン開始時に呼ばれます。
    virtual void awake(){}
    // シーン開始時に呼ばれます。
    virtual void start(){}
    // 描画処理を行います。
    virtual void draw(){}
    // 毎フレーム呼ばれます。
    virtual void update(float delta_time){}
    // 一定秒数ごとに呼ばれます。
    virtual void fixed_update(float fixed_delta_time){}
    // コンポーネントが有効になった時に呼ばれます。
    virtual void on_enable(){}
    // コンポーネントが無効になった時に呼ばれます。
    virtual void on_disable(){}
    // ゲームオブジェクトをインスタンス化する関数
    virtual void instantiate(const std::string& name)//objectのinstantiateを呼び出す
    {
        auto new_game_object = object::instantiate(name); // 新しいgame_objectインスタンスを作成
         scene_manager::getInstance()->current_scene_->add_game_object(new_game_object); // シーンに追加
    }
    // オブジェクトを破棄した時に呼ばれます。
    virtual void destroy()//objectのdestroyを呼び出す
    {
        // このオブジェクトを削除
        current_scene->remove_game_object(shared_from_this()); // shared_from_this()は、thisをstd::shared_ptrとして取得する
        object::destroy(this); // objectの破棄処理を呼び出す
    }

    // ログメソッド
    static void log(const std::string& message)
    {
        debug::log(message);
    }
    static void log_warning(const std::string& message)
    {
        debug::log_warning(message);
    }
    static void log_error(const std::string& message)
    {
        debug::log_error(message);
    }
};
