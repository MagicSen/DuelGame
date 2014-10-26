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
		// Set the event receiver.
		dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		return true;
	}else {
		return false;
	}
}

void ControlLayer::onTouchesBegan(const std::vector<Touch *>& touches, Event *event)
{
	this->delegator->onTouch();
}