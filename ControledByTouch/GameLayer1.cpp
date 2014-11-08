#pragma once
#include "GameLayer.h"

GameLayer::GameLayer()
{}

GameLayer::~GameLayer()
{}

bool GameLayer::init(){

	if(Layer::init()){
		this->visiblesize = Director::getInstance()->getOpenGLView()->getVisibleSize();
		this->origin = Director::getInstance()->getOpenGLView()->getVisibleOrigin();

		this->hero = Armature::create("girl");
//		this->hero = Armature::create("monster");
		if(hero){
			hero->setPosition(origin.x + visiblesize.width/2, origin.y + visiblesize.height/2);
			addChild(hero);
		}

		return true;
	}else {
		return false;
	}
}
// Add a timer to control weather it is moving or not
void GameLayer::onTouchEnd(const std::vector<Touch *>& touches, Event *event){
	hero->getAnimation()->stop();
}
void GameLayer::onTouch(const std::vector<Touch *>& touches, Event *event){
	const int DIRECTION_INTERVAL = 30;
	if(touches.size() != 0){	
		Touch *first_touch = touches[0];
		Point touch_point = first_touch->getLocation();

		if(touch_point.x > origin.x + DIRECTION_INTERVAL && touch_point.x < origin.x + 2*DIRECTION_INTERVAL && touch_point.y > origin.y + 2*DIRECTION_INTERVAL && touch_point.y < origin.y + 3*DIRECTION_INTERVAL){
		// UP
			this->onTouchUp(touches, event);
		}else if(touch_point.x > origin.x + DIRECTION_INTERVAL && touch_point.x < origin.x + 2*DIRECTION_INTERVAL && touch_point.y > origin.y && touch_point.y < origin.y + DIRECTION_INTERVAL){
		// DOWN
			this->onTouchDown();
		}else if(touch_point.x > origin.x && touch_point.x < origin.x + DIRECTION_INTERVAL && touch_point.y > origin.y + DIRECTION_INTERVAL && touch_point.y < origin.y + 2*DIRECTION_INTERVAL){
		// LEFT
			this->onTouchLeft();
		}else if(touch_point.x > origin.x + 2*DIRECTION_INTERVAL && touch_point.x < origin.x + 3*DIRECTION_INTERVAL && touch_point.y > origin.y + DIRECTION_INTERVAL && touch_point.y < origin.y + 2*DIRECTION_INTERVAL){
		// RIGHT
			this->onTouchRight();
		}else if(touch_point.x > origin.x + 5*DIRECTION_INTERVAL && touch_point.x < origin.x + 10*DIRECTION_INTERVAL && touch_point.y > origin.y && touch_point.y < origin.y + 3*DIRECTION_INTERVAL){
		// ATTACK
			this->onTouchAttack();
		}else{
		}
	}
}
void GameLayer::onTouchUp(const std::vector<Touch *>& touches, Event *event){
	//	hero->getAnimation()->play("attack");
	// hero->getAnimation()->play("smitten");
	//hero->setPosition(hero->getPosition().x,hero->getPosition().y+10);
	SEL_SCHEDULE up_timer = schedule_selector(GameLayer::MoveUp);
	this->schedule(up_timer, 0.01f);
}

void GameLayer::onTouchDown(){
//	hero->getAnimation()->play("death");
	hero->setPosition(hero->getPosition().x,hero->getPosition().y-10);
}

void GameLayer::onTouchRight(){
	// flip
	hero->setRotationY(0);
	hero->getAnimation()->play("run");
	hero->setPosition(hero->getPosition().x+10,hero->getPosition().y);
//	hero->getAnimation()->play("smitten");
}

void GameLayer::onTouchLeft(){
	hero->setRotationY(180);
	hero->getAnimation()->play("run");
	hero->setPosition(hero->getPosition().x-10,hero->getPosition().y);
//	hero->getAnimation()->play("smitten");
}

void GameLayer::onTouchAttack(){
	hero->getAnimation()->play("attack");
}

void GameLayer::MoveUp(float dt){
	hero->setPosition(hero->getPosition().x,hero->getPosition().y+10);
}