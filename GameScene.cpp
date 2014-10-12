#include "GameScene.h"

GameScene::GameScene()
{}

GameScene::~GameScene()
{}

bool GameScene::init()
{
	if(Scene::initWithPhysics()){
		this->getPhysicsWorld()->setGravity(Vect::ZERO);

		auto backgroundLayer = BackgroundLayer::create();
	}
}