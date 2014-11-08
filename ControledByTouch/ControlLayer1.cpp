#include "ControlLayer.h"

ControlLayer::ControlLayer()
{}

ControlLayer::~ControlLayer()
{}

bool ControlLayer::init()
{
	if(Layer::init()){
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto listener = EventListenerTouchAllAtOnce::create();
		listener->onTouchesBegan = CC_CALLBACK_2(ControlLayer::onTouchesBegan, this);
		listener->onTouchesEnded = CC_CALLBACK_2(ControlLayer::onTouchesEnded, this);
		// Set the event receiver.
		dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		return true;
	}else {
		return false;
	}
}

void ControlLayer::onTouchesBegan(const std::vector<Touch *>& touches, Event *event)
{
	this->delegator->onTouch(touches, event);
}

void ControlLayer::onTouchesEnded(const std::vector<Touch *>& touches, Event *event)
{
	this->delegator->onTouchEnd(touches, event);
}