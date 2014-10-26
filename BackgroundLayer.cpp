#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer()
{}

BackgroundLayer::~BackgroundLayer()
{}

bool BackgroundLayer::init()
{
	if(!Layer::init()){
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Sprite *background = Sprite::create("img/bg1.png");
	// Set the texture to the background.
	background->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2));
	
	float scaleX = visibleSize.width / background->getContentSize().width;
    float scaleY = visibleSize.height / background->getContentSize().height;

	background->setScaleX(scaleX);
	background->setScaleY(scaleY);

	this->addChild(background);
	
	return true;
}