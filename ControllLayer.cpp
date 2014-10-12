#include "ControllLayer.h"

ControllLayer::ControllLayer()
{}

ControllLayer::~ControllLayer()
{}

bool ControllLayer::init()
{
	if(Layer::init()){
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto listener = EventListenerTouchAllAtOnce::create();
		listener->onTouchesBegan = CC_CALLBACK_2(ControllLayer::onTouchesBegan, this);
		// Set the event receiver.
		dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		return true;
	}else {
		return false;
	}
}

void ControllLayer::onTouchesBegan(const std::vector<Touch *>& touches, Event *event)
{
	this->delegator->onTouch();
}