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
//		this->hero = Armature::create("running_main");
//		this->hero->getAnimation()->play("running");
//		this->hero = Armature::create("monster");
		if(hero){
			hero->setPosition(origin.x + visiblesize.width/2, origin.y + visiblesize.height/2);
			addChild(hero);
		}

		this->right_timer = schedule_selector(GameLayer::MoveRight);
		this->left_timer = schedule_selector(GameLayer::MoveLeft);
		return true;
	}else {
		return false;
	}
}
// Add a timer to control weather it is moving or not
void GameLayer::onTouchEnd(const std::vector<Touch *>& touches, Event *event){
	if(isScheduled(right_timer)){
		this->unschedule(right_timer);
		hero->getAnimation()->pause();
	}
	if(isScheduled(left_timer)){
		this->unschedule(left_timer);
		hero->getAnimation()->stop();
	}
}
void GameLayer::onTouch(const std::vector<Touch *>& touches, Event *event){
	const int DIRECTION_INTERVAL = 30;
	if(touches.size() != 0){	
		Touch *first_touch = touches[0];
		Point touch_point = first_touch->getLocation();

		if(touch_point.x > origin.x + DIRECTION_INTERVAL && touch_point.x < origin.x + 2*DIRECTION_INTERVAL && touch_point.y > origin.y + 2*DIRECTION_INTERVAL && touch_point.y < origin.y + 3*DIRECTION_INTERVAL){
		// UP
			this->onTouchUp();
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
void GameLayer::onTouchUp(){
	//	hero->getAnimation()->play("attack");
	hero->getAnimation()->play("smitten");
	//hero->setPosition(hero->getPosition().x,hero->getPosition().y+10);
}

void GameLayer::onTouchDown(){
	hero->getAnimation()->play("death");
//	hero->setPosition(hero->getPosition().x,hero->getPosition().y-10);
}

void GameLayer::onTouchRight(){
	// flip
	hero->setRotationY(0);
	hero->getAnimation()->play("run");
	if(!isScheduled(right_timer)){
		this->schedule(right_timer, MOVE_STEP_FREQUENCE);
	}
}

void GameLayer::onTouchLeft(){
	hero->setRotationY(180);
	hero->getAnimation()->play("run");
//	hero->getAnimation()->play("smitten");
	if(!isScheduled(left_timer)){
		this->schedule(left_timer, MOVE_STEP_FREQUENCE);
	}
}

void GameLayer::onTouchAttack(){
	hero->getAnimation()->play("attack");
}

void GameLayer::MoveRight(float dt){
	if(hero->getPosition().x + hero->getContentSize().width/2 < origin.x + visiblesize.width){
		hero->setPosition(hero->getPosition().x+MOVE_STEP_DISTANCE,hero->getPosition().y);
	}
}

void GameLayer::MoveLeft(float dt){
	if(hero->getPosition().x - hero->getContentSize().width/2 > origin.x){
		hero->setPosition(hero->getPosition().x-MOVE_STEP_DISTANCE,hero->getPosition().y);
	}
}