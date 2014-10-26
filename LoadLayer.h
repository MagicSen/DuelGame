#ifndef __MYCPPGAME_LOADLAYER_H_
#define __MYCPPGAME_LOADLAYER_H_

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "GameScene.h"
#include "BackgroundLayer.h"

class LoadLayer : public cocos2d::Layer
{
public:
//	static cocos2d::Scene* createScene();
	virtual void onEnter() override;
	
	void dataLoaded(float percent);
};

#endif // __MYCPPGAME_LOADLAYER_H_
