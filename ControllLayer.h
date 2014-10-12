#pragma once
#include "cocos2d.h"
#include "vector"

using namespace cocos2d;

class ControllDelegate{
public:
	virtual void onTouch() = 0;
};

class ControllLayer : public Layer{
public:
	ControllLayer();
	~ControllLayer();

	virtual bool init();
	CREATE_FUNC(ControllLayer);

	// override 
	void onTouchesBegan(const std::vector<Touch *>& touches, Event *event);
	// Set the delegator.
	CC_SYNTHESIZE(ControllDelegate*, delegator, Delegator);
};
