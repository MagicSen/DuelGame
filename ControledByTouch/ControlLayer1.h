#pragma once
#include "cocos2d.h"
#include "vector"

using namespace cocos2d;

class ControllDelegate{
public:
	virtual void onTouch(const std::vector<Touch *>& touches, Event *event) = 0;
	virtual void onTouchEnd(const std::vector<Touch *>& touches, Event *event) = 0;
};

class ControlLayer : public Layer{
public:
	ControlLayer();
	~ControlLayer();

	virtual bool init();
	CREATE_FUNC(ControlLayer);

	// override 
	void onTouchesBegan(const std::vector<Touch *>& touches, Event *event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);
	// Set the delegator.
	CC_SYNTHESIZE(ControllDelegate*, delegator, Delegator);
};
