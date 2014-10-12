#include "LoadLayer.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

Scene* LoadLayer::createScene()
{
	std::string _filePath = "publish/FightScene.json";
	cocos2d::Node* _rootNode = SceneReader::getInstance()->createNodeWithSceneFile(_filePath.c_str());
	auto scene = Scene::create();
	//auto layer = LoadLayer::create();
	scene->addChild(_rootNode);
	Vector<Node*> childNode = _rootNode->getChildren();
	log("Hello World!, I have %d's children node.", childNode.size());
//	Node* hero = _rootNode->getChildByTag(10005);
	//std::string _heroPath = "ani/hero/girl.ExportJson";
	//Node* hero = SceneReader::getInstance()->createNodeWithSceneFile(_heroPath.c_str());
	//log("Hero have %d's children node", hero->getChildren().size());
	//cocos2d::Vec2 origin_coordinate = Director::getInstance()->getOpenGLView()->getVisibleOrigin();
	//hero->setPositionX(origin_coordinate.x);
	return scene;
}

void LoadLayer::onEnter()
{
	Layer::onEnter();
	log("onEnter function");
	// create a new thread to load data
	ArmatureDataManager::getInstance()->addArmatureFileInfoAsync("ani/hero/girl.ExportJson", this, schedule_selector(LoadLayer::dataLoaded));
}

void LoadLayer::dataLoaded(float percent)
{
	log("Loading Ready");
	Rect VisibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
	auto scene = Scene::create();	
	Armature* armature = Armature::create("girl");
	armature->getAnimation()->play("attack");
	armature->setPosition(VisibleRect.origin.x + 50, VisibleRect.origin.y);
	scene->addChild(armature);
	Director::getInstance()->replaceScene(scene);
}
