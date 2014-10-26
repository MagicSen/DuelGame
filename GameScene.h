#pragma once

#include "cocos2d.h"
#include "GameLayer.h"
#include "ControlLayer.h"
#include "BackgroundLayer.h"

using namespace cocos2d;

class GameScene : public Scene {
public:
	GameScene();
	~GameScene();
	bool virtual init();
	void restart();
	CREATE_FUNC(GameScene);
};