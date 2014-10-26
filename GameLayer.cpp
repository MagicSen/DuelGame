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
		if(hero){
			hero->setPosition(origin.x + visiblesize.width/2, origin.y + visiblesize.height/2);
			addChild(hero);
		}

		return true;
	}else {
		return false;
	}
}


void GameLayer::onTouch(){
	//	hero->getAnimation()->play("attack");
	//	hero->getAnimation()->play("smitten");
		hero->getAnimation()->play("run");
	//	hero->getAnimation()->play("death");
}