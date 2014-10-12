#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer()
{}

BackgroundLayer::~BackgroundLayer()
{}

bool BackgroundLayer::init()
{
	if(Layer::init()){
		return false;
	}
	Size visiableSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Sprite *background;
	// Set the texture to the background.
	background->setAnchorPoint(Point::ZERO);
	background->setPosition(Point::ZERO);
	this->addChild(background);
	
	return true;
}