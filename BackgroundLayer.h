#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class BackgroundLayer : public Layer{
public:
	BackgroundLayer();
	~BackgroundLayer();
	virtual bool init();
	CREATE_FUNC(BackgroundLayer);
};