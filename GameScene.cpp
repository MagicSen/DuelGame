#include "GameScene.h"

GameScene::GameScene()
{}

GameScene::~GameScene()
{}

bool GameScene::init()
{
	if(!Scene::init())
		return false;

	if(Scene::initWithPhysics()){
		this->getPhysicsWorld()->setGravity(Vect::ZERO);

		auto backgroundLayer = BackgroundLayer::create();
		if(backgroundLayer){
			this->addChild(backgroundLayer);
		}


		auto gameLayer = GameLayer::create();

		if(gameLayer){
			gameLayer->setPhyWorld(this->getPhysicsWorld());
			this->addChild(gameLayer);
		}

		auto controlLayer = ControlLayer::create();
		if(controlLayer){
			controlLayer->setDelegator(gameLayer);
			this->addChild(controlLayer);
		}
		return true;
	} else {
		return false;
	}
}