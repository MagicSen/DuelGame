#pragma once
#include "cocos2d.h"
#include "ControlLayer.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace ui;
using namespace cocostudio;


const int MOVE_STEP_DISTANCE = 3;
const float MOVE_STEP_FREQUENCE = 0.01f;
typedef enum _game_status{
	GAME_STATUS_READY = 1,
	GAME_STATUS_START,
	GAME_STATUS_OVER
} GameStatus;

class StatusDelegate {
public:
	virtual void onGameStart(void) = 0;
	virtual void onGamePlaying(int player, int damage);
	virtual void onGameEnd(void) = 0;
};

class GameLayer : public Layer, public ControllDelegate {
public:
	GameLayer();
	~GameLayer();
	bool virtual init();
	CREATE_FUNC(GameLayer);

	CC_SYNTHESIZE(StatusDelegate*, delegator, Delegator);

	void onTouch(const std::vector<Touch *>& touches, Event *event);
	void onTouchEnd(const std::vector<Touch *>& touches, Event *event);
	void onTouchUp();
	void onTouchDown();
	void onTouchRight();
	void onTouchLeft();
	void onTouchAttack();
	
	void MoveRight(float dt);
	void MoveLeft(float dt);
	void setPhyWorld(PhysicsWorld* world){this->world = world;}
//	void update(float delta);
	Size visiblesize;
	Point origin;
	Armature *hero;
private:
	bool onContactBegin(const PhysicsContact& contact);
	void gameOver();
	PhysicsWorld *world;
	GameStatus gameStatus;
	SEL_SCHEDULE right_timer;
	SEL_SCHEDULE left_timer;
};